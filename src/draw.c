/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/23 20:42:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw
//ANCHOR - Draw Z
static void	ft_iso(t_point *point)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	x = point->x0;
	y = point->y0;
	x1 = point->x1;
	y1 = point->y1;
	point->x0 = fabs(x *cos(ft_toradian(60))+ y * sin(ft_toradian(60)));
	point->y0 = fabs(-x * sin(ft_toradian(60)) + y * cos(ft_toradian(60)));
	//point->x1 = fabs(x1 * cos(ft_toradian(45)) + y1 * sin(ft_toradian(45)));
	//point->y1 = fabs(-x1 * sin(ft_toradian(45)) + y1 *cos(ft_toradian(45)));
}

//ANCHOR - Draw Net
static void	ft_draw_xy(t_window *window, t_point *point)
{
	int	pixel;
	int	dx;
	int	dy;

	dx = fabs(point->x1 - point->x0);
	dy = fabs(point->y1 - point->y0);
	pixel = (2 * dy) - dx;
	ft_iso(point);
	printf("point0 = (%f, %f)\t point1 = (%f, %f)\n", point->x0, point->y0, point->x1, point->y1);
	while (point->x0 <= point->x1)
	{
		if (point->x0 < point->imagelength && point->y0 < point->imageheight)
			ft_pixelput(window, point->x0, point->y0, point->color0);
		point->x0 += 1;
		if (pixel >= 0)
		{
			pixel += 2 * (dy - dx);
			point->y0 += 1;
		}
		else
			pixel += 2 * dy;
	}
}

//ANCHOR - Draw borders
static void	ft_drawaxis(t_window *window, t_point *point)
{
	int	pixel;
	int	maxlen;
	int	maxwidth;
	
	pixel = 0;
	maxwidth = point->imagelength - point->margin - (point->imagelength * 0.1);
	maxlen = point->imageheight - point->margin - (point->imageheight * 0.1);
	while (pixel < maxlen)
	{
		if (pixel < maxlen)
			ft_pixelput(window, 0, pixel, 0xFF00FF);
		pixel++;
	}
	mlx_string_put(window->mlx, window->win, (point->margin) - 10,
		pixel - 5, 0xFF0000, "y");
	pixel = 0;
	while (pixel < maxwidth)
	{
		ft_pixelput(window, pixel, 0, 0x00FF00);
		pixel++;
	}
	mlx_string_put(window->mlx, window->win, pixel - 5,
		(point->margin) - 20, 0xFF000, "x");
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_point *point)
{
	t_map	*node;
	int		count;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	ft_drawaxis(window, point);
	count = 0;
	node = map;
	while (node != NULL)
	{
		count = 0;
		while (count < node->width)
		{
			ft_markpoint(point, node, count);
			ft_draw_xy(window, point);
			++count;
		}
		node = node->next;
	}
	ft_printheader(window, point);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, point->margin + 5, point->margin + 5);
}
//!SECTION

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/12 20:43:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw
//ANCHOR - Draw Z
/*static void	ft_iso(int *x, int *y, int z)
{
	int	x0;

	x0 = *x;
	*x = (x0 - *y) * cos(0.523);
	*y = -z + (x0 + *y) * sin(0.523);
		if (point->y < point->height)
			point->y = (point->y * point->step) + point->step;
		ft_iso(&point->x, &point->y, x[counter]);
}*/

//ANCHOR - Draw Net
static void	ft_draw_xy(t_window *window, t_point *point)
{
	int	pixel;
	int	dx;
	int	dy;

	dx = abs(point->x1 - point->x0);
	dy = abs(point->y1 - point->y0);
	printf("point0->(%d,%d) \t point1-> (%d,%d)\n",
			point->x0, 
			point->y0, point->x1, point->y1);
	pixel = 2 * dy - dx;
	while (point->y0 < point->y1)
	{
		if (point->y0 < (point->height * point->scale))
			ft_pixelput(window, point->x0, point->y0, point->color0);
		if (pixel >= 0)
		{
			pixel += 2 * (dy - dx);
			point->y0 += 1;
		}
		else
		{
			pixel += 2 * dy;
			point->x0 += 1;
		}
	}
}

//ANCHOR - Draw borders
/*static void	ft_drawborders(t_window *window, int color, int len)
{
	int	pixel;

	pixel = 0;
	while (pixel < len)
	{
		ft_pixelput(window, 0, pixel, color);
		ft_pixelput(window, pixel, 0, color);
		pixel++;
	}
}*/

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_point *point)
{
	t_map	*node;
	int		count;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	node = map;
	//ft_drawborders(window, node->color[0], point->linelength);
	count = 0;
	while (node != NULL)
	{
		count = 0;
		while (count < point->width - 1)
		{
			ft_markpoint(point, node, count);
			ft_draw_xy(window, point);
			++count;
		}
		node = node->next;
	}
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, point->step / 2, point->step / 2);
}
//!SECTION

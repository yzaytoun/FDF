/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/09 20:38:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw
//ANCHOR - Draw Z
static void	ft_iso(int *x, int *y, int z)
{
	int	x;

	x = *x;
	*x = (x - *y) * cos(0.523599);
	*y = -z + (x + *y) * sin(0.523599);
}

//ANCHOR - Draw Net
static void	ft_draw_xy(t_window *window, t_point *point, int *color, int *x)
{
	int	index;
	int	pixel;

	index = 0;
	pixel = 0;
	while (index < point->width)
	{
		pixel = 0;
		if (index < point->width)
			point->x = (index * point->step) + point->step;
		if (point->y < point->height)
			point->y = (point->y * point->step) + point->step;
		while (pixel < point->linelength)
		{
			ft_iso(&point->x, &point->y, x[index]);
			ft_pixelput(window, point->x, pixel, color[index]);
			ft_pixelput(window, pixel, point->y, color[index]);
			pixel++;
		}
		++index;
	}
}

static void	ft_drawborders(t_window *window, t_point *point, int color)
{
	int	pixel;

	pixel = 0;
	while (pixel < point->linelength)
	{
		ft_pixelput(window, point->x, pixel, color);
		ft_pixelput(window, pixel, point->y, color);
		pixel++;
	}
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_point *point)
{
	t_map	*node;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	node = map;
	ft_markpoint(point, 0, 0);
	ft_drawborders(window, point, node->color[0]);
	while (node != NULL)
	{
		ft_markpoint(point, 0, node->y);
		ft_draw_xy(window, point, node->color, node->x);
		node = node->next;
	}
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, point->step / 2, point->step / 2);
}
//!SECTION

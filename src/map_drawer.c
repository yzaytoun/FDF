/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:12:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/08 20:40:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map Drawer
//ANCHOR - Mark point
static void	ft_markpoint(t_point *point, int x0, int y0)
{
	point->x = x0;
	point->y = y0;
	point->linelength = (point->width * point->scale) * 0.90;
	point->step = point->linelength / point->height;
}

//ANCHOR - Pixel Put
static void	ft_pixelput(t_window *window, int dist_x, int dist_y, int color)
{
	char	*dst;

	dst = window->addr
		+ (window->size_line * dist_y + dist_x * (window->bpp / 8));
	*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}

//ANCHOR - Draw_y
static void	ft_draw_y(t_window *window, t_point *point, int color)
{
	int	index;
	int	pixel;
	int	x;

	index = 0;
	pixel = 0;
	x = 1;
	while (pixel < point->linelength)
	{
		ft_pixelput(window, 0, pixel, color);
		pixel++;
	}
	while (index < point->width)
	{
		pixel = 0;
		if (index < point->width)
			x = (index * point->step) + point->step;
		while (pixel < point->linelength)
		{
			ft_pixelput(window, x, pixel, color);
			pixel++;
		}
		++index;
	}
}

//ANCHOR - Draw line 
static void	ft_draw_x(t_window *window, t_point *point, int color)
{
	int	index;
	int	pixel;

	index = 0;
	pixel = 0;
	while (pixel < point->linelength)
	{
		ft_pixelput(window, pixel, 0, color);
		pixel++;
	}
	while (index < point->width)
	{
		pixel = 0;
		if (point->y < point->height)
			point->y = (point->y * point->step) + point->step;
		while (pixel < point->linelength)
		{
			ft_pixelput(window, pixel, point->y, color);
			pixel++;
		}
		++index;
	}
}

//ANCHOR - Draw Map
static void	ft_put_map_to_image(t_window *window, t_map *map, t_point *point)
{
	t_map	*node;
	int		index;

	index = 0;
	node = map;
	while (node != NULL)
	{
		ft_markpoint(point, index, node->y);
		ft_draw_x(window, point, node->color[index]);
		node = node->next;
	}
	node = map;
	while (node != NULL)
	{
		ft_markpoint(point, index, node->y);
		ft_draw_y(window, point, node->color[index]);
		node = node->next;
	}
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_point *point)
{
	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	ft_put_map_to_image(window, map, point);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, point->step/ 2, point->step / 2);
}
//!SECTION

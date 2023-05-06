/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:12:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/06 19:58:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map Drawer
//ANCHOR - Pixel Put
static void	ft_pixelput(t_window *window, int dist_x, int dist_y, int color)
{
	char	*dst;

	dst = window->addr
		+ (window->size_line * dist_y + dist_x * (window->bpp / 8));
	*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}

//ANCHOR - Draw Map
static void	ft_draw_line(t_window *window, t_map *map, t_point *point)
{
	t_map	*node;
	int		index;

	index = 0;
	node = map;
	point->dx = 500;
	point->dy = 500;
	point->step = 2 * point->dy - point->dx;
	while (node->next != NULL)
	{
		point->y = node->y;
		index = 0;
		while (index < point->step)
		{
			printf("points %d, %d\n", index, point->y);
			ft_pixelput(window, index, point->y, node->color[index]);
			index++;
		}
		node = node->next;
	}
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map)
{
	t_point	*point;

	window->img = mlx_new_image(window->mlx, map->size * 100, map->size * 100);
	if (!window->img)
		return ;
	point = ft_calloc(1, sizeof(t_point));
	if (!point)
		return ;
	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	ft_draw_line(window, map, point);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 10, 10);
}
//!SECTION
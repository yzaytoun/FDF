/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/26 20:32:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
//ANCHOR - Mark point
void	ft_markpoint(t_point *point, t_map *map, int count)
{
	if (count == 0)
	{
		point->x0 = 0;
		point->y0 = 0;
	}
	else
	{
		point->x0 = point->x1;
		point->y0 = point->y1;
	}
	point->y1 = (map->y * (point->distance_y / 2));
	point->x1 = (count * (point->distance_x / 2));
	point->z = map->x[count];
	point->color0 = map->color[count];
	point->color1 = map->color[count + 1];
}

//ANCHOR - Pixel Put
void	ft_pixelput(t_window *window, int dist_x, int dist_y, int color)
{
	char	*dst;

	if (dist_x < 0 || dist_y < 0)
		return ;
	dst = window->addr
		+ (window->size_line * dist_y + dist_x * (window->bpp / 8));
	if (dst != NULL)
		*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}
//!SECTION

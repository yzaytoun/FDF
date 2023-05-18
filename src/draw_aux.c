/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/18 20:53:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
//ANCHOR - Mark point
void	ft_markpoint(t_point *point, t_map *map, int count)
{
	if (count == 0)
		point->extend = point->step;
	point->y1 = map->y;
	point->x1 = point->extend;
	point->z = map->x[count];
	point->color0 = map->color[count];
	point->color1 = map->color[count + 1];
}

//ANCHOR - Pixel Put
void	ft_pixelput(t_window *window, int dist_x, int dist_y, int color)
{
	char	*dst;

	dst = window->addr
		+ (window->size_line * dist_y + dist_x * (window->bpp / 8));
	*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}
//!SECTION

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/12 20:53:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
//ANCHOR - Mark point
void	ft_markpoint(t_point *point, t_map *map, int count)
{
	point->x0 = count;
	point->x1 = (count + 1) * point->step;
	point->y0 = map->x[count];
	point->y1 = (map->x[count + 1]) * point->step;
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

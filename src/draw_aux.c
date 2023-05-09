/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/09 20:21:08 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
//ANCHOR - Mark point
void	ft_markpoint(t_point *point, int x0, int y0)
{
	point->x = x0;
	point->y = y0;
	point->linelength = (point->width * point->scale) * 0.90;
	point->step = point->linelength / point->height;
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

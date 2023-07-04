/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:32:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/04 15:03:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Bresenham
//ANCHOR - Get Coordination
void	ft_getcoord(t_fdf *fdf, int x, int y, int point)
{
	if (point == FIRST_POINT)
	{
		fdf->v0.x = x;
		fdf->v0.y = y;
	}
	else if (point == SECOND_POINT)
	{
		fdf->v1.x = x;
		fdf->v1.y = y;
	}
}

//ANCHOR - Mark point
void	ft_markpoint(t_fdf *fdf, t_matrix *matrix)
{
	fdf->v0.x = ft_toint(matrix->vector[matrix->count_y][matrix->count_x].x);
	fdf->v0.y = ft_toint(matrix->vector[matrix->count_y][matrix->count_x].y);
	fdf->v0.color
		= ft_toint(matrix->vector[matrix->count_y][matrix->count_x].color);
	if (fdf->flags.x_axis == 1)
	{
		fdf->v1.x
			= ft_toint(matrix->vector[matrix->count_y][matrix->count_x + 1].x);
		fdf->v1.y
			= ft_toint(matrix->vector[matrix->count_y][matrix->count_x + 1].y);
		fdf->v1.color
			= ft_toint(matrix->vector
			[matrix->count_y][matrix->count_x + 1].color);
	}
	else
	{
		fdf->v1.x
			= ft_toint(matrix->vector[matrix->count_y + 1][matrix->count_x].x);
		fdf->v1.y
			= ft_toint(matrix->vector[matrix->count_y + 1][matrix->count_x].y);
		fdf->v1.color
			= ft_toint(matrix->vector
			[matrix->count_y + 1][matrix->count_x].color);
	}
}

//ANCHOR - Pixel Put
static void	ft_pixelput(t_window *window, int dist_x, int dist_y, int color)
{
	char	*dst;

	if (dist_x < 0 || dist_y < 0)
		return ;
	dst = window->addr
		+ (window->size_line * dist_y + dist_x * (window->bpp / 8));
	if (dst != NULL)
		*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}


static void	ft_bresenaux(t_fdf *fdf)
{
	if (fdf->v0.x < fdf->v1.x)
		fdf->ham.sx = 1;
	else
		fdf->ham.sx = -1;
	if (fdf->v0.y < fdf->v1.y)
		fdf->ham.sy = 1;
	else
		fdf->ham.sy = -1;
	fdf->ham.err = fdf->ham.dx + fdf->ham.dy;
}

//ANCHOR - Draw Net
void	ft_bresenham(t_window *window, t_fdf *fdf)
{
	fdf->ham.dx = abs(fdf->v1.x - fdf->v0.x);
	fdf->ham.dy = -abs(fdf->v1.y - fdf->v0.y);
	ft_bresenaux(fdf);
	while (TRUE)
	{
		if (fdf->v0.x < fdf->imagelength
			&& fdf->v0.y < fdf->imageheight)
			ft_pixelput(window, fdf->v0.x, fdf->v0.y, fdf->v0.color);
		if (fdf->v0.x == fdf->v1.x && fdf->v0.y == fdf->v1.y)
			break ;
		fdf->ham.e2 = fdf->ham.err * 2;
		if (fdf->ham.e2 >= fdf->ham.dy)
		{
			fdf->ham.err += fdf->ham.dy;
			fdf->v0.x += fdf->ham.sx;
		}
		if (fdf->ham.e2 <= fdf->ham.dx)
		{
			fdf->ham.err += fdf->ham.dx;
			fdf->v0.y += fdf->ham.sy;
		}
	}
}

//!SECTION

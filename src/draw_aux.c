/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/31 20:36:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
void	ft_markpoint(t_point *point, t_matrix *matrix, int count_x, int count_y)
{
	point->v0.x = matrix->vector[count_y][count_x].x;
	point->v0.y = matrix->vector[count_y][count_x].y;
	point->v0.z = matrix->vector[count_y][count_x].z;
	point->v0.color = matrix->vector[count_y][count_x].color;
	point->v1.x = matrix->vector[count_y][count_x + 1].x;
	point->v1.y = matrix->vector[count_y][count_x + 1].y;
	point->v1.z = matrix->vector[count_y][count_x + 1].z;
	point->v1.color = matrix->vector[count_y][count_x + 1].color;
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

//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_point *point)
{
	mlx_string_put(window->mlx, window->win, 1, 1, 0xFFFF00,
		ft_strjoin("Width: ", ft_itoa(point->imagelength / point->scale)));
	mlx_string_put(window->mlx, window->win, 1, 15, 0xFFFF00,
		ft_strjoin("Height: ", ft_itoa(point->imageheight / point->scale)));
	mlx_string_put(window->mlx, window->win, 1, 30, 0xFFFF00,
		ft_strjoin("Scale: ", ft_itoa((int)point->scale)));
}

//ANCHOR - ISO Projection
void	ft_isoprojection(int *x, int *y, int angle)
{
	int	x0;
	int	y0;

	x0 = *x;
	y0 = *y;
	*x = x0 * cos(ft_toradian(angle)) - y0 * sin(ft_toradian(angle));
	*y = x0 * sin(ft_toradian(angle)) + y0 * cos(ft_toradian(angle));
}

//ANCHOR - Draw Net
void	ft_draw_xy(t_window *window, t_point *point)
{
	register int	pixel;
	int				dx;
	int				dy;

	dx = abs(point->v1.x - point->v0.x);
	dy = abs(point->v1.y - point->v0.y);
	pixel = (2 * dy) - dx;
	while (point->v0.x <= point->v1.x)
	{
		if (point->v0.x < point->imagelength && point->v0.y < point->imageheight)
		{
			ft_pixelput(window, point->v0.x, point->v0.y, point->v0.color);
			ft_pixelput(window, point->v0.y, point->v0.x, point->v0.color);
		}
		point->v0.x += 1;
		if (pixel >= 0)
		{
			pixel += 2 * (dy - dx);
			point->v0.y += 1;
		}
		else
			pixel += 2 * dy;
	}
}

void	ft_draw_matrix(t_window *window, t_point *matrix)
{
	register int	pixel;
	int				dx;
	int				dy;

	dx = abs(matrix->vector[count_y][count_x + 1].x - matrix->vector[count_y][count_x].x);
	dy = abs(matrix->vector[count_y][count_x + 1].y - matrix->vector[count_y][count_x].y);
	pixel = (2 * dy) - dx;
	while (point->v0.x <= point->v1.x)
	{
		if (point->v0.x < point->imagelength && point->v0.y < point->imageheight)
		{
			ft_pixelput(window, point->v0.x, point->v0.y, point->v0.color);
			ft_pixelput(window, point->v0.y, point->v0.x, point->v0.color);
		}
		point->v0.x += 1;
		if (pixel >= 0)
		{
			pixel += 2 * (dy - dx);
			point->v0.y += 1;
		}
		else
			pixel += 2 * dy;
	}
}
//!SECTION

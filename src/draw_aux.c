/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/02 20:25:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
void	ft_markpoint(t_fdf *fdf, t_matrix *matrix)
{
	fdf->v0.x = matrix->vector[matrix->count_y][matrix->count_x].x;
	fdf->v0.y = matrix->vector[matrix->count_y][matrix->count_x].y;
	fdf->v0.z = matrix->vector[matrix->count_y][matrix->count_x].z;
	fdf->v0.color = matrix->vector[matrix->count_y][matrix->count_x].color;
	fdf->v1.x = matrix->vector[matrix->count_y][matrix->count_x + 1].x;
	fdf->v1.y = matrix->vector[matrix->count_y][matrix->count_x + 1].y;
	fdf->v1.z = matrix->vector[matrix->count_y][matrix->count_x + 1].z;
	fdf->v1.color
		= matrix->vector[matrix->count_y][matrix->count_x + 1].color;
}

//ANCHOR - Pixel Put
void	ft_pixelput(t_window *window, float dist_x, float dist_y, int color)
{
	char	*dst;

	if (dist_x < 0 || dist_y < 0)
		return ;
	dst = window->addr
		+ (int)(window->size_line * dist_y + dist_x * (window->bpp / 8));
	if (dst != NULL)
		*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}

//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_fdf *fdf)
{
	mlx_string_put(window->mlx, window->win, 1, 1, 0xFFFF00,
		ft_strjoin("Width: ", ft_itoa(fdf->imagelength / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 15, 0xFFFF00,
		ft_strjoin("Height: ", ft_itoa(fdf->imageheight / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 30, 0xFFFF00,
		ft_strjoin("Scale: ", ft_itoa((int)fdf->scale)));
}

//ANCHOR - Draw Net
void	ft_draw_xy(t_window *window, t_fdf *fdf)
{
	register int	pixel;
	float			dx;
	float			dy;

	dx = fabs(fdf->v1.x - fdf->v0.x);
	dy = fabs(fdf->v1.y - fdf->v0.y);
	pixel = (2 * dy) - dx;
	while (fdf->v0.x <= fdf->v1.x)
	{
		if (fdf->v0.x < fdf->imagelength
			&& fdf->v0.y < fdf->imageheight)
		{
			ft_pixelput(window, fdf->v0.x, fdf->v0.y, fdf->v0.color);
			ft_pixelput(window, fdf->v0.y, fdf->v0.x, fdf->v0.color);
		}
		fdf->v0.x += 1;
		if (pixel >= 0)
		{
			pixel += 2 * (dy - dx);
			fdf->v0.y += 1;
		}
		else
			pixel += 2 * dy;
	}
}
//!SECTION

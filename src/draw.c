/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/08 21:05:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
//ANCHOR - Draw borders
static void	ft_drawaxis(t_window *window, t_fdf *fdf)
{
	register int	pixel;
	int				maxlen;
	int				maxwidth;

	pixel = 0;
	maxwidth = fdf->imagelength - fdf->margin - (fdf->imagelength * 0.1);
	maxlen = fdf->imageheight - fdf->margin - (fdf->imageheight * 0.1);
	while (pixel < maxwidth)
	{
		ft_pixelput(window, pixel, 0, 0x00FF00);
		pixel++;
	}
	pixel = 0;
	while (pixel < maxlen)
	{
		ft_pixelput(window, 0, pixel, 0xFFFF00);
		pixel++;
	}
}

static void	ft_plot(t_window *window, t_fdf *fdf, t_matrix *matrix)
{
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length - 1)
		{
			ft_markpoint(fdf, matrix);
			ft_bresenham(window, fdf);
			++matrix->count_x;
		}
		++matrix->count_y;
	}
}

static void	ft_project_to_image(t_window *window, t_fdf *fdf, t_matrix *matrix,
	t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_fillmatrix(map, &matrix);
	ft_apply(matrix, ft_translate, fdf);
	ft_apply(matrix, ft_rotate, fdf);
	ft_matrixmin(matrix, fdf);
	if (fdf->min_x < 0 || fdf->min_y < 0)
		ft_apply(matrix, ft_normalize, fdf);
	ft_printmatrix(matrix);
	ft_plot(window, fdf, matrix);
}

void
	ft_projectmap(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	ft_apply(matrix, ft_angleinit, fdf);
	ft_drawaxis(window, fdf);
	ft_project_to_image(window, fdf, matrix, map);
	fdf->angle = 1;
	ft_project_to_image(window, fdf, matrix, map);
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_fdf *fdf, t_matrix *matrix)
{
	ft_projectmap(window, fdf, matrix, map);
	ft_printheader(window, fdf);
	ft_printfdf(fdf);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, fdf->margin + 5, fdf->margin + 5);
}
//!SECTION

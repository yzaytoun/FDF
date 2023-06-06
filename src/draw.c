/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/06 21:08:00 by yzaytoun         ###   ########.fr       */
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

void	ft_plot(t_window *window, t_fdf *fdf, t_matrix *matrix)
{
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length - 1)
		{
			ft_markpoint(fdf, matrix);
			ft_draw_xy(window, fdf);
			++matrix->count_x;
		}
		++matrix->count_y;
	}
}

void	ft_getmatrix(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_fillmatrix(map, &matrix);
	ft_transform(matrix, ft_translate, fdf);
	ft_transform(matrix, ft_angleprojection, fdf);
	ft_matrixmin(matrix, fdf);
	if (fdf->min_x < 0 || fdf->min_y < 0)
		ft_transform(matrix, ft_topositive, fdf);
}

static void	ft_projectmap(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	ft_drawaxis(window, fdf);
	fdf->angle = 30;
	ft_getmatrix(window, fdf, matrix, map);
	ft_plot(window, fdf, matrix);
	fdf->angle = 120;
	ft_getmatrix(window, fdf, matrix, map);
	ft_plot(window, fdf, matrix);
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_fdf *fdf)
{
	t_matrix	*matrix;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	matrix = ft_creatematrix(map, fdf);
	ft_projectmap(window, fdf, matrix, map);
	ft_printheader(window, fdf);
	ft_printfdf(fdf);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, fdf->margin + 5, fdf->margin + 5);
	ft_destroyvector(&matrix->vector, matrix->height);
	free(matrix);
}
//!SECTION

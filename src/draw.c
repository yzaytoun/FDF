/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/02 20:29:33 by yzaytoun         ###   ########.fr       */
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

static void	ft_projectmap(t_window *window, t_fdf *fdf, t_matrix *matrix)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_drawaxis(window, fdf);
	ft_transform(matrix, ft_isoprojection, fdf);
	ft_matrixmin(matrix);
	fdf->min = matrix->min;
	if (fdf->min < 0)
		ft_transform(matrix, ft_topositive, fdf);
	ft_transform(matrix, ft_translate, fdf);
	ft_printmatrix(matrix);
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

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_fdf *fdf)
{
	t_matrix	*matrix;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	matrix = ft_creatematrix(map, fdf);
	ft_fillmatrix(map, &matrix);
	ft_projectmap(window, fdf, matrix);
	ft_printheader(window, fdf);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, fdf->margin + 5, fdf->margin + 5);
	ft_destroyvector(&matrix->vector, matrix->height);
	free(matrix);
}
//!SECTION

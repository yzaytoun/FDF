/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/30 19:44:53 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
//ANCHOR - Draw borders
static void	ft_drawaxis(t_window *window, t_point *point)
{
	register int	pixel;
	int				maxlen;
	int				maxwidth;

	pixel = 0;
	maxwidth = point->imagelength - point->margin - (point->imagelength * 0.1);
	maxlen = point->imageheight - point->margin - (point->imageheight * 0.1);
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

static void	ft_projectmap(t_window *window, t_point *point, t_matrix *matrix)
{
	ft_drawaxis(window, point);
	ft_printmatrix(matrix);
	/*while (count_y < matrix->height)
	{
		count_x = 0;
		while (count_x < matrix->length - 1)
		{
			ft_markpoint(point, matrix);
			ft_draw_xy(window, point);	
			++count_x;
		}
		++count_y;
	}*/
}



//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_point *point)
{
	t_matrix	*matrix;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	matrix = ft_creatematrix(map, point);
	ft_fillmatrix(map, matrix);
	ft_projectmap(window, point, matrix);
	ft_printheader(window, point);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, point->margin + 5, point->margin + 5);
	ft_destroyvector(&matrix->vector, matrix->height);
	free(matrix);
}
//!SECTION

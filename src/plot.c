/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/30 17:56:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
//ANCHOR - Plot axis
void	ft_plotaxis(t_window *window, t_fdf *fdf)
{
	ft_getcoord(fdf, fdf->maxlen_x / 2, fdf->maxlen_y / 2, FIRST_POINT);
	ft_getcoord(fdf, fdf->maxlen_x, fdf->maxlen_y / 2, SECOND_POINT);
	ft_bresenham(window, fdf);
	ft_getcoord(fdf, fdf->maxlen_x / 2, fdf->maxlen_y / 2, FIRST_POINT);
	ft_getcoord(fdf, fdf->maxlen_x / 2, 0, SECOND_POINT);
	ft_bresenham(window, fdf);
	ft_getcoord(fdf, 0, 55, FIRST_POINT);
	ft_getcoord(fdf, fdf->imagelength, 55, SECOND_POINT);
	ft_bresenham(window, fdf);
}

//ANCHOR - plot
void	ft_plot(t_window *window, t_fdf *fdf, t_matrix *matrix)
{
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height - 1)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length - 1)
		{
			fdf->flags.x_axis = 0;
			ft_markpoint(fdf, matrix);
			ft_bresenham(window, fdf);
			fdf->flags.x_axis = 1;
			ft_markpoint(fdf, matrix);
			ft_bresenham(window, fdf);
			++matrix->count_x;
		}
		++matrix->count_y;
	}
}

//ANCHOR - Main func
int	ft_plotmap(void *param)
{
	t_params	*params;

	params = (t_params *)param;
	ft_project(params->window, params->fdf, params->matrix, params->map);
	mlx_put_image_to_window(params->window->mlx, params->window->win,
		params->window->img, 0, 0);
	ft_printheader(params->window, params->fdf);
	return (EXIT_SUCCESS);
}
//!SECTION

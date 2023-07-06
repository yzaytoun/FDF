/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/05 18:35:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Plot
//ANCHOR - Close shape
void	ft_closeshape(t_window *window, t_fdf *fdf, t_matrix *matrix)
{
	matrix->count_y = 0;
	matrix->count_x = matrix->length - 1;
	fdf->flags.x_axis = 0;
	while (matrix->count_y < matrix->height - 1)
	{
		ft_markpoint(fdf, matrix);
		ft_bresenham(window, fdf);
		matrix->count_y++;
	}
	matrix->count_y = matrix->height - 1;
	matrix->count_x = 0;
	fdf->flags.x_axis = 1;
	while (matrix->count_x < matrix->length - 1)
	{
		ft_markpoint(fdf, matrix);
		ft_bresenham(window, fdf);
		matrix->count_x++;
	}
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
			fdf->flags.x_axis = 1;
			ft_markpoint(fdf, matrix);
			ft_bresenham(window, fdf);
			fdf->flags.x_axis = 0;
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
	if (params->hook->spin == TRUE)
		params->fdf->angle.z -= ft_toradian(0.5);
	ft_printheader(params->window, params->fdf);
	return (EXIT_SUCCESS);
}
//!SECTION

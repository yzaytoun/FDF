/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/27 20:43:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
//ANCHOR - Plot axis
void	ft_plotaxis(t_window *window, t_fdf *fdf)
{
	fdf->v0.x = 0;
	fdf->v0.y = 0;
	fdf->v1.x = fdf->imagelength - fdf->margin;
	fdf->v1.y = 0;
	ft_bresenham(window, fdf);
	fdf->v0.x = 0;
	fdf->v0.y = 0;
	fdf->v1.x = 0;
	fdf->v1.y = fdf->imageheight - fdf->margin;
	ft_bresenham(window, fdf);
}

//ANCHOR - plot
void	ft_plot(t_window *window, t_fdf *fdf, t_matrix *matrix)
{
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

//ANCHOR - Main func
int	ft_plotmap(void *param)
{
	t_params	*params;

	params = (t_params *)param;
	ft_project(params->window, params->fdf, params->matrix, params->map);
	ft_printheader(params->window, params->fdf);
	//ft_printfdf(params->fdf);
	mlx_put_image_to_window(params->window->mlx, params->window->win,
		params->window->img, params->fdf->margin, params->fdf->margin);
	return (EXIT_SUCCESS);
}
//!SECTION

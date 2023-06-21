/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/21 21:18:47 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
//ANCHOR - Angle init
void	ft_fdfinit(t_fdf *fdf)
{
	fdf->flags.focal = 1;
	fdf->flags.translation_x = fdf->imagelength / 2 - fdf->margin;
	fdf->flags.translation_y = fdf->imageheight / 2 - fdf->margin;
	fdf->angle.x = ft_toradian(0);
	fdf->angle.y = ft_toradian(0);
	fdf->angle.z = ft_toradian(30);
}

//ANCHOR - Plot axis
static void	ft_plotaxis(t_window *window, t_fdf *fdf)
{
	fdf->v0.x = fdf->imagelength / 2 - fdf->margin;
	fdf->v0.y = fdf->imageheight / 2 - fdf->margin;
	fdf->v1.x = fdf->imagelength / 2 - fdf->margin;
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
	ft_plotaxis(params->win, params->fdf);
	ft_project(params->win, params->fdf, params->matrix, params->map);
	ft_printheader(params->win, params->fdf);
	//ft_printfdf(params->fdf);
	mlx_put_image_to_window(params->win->mlx, params->win->win,
		params->win->img, params->fdf->margin, params->fdf->margin);
	return(EXIT_SUCCESS);
}
//!SECTION

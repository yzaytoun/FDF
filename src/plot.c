/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/19 19:34:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
//ANCHOR - Angle init
void	ft_fdfinit(t_fdf *fdf)
{
	fdf->flags.translation = 5;
	fdf->flags.focal = 1;
	fdf->angle.x = ft_toradian(0);
	fdf->angle.y = ft_toradian(0);
	fdf->angle.z = ft_toradian(0);
}

//ANCHOR - Plot axis
static void	ft_plotaxis(t_window *window, t_fdf *fdf)
{
	float	magnitude;

	(void)window;
	fdf->v0.x = (fdf->imagelength / 2);
	fdf->v0.y = (fdf->imageheight / 2);
	fdf->v1.x = 0;
	fdf->v1.y = 0;
	magnitude = sqrt(powf(fdf->v1.y, 2));
	//fdf->v1.y += fdf->v1.y * cos(ft_toradian(120));
	printf("v1 = %i\n", fdf->v1.y);
	ft_bresenham(window, fdf);
}

//ANCHOR - plot
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
			ft_bresenham(window, fdf);
			++matrix->count_x;
		}
		++matrix->count_y;
	}
}

//ANCHOR - Main func
void	ft_plotmap(t_window *window, t_map *map, t_fdf *fdf, t_matrix *matrix)
{
	(void)map;
	(void)matrix;
	ft_fdfinit(fdf);
	ft_plotaxis(window, fdf);
	//ft_project(window, fdf, matrix, map);
	ft_printheader(window, fdf);
	ft_printfdf(fdf);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, fdf->imagelength / 2, fdf->imageheight / 2);
}
//!SECTION

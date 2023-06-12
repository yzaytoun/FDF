/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:45:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/12 19:06:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Draw Map
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
	ft_project(window, fdf, matrix, map);
	ft_printheader(window, fdf);
	ft_printfdf(fdf);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, fdf->margin + 5, fdf->margin + 5);
}
//!SECTION

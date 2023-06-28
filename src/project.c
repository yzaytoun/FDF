/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/28 20:58:00 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Project
//ANCHOR - Reset image
static void	ft_resetimage(t_window *window, t_fdf *fdf)
{
	mlx_destroy_image(window->mlx, window->img);
	ft_createimage(window, fdf);
}

//ANCHOR - Project matrix
static void	ft_project_to_image(t_window *window, t_fdf *fdf, t_matrix *matrix,
	t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_matrix_map(map, &matrix);
	fdf->flags.operation = ADD;
	ft_apply(matrix, ft_increment, fdf);
	ft_apply(matrix, ft_rotate_z, fdf);
	ft_apply(matrix, ft_translate, fdf);
	ft_matrixmin(matrix, fdf);
	/*if (fdf->min_x < 0 || fdf->min_y < 0)
		ft_apply(matrix, ft_topositive, fdf); */
	ft_plot(window, fdf, matrix);
}

void
	ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	ft_resetimage(window, fdf);
	ft_plotaxis(window, fdf);
	ft_project_to_image(window, fdf, matrix, map);
}

//!SECTION
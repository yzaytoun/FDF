/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/11 10:48:10 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Project
//ANCHOR - Project matrix
/*static void	ft_project_to_image(t_window *window, t_fdf *fdf, t_matrix *matrix,
	t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_matrix_map(map, &matrix);
	ft_apply(matrix, ft_translate, fdf);
	//ft_apply(matrix, ft_rotate, fdf);
	ft_apply(matrix, ft_to2d, fdf);
	ft_matrixmin(matrix, fdf);
	if (fdf->min_x < 0 || fdf->min_y < 0)
		ft_apply(matrix, ft_normalize, fdf);
	ft_printmatrix(matrix);
	ft_plot(window, fdf, matrix);
}
*/
void
	ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	(void)map;
	ft_apply(matrix, ft_angleinit, fdf);
	ft_apply(matrix, ft_matrotate, fdf);
	ft_plotaxis(window, fdf);
	//ft_project_to_image(window, fdf, matrix, map);
}

//!SECTION
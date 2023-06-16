/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/16 21:18:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Project
//ANCHOR - Angle init
void	ft_fdfinit(t_fdf *fdf)
{
	fdf->flags.translation = 5;
	fdf->flags.orientation = LOWERLEFT;
	fdf->flags.focal = 1;
	fdf->angle.x = 120;
	fdf->angle.y = 120 * 2;
	fdf->angle.z = 120 * 3;
}
void	ft_positive(t_vector *vector, t_fdf *fdf)
{
	if (vector->x < 0)
		vector->x +=  fabsf(fdf->min_x);
	if (vector->y < 0)
		vector->y += fabsf(fdf->min_y);
}

//ANCHOR - Project matrix
static void	ft_project_to_image(t_window *window, t_fdf *fdf, t_matrix *matrix,
	t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_matrix_map(map, &matrix);
	ft_apply(matrix, ft_increment, fdf);
	fdf->rotatemat = ft_get_rotmat(fdf);
	if (!fdf->rotatemat)
		return ;
	ft_apply(matrix, ft_matrotate, fdf);
	ft_printmatrix(matrix);
	ft_apply(matrix, ft_normalize, fdf);
	ft_printmatrix(matrix);
	//ft_apply(matrix, ft_dimcamera, fdf);
	//ft_apply(matrix, ft_to2d, fdf);
	ft_matrixmin(matrix, fdf);
	if (fdf->min_x < 0 || fdf->min_y < 0)
		ft_apply(matrix, ft_positive, fdf);
	ft_plot(window, fdf, matrix);
}

void
	ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	ft_fdfinit(fdf);
	ft_project_to_image(window, fdf, matrix, map);
}

//!SECTION
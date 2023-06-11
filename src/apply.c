/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:30:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/11 15:26:24 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Apply
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	vector->x *= fdf->distance_x;
	vector->y *= fdf->distance_y;
	vector->z += 0.7;
}

//FIXME - To 2D
void	ft_to2d(t_vector *vector, t_fdf *fdf)
{
	(void)fdf;
	if (vector->z != 0)
	{
		vector->x /= vector->z;
		vector->y /= vector->z;
	}
}

//ANCHOR - To positive
void	ft_normalize(t_vector *vector, t_fdf *fdf)
{
	if (fdf->min_x < 0)
		vector->x += fabs(fdf->min_x);
	if (fdf->min_y < 0)
		vector->y += fabs(fdf->min_y);
}

//ANCHOR - Rotate
void	ft_matrotate(t_vector *vector, t_fdf *fdf)
{
	t_matrix	*matrix;
	t_matrix	*mat_1;
	t_matrix	*mat_2;

	mat_1 = ft_get_rotmat(vector, fdf);
	if (!mat_1)
		return ;
	mat_2 = ft_vectomat(vector);
	matrix = ft_matmult(mat_1, mat_2);
	vector->x = matrix->vector[0][0].x + matrix->vector[0][0].y
		+ matrix->vector[0][0].z;
	vector->y = matrix->vector[1][0].x + matrix->vector[1][0].y
		+ matrix->vector[1][0].z;
	vector->z = matrix->vector[2][0].x + matrix->vector[2][0].y
		+ matrix->vector[2][0].z;
	ft_destroyvector(&mat_1->vector, mat_1->height);
	free(mat_1);
	ft_destroyvector(&mat_2->vector, mat_2->height);
	free(mat_2);
	ft_destroyvector(&matrix->vector, matrix->height);
	free(matrix);
}

//ANCHOR - Main func
void	ft_apply(t_matrix *matrix, void (*func)(t_vector *, t_fdf *)
	, t_fdf *fdf)
{
	if (!matrix || !(*func))
		return ;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			(*func)(&matrix->vector[matrix->count_y][matrix->count_x], fdf);
			matrix->count_x++;
		}
		matrix->count_y++;
	}
}

//!SECTION 

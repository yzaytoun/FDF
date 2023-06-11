/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:25:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/11 13:54:56 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Matrix X Vector Operations
//ANCHOR - Matrix Multiplication
t_matrix	*ft_matmult(t_matrix *mat_1, t_matrix *mat_2)
{
	t_matrix	*matrix;

	matrix = ft_creatematrix(mat_1->length, mat_1->height);
	if (!matrix)
		return (NULL);
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			matrix->vector[matrix->count_y][matrix->count_x].x
				= mat_1->vector[matrix->count_y][matrix->count_x].x
				* mat_2->vector[matrix->count_y][matrix->count_x].x;
			matrix->vector[matrix->count_y][matrix->count_x].y
				= mat_1->vector[matrix->count_y][matrix->count_x].y
				* mat_2->vector[matrix->count_y][matrix->count_x].y;
			matrix->vector[matrix->count_y][matrix->count_x].z
				= mat_1->vector[matrix->count_y][matrix->count_x].z
				* mat_2->vector[matrix->count_y][matrix->count_x].z;
			matrix->count_x++;
		}
		matrix->count_y++;
	}
	return (matrix);
}

//ANCHOR - Vector to matrix
t_matrix	*ft_vectomat(t_vector *vector)
{
	t_matrix	*matrix;

	if (!vector)
		return (NULL);
	matrix = ft_creatematrix(1,3);
	if (!matrix)
		return (NULL);
	matrix->vector[0][0].x = vector->x;
	matrix->vector[1][0].y = vector->y;
	matrix->vector[2][0].z = vector->z;
	return (matrix);
}
//!SECTION

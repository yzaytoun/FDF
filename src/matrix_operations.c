/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:25:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/16 20:15:48 by yzaytoun         ###   ########.fr       */
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
				+= mat_1->vector[matrix->count_y][matrix->count_x].x
				* mat_2->vector[matrix->count_y][matrix->count_x].x;
			matrix->vector[matrix->count_y][matrix->count_x].y
				+= mat_1->vector[matrix->count_y][matrix->count_x].y
				* mat_2->vector[matrix->count_y][matrix->count_x].y;
			matrix->vector[matrix->count_y][matrix->count_x].z
				+= mat_1->vector[matrix->count_y][matrix->count_x].z
				* mat_2->vector[matrix->count_y][matrix->count_x].z;
			matrix->count_x++;
		}
		matrix->count_y++;
	}
	return (matrix);
}

static void	ft_vecmultaux(t_matrix *result, t_vector *vector, t_matrix *matrix)
{
	result->count_y = 0;
	while (result->count_y < result->height)
	{
		result->count_x = 0;
		while (result->count_x < result->height)
		{
			result->vector[result->count_y][result->count_x].x
				= vector->x * matrix->vector[result->count_y][result->count_x].x
				+ vector->y * matrix->vector[result->count_y][result->count_x].y
				+ vector->z
				* matrix->vector[result->count_y][result->count_x].z;
			result->vector[result->count_y][result->count_x].y
				= vector->x * matrix->vector[result->count_y][result->count_x].x
				+ vector->y * matrix->vector[result->count_y][result->count_x].y
				+ vector->z
				* matrix->vector[result->count_y][result->count_x].z;
			result->vector[result->count_y][result->count_x].z
				= vector->x * matrix->vector[result->count_y][result->count_x].x
				+ vector->y * matrix->vector[result->count_y][result->count_x].y
				+ vector->z
				* matrix->vector[result->count_y][result->count_x].z;
			result->count_x++;
		}
		result->count_y++;
	}
}

//ANCHOR - Vector to matrix
t_matrix	*ft_vecmult(t_vector *vector, t_matrix *matrix)
{
	t_matrix	*result;

	if (!vector || !matrix)
		return (NULL);
	result = ft_creatematrix(1, 1);
	if (!result)
		return (NULL);
	ft_vecmultaux(result, vector, matrix);
	return (result);
}
//!SECTION

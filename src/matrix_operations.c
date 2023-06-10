/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:25:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/10 18:13:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Matrix X Vector Operations
t_matrix	ft_matmult(t_matrix *mat_1, t_matrix *mat_2)
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
			matrix->vector[count_y][count_x].x
				= mat_1->vector[count_y][count_x].x
				* mat_2->vector[count_y][count_x].x;
			matrix->vector[count_y][count_x].y
				= mat_1->vector[count_y][count_x].y
				* mat_2->vector[count_y][count_x].y;
			matrix->vector[count_y][count_x].z
				= mat_1->vector[count_y][count_x].z
				* mat_2->vector[count_y][count_x].z;
			matrix->count_x++;
		}
		matrix->count_y++;
	}
	return (matrix);
}

//!SECTION

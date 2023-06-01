/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/01 19:08:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - AUX Matrix
//ANCHOR - Min Matrix
void	ft_matrixmin(t_matrix *matrix)
{
	matrix->min = matrix->vector[0][0].x;
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			if (matrix->min
				> matrix->vector[matrix->count_y][matrix->count_x].x)
				matrix->min
					= matrix->vector[matrix->count_y][matrix->count_x].x;
			matrix->count_x++;
		}
		matrix->count_y++;
	}
}

//!SECTION

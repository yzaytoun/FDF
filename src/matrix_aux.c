/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/03 11:45:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - AUX Matrix
//ANCHOR - Min Matrix
void	ft_matrixmin(t_matrix *matrix, t_fdf *fdf)
{
	fdf->min_x = matrix->vector[0][0].x;
	fdf->min_y = matrix->vector[0][0].y;
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			if (fdf->min_x
				> matrix->vector[matrix->count_y][matrix->count_x].x)
				fdf->min_x
					= matrix->vector[matrix->count_y][matrix->count_x].x;
			if (fdf->min_y
				> matrix->vector[matrix->count_y][matrix->count_x].y)
				fdf->min_y
					= matrix->vector[matrix->count_y][matrix->count_x].y;
			matrix->count_x++;
		}
		matrix->count_y++;
	}
}

//!SECTION

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/08 17:41:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Aux Function
//ANCHOR - Error handling
void	ft_exception(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

//ANCHOR - to radian
float	ft_toradian(double angle)
{
	return ((angle * M_PI) / 180);
}

//ANCHOR - To integer
int	ft_toint(float num)
{
	return ((int)roundf(num));
}

//ANCHOR - Get mid point
void	ft_get_midpoint(t_fdf *fdf, t_matrix *matrix)
{
	int	midx;
	int	midy;

	midx = round(matrix->length / 2);
	midy = round(matrix->height / 2);
	fdf->mid_v.x = matrix->vector[midy][midx].x;
	fdf->mid_v.y = matrix->vector[midy][midx].y;
	fdf->mid_v.z = matrix->vector[midy][midx].z;
}

//ANCHOR - Mark black colors
void	ft_get_blackpoints(t_matrix *matrix)
{
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length - 1)
		{
			if (matrix->vector[matrix->count_y][matrix->count_x].x
				== matrix->vector[matrix->count_y][matrix->count_x + 1].x
				&& matrix->vector[matrix->count_y][matrix->count_x].y
				== matrix->vector[matrix->count_y][matrix->count_x + 1].y)
				matrix->vector[matrix->count_y][matrix->count_x].color = BLACK;
			++matrix->count_x;
		}
		++matrix->count_y;
	}
}
//!SECTION

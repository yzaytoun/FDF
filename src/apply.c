/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:30:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/12 20:53:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Apply
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	vector->x *= fdf->distance_x;
	vector->y *= fdf->distance_y;
	vector->z += 1;
}

//FIXME - To 2D
void	ft_to2d(t_vector *vector, t_fdf *fdf)
{
	if (vector->z != 0)
	{
		if (fdf->flags.orientation == LOWERLEFT)
			vector->x *= -1;
		else if (fdf->flags.orientation == UPPERRIGHT)
			vector->y *= -1;
		else if  (fdf->flags.orientation == LOWERRIGHT)
		{
			vector->x *= 1;
			vector->y *= 1;
		}
		else
		{
			vector->x *= -1;
			vector->y *= -1;
		}
		vector->x /= vector->z * fdf->flags.focal;
		vector->y /= vector->z * fdf->flags.focal;
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
	t_matrix	*vecmat;

	vecmat = ft_vectomat(vector);
	matrix = ft_matmult(fdf->rotatemat, vecmat);
	vector->x = matrix->vector[0][0].x + matrix->vector[0][0].y
		+ matrix->vector[0][0].z;
	vector->y = matrix->vector[1][0].x + matrix->vector[1][0].y
		+ matrix->vector[1][0].z;
	vector->z = matrix->vector[2][0].x + matrix->vector[2][0].y
		+ matrix->vector[2][0].z;
	ft_destroyvector(&vecmat->vector, vecmat->height);
	free(vecmat);
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

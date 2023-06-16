/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:30:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/16 21:08:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Apply
void	ft_increment(t_vector *vector, t_fdf *fdf)
{
	vector->x *= fdf->distance_x;
	vector->y *= fdf->distance_y;
	vector->z += 1;
}

//ANCHOR - To 2D
void	ft_to2d(t_vector *vector, t_fdf *fdf)
{
	if (vector->z > 0)
	{
		if (fdf->flags.orientation == LOWERLEFT)
			vector->y *= -1;
		else if (fdf->flags.orientation == UPPERRIGHT)
			vector->x *= -1;
		else
		{
			vector->x *= -1;
			vector->y *= -1;
		}
		vector->x /= vector->z * fdf->flags.focal;
		vector->y /= vector->z * fdf->flags.focal;
	}
	else if (vector->z < 0)
	{
		vector->x /= vector->z * fdf->flags.focal;
		vector->y /= vector->z * fdf->flags.focal;
	}
}

//ANCHOR - To positive
void	ft_normalize(t_vector *vector, t_fdf *fdf)
{
	(void)fdf;
	float	invelen;

	invelen = 1 / sqrtf(powf(vector->x, 2) + powf(vector->y, 2)
			+ powf(vector->z, 2));
	vector->x *= invelen;
	vector->y *= invelen;
	vector->z *= invelen;
}

//ANCHOR - Rotate
void	ft_matrotate(t_vector *vector, t_fdf *fdf)
{
	t_matrix	*matrix;

	matrix = ft_vecmult(vector, fdf->rotatemat);
	vector->x = matrix->vector[0][0].x;
	vector->y = matrix->vector[0][0].y;
	vector->z = matrix->vector[0][0].z;
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

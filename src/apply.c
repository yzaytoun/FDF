/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:30:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Apply
void	ft_scale(t_vector *vector, t_fdf *fdf)
{
	if (fdf->distance_x > 0 && fdf->distance_y > 0)
	{
		vector->x *= fdf->distance_x;
		vector->y *= fdf->distance_y;
	}
	vector->z *= fdf->distance_z;
}

//ANCHOR - Normalize
void	ft_normalize(t_vector *vector, t_fdf *fdf)
{
	float	v;
	float	x;
	float	y;
	float	z;

	(void)fdf;
	x = vector->x;
	y = vector->y;
	z = vector->z;
	v = sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	if (z != 0)
	{
		vector->x = x / z;
		vector->y = y / z;
	}
}

//ANCHOR - Translate
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	if (fdf->flags.translation_x > 0 && fdf->flags.translation_y > 0)
	{
		vector->x += fdf->flags.translation_x;
		vector->y += fdf->flags.translation_y;
	}
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

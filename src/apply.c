/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:30:00 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/22 20:43:30 by yzaytoun         ###   ########.fr       */
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

//ANCHOR - Translate
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	vector->x += fdf->flags.translation_x;
	vector->y += fdf->flags.translation_y;
}

//ANCHOR - Normalize
void	ft_normalize(t_vector *vector, t_fdf *fdf)
{
	float	invelen;

	(void)fdf;
	invelen = 1 / sqrtf(powf(vector->x, 2) + powf(vector->y, 2)
			+ powf(vector->z, 2));
	vector->x *= invelen;
	vector->y *= invelen;
	vector->z *= invelen;
}

//ANCHOR - Positive
void	ft_topositive(t_vector *vector, t_fdf *fdf)
{
	if (vector->x < 0)
		vector->x +=  fabsf(fdf->min_x);
	if (vector->y < 0)
		vector->y += fabsf(fdf->min_y);
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

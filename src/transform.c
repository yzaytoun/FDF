/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:27:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/02 20:30:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Transform
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	vector->x *= fdf->distance_x / 2;
	vector->y *= fdf->distance_y / 2;
	vector->z *= fdf->distance_y / 4;
}

//ANCHOR - To positive
void	ft_topositive(t_vector *vector, t_fdf *fdf)
{
	vector->x += abs(fdf->min);
}

//ANCHOR - ISO Projection
void	ft_isoprojection(t_vector *vector, t_fdf *fdf)
{
	float	x0;
	float	y0;
	float	angle;

	(void)fdf;
	if (!vector)
		return ;
	angle = 60;
	x0 = vector->x;
	y0 = vector->y;
	vector->x = x0 * cosf(ft_toradian(angle));
	vector->y = y0 * sinf(ft_toradian(angle));
}

//ANCHOR - Main func
void	ft_transform(t_matrix *matrix, void (*func)(t_vector *, t_fdf *)
	, t_fdf *fdf)
{
	matrix->count_x = 0;
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

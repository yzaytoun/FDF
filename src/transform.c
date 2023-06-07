/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:27:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/07 21:09:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Transform
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	vector->x *= fdf->distance_x;
	vector->y *= fdf->distance_y;
	vector->z += fdf->distance_y / 20;
}

//ANCHOR - To positive
void	ft_topositive(t_vector *vector, t_fdf *fdf)
{
	if (fdf->min_x < 0)
		vector->x += fabs(fdf->min_x);
	if (fdf->min_y < 0)
		vector->y += fabs(fdf->min_y);
}

//ANCHOR - ISO Projection
void	ft_angleprojection(t_vector *vector, t_fdf *fdf)
{
	float	x0;
	float	y0;

	if (!vector)
		return ;
	x0 = vector->x;
	y0 = vector->y;
	vector->x = (x0 * cosf(ft_toradian(fdf->angle))
			- y0 * sinf(ft_toradian(fdf->angle))) / vector->z;
	vector->y = (x0 * sinf(ft_toradian(fdf->angle))
			+ y0 * cosf(ft_toradian(fdf->angle))) / vector->z;
}


//ANCHOR - Angle init
void	ft_angleinit(t_vector *vector, t_fdf *fdf)
{
	(void)vector;
	fdf->rotate.x = 30;
	fdf->rotate.y = 120;
	fdf->rotate.z = 210;
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

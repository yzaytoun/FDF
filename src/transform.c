/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:27:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/03 16:11:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Transform
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	vector->x *= fdf->distance_x;
	vector->y *= fdf->distance_y;
	vector->z *= fdf->distance_y;
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
void	ft_isoprojection(t_vector *vector, t_fdf *fdf)
{
	float	x0;
	float	y0;
	float	angle;

	(void)fdf;
	if (!vector)
		return ;
	angle = M_PI_2 / 2;
	x0 = vector->x;
	y0 = vector->y;
	vector->x = x0 * cosf(angle) - y0 * sinf(angle);
	vector->y = x0 * sinf(angle) + y0 * cosf(angle);
	//printf("P0(%f, %f) ->> V0(%f,%f)\n", x0, y0, vector->x, vector->y);
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

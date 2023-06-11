/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:41:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/11 10:37:41 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Rotate
//ANCHOR - Angle init
void	ft_angleinit(t_vector *vector, t_fdf *fdf)
{
	(void)vector;
	fdf->angle.x = 120;
	fdf->angle.y = 120 * 2;
	fdf->angle.z = 120 * 3;
}

//ANCHOR - Rotate X
static void	ft_rotate_x(t_vector *vector, t_fdf *fdf)
{
	vector->x = cosf(fdf->angle.y) * cosf(fdf->angle.z);
	vector->y = (sinf(fdf->angle.x) * sinf(fdf->angle.y) * cosf(fdf->angle.z))
		+ (sinf(fdf->angle.z) * cosf(fdf->angle.x));
	vector->z = (-cosf(fdf->angle.x) * sinf(fdf->angle.y) * cosf(fdf->angle.z))
		+ (sinf(fdf->angle.x) * sinf(fdf->angle.z));
}

//ANCHOR - Rotate Y
static void	ft_rotate_y(t_vector *vector, t_fdf *fdf)
{
	vector->x = -cosf(fdf->angle.y) * sinf(fdf->angle.z);
	vector->y = (-sinf(fdf->angle.x) * sinf(fdf->angle.y) * sinf(fdf->angle.z))
		+ (cosf(fdf->angle.z) * cosf(fdf->angle.x));
	vector->z = (cosf(fdf->angle.x) * sinf(fdf->angle.y) * sinf(fdf->angle.z))
		+ (sinf(fdf->angle.x) * cosf(fdf->angle.z));
}

//ANCHOR - Rotate Z
static void	ft_rotate_z(t_vector *vector, t_fdf *fdf)
{
	vector->x = sinf(fdf->angle.y);
	vector->y = (-sinf(fdf->angle.x) * cosf(fdf->angle.y));
	vector->z = (cosf(fdf->angle.x) * cosf(fdf->angle.y));
}

//ANCHOR - Rotation Matrix
t_matrix	*ft_get_rotmat(t_vector *vector, t_fdf *fdf)
{
	t_matrix	*matrix;

	if (!vector || !fdf)
		return (NULL);
	matrix = ft_creatematrix(3, 1);
	if (!matrix)
		return (NULL);
	ft_toradian(&fdf->angle);
	ft_rotate_x(&matrix->vector[0][0], fdf);
	ft_rotate_y(&matrix->vector[1][0], fdf);
	ft_rotate_z(&matrix->vector[2][0], fdf);
	return (matrix);
}

//!SECTION

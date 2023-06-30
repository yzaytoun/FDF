/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:41:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/30 17:44:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Rotate
//ANCHOR - Rotate X
void	ft_rotate_x(t_vector *vector, t_fdf *fdf)
{
	float	x;
	float	y;
	float	z;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	vector->y = y * cosf(fdf->angle.x);
	vector->z = z * cosf(fdf->angle.x);
}

//ANCHOR - Rotate Y
void	ft_rotate_y(t_vector *vector, t_fdf *fdf)
{
	vector->x = -cosf(fdf->angle.y) * sinf(fdf->angle.z);
	vector->y = (-sinf(fdf->angle.x) * sinf(fdf->angle.y) * sinf(fdf->angle.z))
		+ (cosf(fdf->angle.z) * cosf(fdf->angle.x));
	vector->z = (cosf(fdf->angle.x) * sinf(fdf->angle.y) * sinf(fdf->angle.z))
		+ (sinf(fdf->angle.x) * cosf(fdf->angle.z));
}

//ANCHOR - Rotate Z
void	ft_rotate_z(t_vector *vector, t_fdf *fdf)
{
	float	x;
	float	y;
	float	z;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	vector->x = x * cosf(fdf->angle.z) + sinf(fdf->angle.z);
	vector->y = y * sinf(fdf->angle.z);
	//vector->z = cosf(fdf->angle.x) * cosf(fdf->angle.y);
}
//!SECTION

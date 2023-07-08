/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:41:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/08 17:24:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Rotate
void	ft_set_projection(t_vector *vector, t_fdf *fdf)
{
	float	x;
	float	y;
	float	z;
	float	angle;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	if (fdf->flags.iso == TRUE)
	{
		angle = ft_toradian(fdf->isoangle);
		vector->x = (x + y) * cosf(angle);
		vector->y = -z + (x - y) * sinf(angle);
	}
}

//ANCHOR - Rotate X
void	ft_rotate_x(t_vector *vector, t_fdf *fdf)
{
	float	y;
	float	z;

	y = vector->y;
	z = vector->z;
	vector->y = y * cosf(fdf->angle.x) - z * sinf(fdf->angle.x);
	vector->z = y * sinf(fdf->angle.x) + z * cosf(fdf->angle.x);
}

//ANCHOR - Rotate Y
void	ft_rotate_y(t_vector *vector, t_fdf *fdf)
{
	float	x;
	float	z;

	x = vector->x;
	z = vector->z;
	vector->x = x * cosf(fdf->angle.y) + z * sinf(fdf->angle.y);
	vector->z = -x * sinf(fdf->angle.y) + z * cosf(fdf->angle.y);
}

//ANCHOR - Rotate Z
void	ft_rotate_z(t_vector *vector, t_fdf *fdf)
{
	float	x;
	float	y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cosf(fdf->angle.z) - y * sinf(fdf->angle.z);
	vector->y = x * sinf(fdf->angle.z) + y * cosf(fdf->angle.z);
}
//!SECTION

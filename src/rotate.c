/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:41:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/08 21:07:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Rotate
//ANCHOR - Rotate X
void	ft_rotate_x(t_vector *vector, t_fdf *fdf, int y0, int z0)
{
	vector->x = (z0 * cosf(ft_toradian(fdf->rotate.x))
			- y0 * sinf(ft_toradian(fdf->rotate.x)) + vector->x);
	vector->y = (z0 * sinf(ft_toradian(fdf->rotate.x))
			+ y0 * cosf(ft_toradian(fdf->rotate.x)) + vector->x);
}

//ANCHOR - Rotate Y
void	ft_rotate_y(t_vector *vector, t_fdf *fdf, int x0, int z0)
{
	vector->x = (x0 * cosf(ft_toradian(fdf->rotate.y))
			- z0 * sinf(ft_toradian(fdf->rotate.y)) + vector->y);
	vector->z = (-x0 * sinf(ft_toradian(fdf->rotate.y))
			+ z0 * cosf(ft_toradian(fdf->rotate.y)) + vector->y);
}

//ANCHOR - Rotate Z
void	ft_rotate_z(t_vector *vector, t_fdf *fdf, int x0, int y0)
{
	vector->x = (x0 * cosf(ft_toradian(fdf->rotate.z))
			- y0 * sinf(ft_toradian(fdf->rotate.z)) + vector->z);
	vector->y = (x0 * sinf(ft_toradian(fdf->rotate.z))
			+ y0 * cosf(ft_toradian(fdf->rotate.z))+ vector->z);
}


//ANCHOR - Rotate
void	ft_rotate(t_vector *vector, t_fdf *fdf)
{
	float	x0;
	float	y0;
	float	z0;

	if (!vector || !fdf)
		return ;
	x0 = vector->x;
	y0 = vector->y;
	z0 = vector->z;
	if (fdf->angle == 1)
		ft_rotate_x(vector, fdf, y0, z0);
	else
		ft_rotate_y(vector, fdf, x0, z0);
	//ft_rotate_z(vector, fdf, x0, y0);
}

//ANCHOR - Angle init
void	ft_angleinit(t_vector *vector, t_fdf *fdf)
{
	(void)vector;
	fdf->rotate.x = 30;
	fdf->rotate.y = 60;
	fdf->rotate.z = 90;
}
//!SECTION

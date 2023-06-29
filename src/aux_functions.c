/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/29 20:54:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Aux Function
//ANCHOR - Error handling
void	ft_exception(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

//ANCHOR - to radian
float	ft_toradian(int angle)
{
	return ((angle * M_PI) / 180);
}

//ANCHOR - To integer
int	ft_toint(float num)
{
	return ((int)roundf(num));
}

//ANCHOR - Center 
void	ft_tocenter(t_vector *vector, t_fdf *fdf)
{
	vector->x -= fdf->mid_v.x;
	vector->y -= fdf->mid_v.y;
	vector->z -= fdf->mid_v.z;
}

//ANCHOR - Get mid point
void	ft_get_midpoint(t_fdf *fdf, t_matrix *matrix)
{
	int	midx;
	int	midy;

	midx = round(matrix->length / 2);
	midy = round(matrix->height / 2);
	fdf->mid_v.x = ft_toint(matrix->vector[midy][midx].x);
	fdf->mid_v.y = ft_toint(matrix->vector[midy][midx].y);
	fdf->mid_v.z = ft_toint(matrix->vector[midy][midx].z);
}
//!SECTION

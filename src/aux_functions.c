/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/04 14:52:54 by yzaytoun         ###   ########.fr       */
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
float	ft_toradian(double angle)
{
	return ((angle * M_PI) / 180);
}

//ANCHOR - To integer
int	ft_toint(float num)
{
	return ((int)roundf(num));
}

//ANCHOR - Get mid point
void	ft_get_midpoint(t_fdf *fdf, t_matrix *matrix)
{
	int	midx;
	int	midy;

	midx = round(matrix->length / 2);
	midy = round(matrix->height / 2);
	fdf->mid_v.x = matrix->vector[midy][midx].x;
	fdf->mid_v.y = matrix->vector[midy][midx].y;
	fdf->mid_v.z = matrix->vector[midy][midx].z;
}
//!SECTION

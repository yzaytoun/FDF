/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:27:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/01 19:46:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Transform

//ANCHOR - To positive
void	ft_topositive(t_matrix *matrix)
{
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			matrix->vector[matrix->count_y][matrix->count_x].x
				+= abs(matrix->min);
			matrix->count_x++;
		}
		matrix->count_y++;
	}

}

//ANCHOR - ISO Projection
void	ft_isoprojection(t_vector *vector)
{
	int	x0;
	int	y0;
	int	angle;

	if (!vector)
		return ;
	angle = 30;
	x0 = vector->x;
	y0 = vector->y;
	vector->x = x0 * cos(ft_toradian(angle)) - y0 * sin(ft_toradian(angle));
	vector->y = x0 * sin(ft_toradian(angle)) + y0 * cos(ft_toradian(angle));
}

//ANCHOR - Main func
void	ft_transform(t_matrix *matrix, void (*func)(t_vector *))
{
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			(*func)(&matrix->vector[matrix->count_y][matrix->count_x]);
			matrix->count_x++;
		}
		matrix->count_y++;
	}
}

//!SECTION 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:06:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 19:22:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Apply Aux
//ANCHOR - Add color
void	ft_addcolor(t_vector *vector, t_fdf *fdf)
{
	if (vector->color == WHITE && vector->z > fdf->distance_z / 2)
		vector->color = RED_COLOR;
	else if (vector->color == WHITE && vector->z > fdf->distance_z)
		vector->color = BLUE_COLOR;
}
//!SECTION
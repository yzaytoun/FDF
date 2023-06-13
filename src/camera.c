/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:16:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/13 20:26:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Camera

//ANCHOR - Translate
void	ft_translate(t_vector *vector, t_fdf *fdf)
{
	if (fdf->flags.operation == ADD)
	{
		vector->x += fdf->flags.translate;
		vector->y += fdf->flags.translate;
		vector->z += fdf->flags.translate;
	}
	else if (fdf->flags.operation == SUB)
	{
		vector->x -= fdf->flags.translate;
		vector->y -= fdf->flags.translate;
		vector->z -= fdf->flags.translate;
	}
}

//ANCHOR - Dimensions to Camera
void	ft_dimcamera(t_vector *vector, t_fdf *fdf)
{
	if (!vector || !fdf)
		return ;
	fdf->flags.operation = SUB;
	ft_translate(vector, fdf);
	ft_matmult()
}

//!SECTION
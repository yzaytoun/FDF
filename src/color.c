/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:08:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/06 21:18:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Colors
//NOTE - WORK IN PROGRESS
static double	ft_getcolor(double color, int key)
{
	if (key == RED)
		return (color >> RED & 0xFF);
	else if (key == BLUE)
		return (color & 0xFF);
	else if (key == GREEN)
		return (color >> GREEN & 0xFF);
}

//ANCHOR - Color Interpolation
static int	ft_interpolate(t_color *color1, t_color *color2)
{
	
}

//ANCHOR - Main Function get color
void	ft_colorgradient(t_fdf *fdf)
{
	t_color	color1;
	t_color	color2;

	color1.red = ft_getcolor(fdf->v0.color, RED);
	color1.blue = ft_getcolor(fdf->v0.color, BLUE);
	color1.green = ft_getcolor(fdf->v0.color, GREEN);
	color2.red = ft_getcolor(fdf->v1.color, RED);
	color2.blue = ft_getcolor(fdf->v1.color, BLUE);
	color2.green = ft_getcolor(fdf->v1.color, GREEN);
	
}

//!SECTION
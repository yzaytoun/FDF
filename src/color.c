/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:08:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/08 16:09:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Colors
//ANCHOR - Get Percentage
static double	ft_get_percentage(double len, double dist)
{
	if (len == 0)
		return (1.0);
	else
		return (dist / len);
}

//ANCHOR - Get color value
static int	ft_getcolor(double fullcolor, int key)
{
	if (key == RED)
		return ((int)fullcolor >> RED & 0xFF);
	else if (key == GREEN)
		return ((int)fullcolor >> GREEN & 0xFF);
	else if (key == BLUE)
		return ((int)fullcolor & 0xFF);
	return (0);
}

//ANCHOR - Extract Color
static t_color	ft_extract_rbg(double fullcolor)
{
	t_color	color;

	color.red = ft_getcolor(fullcolor, RED);
	color.blue = ft_getcolor(fullcolor, BLUE);
	color.green = ft_getcolor(fullcolor, GREEN);
	return (color);
}

//ANCHOR - Color Interpolation
static t_color	ft_interpolate(t_color color1, t_color color2,
	double percentage)
{
	t_color	color;

	color.red = (1 - percentage) * color1.red + percentage * color2.red;
	color.green = (1 - percentage) * color1.green + percentage * color2.green;
	color.blue = (1 - percentage) * color1.blue + percentage * color2.blue;
	return (color);
}

//ANCHOR - Main Function get color
int	ft_get_colorgradient(t_fdf *fdf, int p_start, int p_end, int p_current)
{
	t_color	color1;
	t_color	color2;
	t_color	newcolor;
	double	percentage;

	percentage = ft_get_percentage(p_end - p_start, p_current - p_start);
	color1 = ft_extract_rbg(fdf->v0.color);
	color2 = ft_extract_rbg(fdf->v1.color);
	newcolor = ft_interpolate(color1, color2, percentage);
	return ((newcolor.red << 16) | (newcolor.green << 8) | newcolor.blue);
}
//!SECTION
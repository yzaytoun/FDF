/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/22 18:54:15 by yzaytoun         ###   ########.fr       */
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

//ANCHOR - get min number in map
int	ft_mapmin(t_map *map)
{
	int		min;
	t_map	*node;

	if (map == NULL)
		return (0);
	node = map;
	min = node->min;
	while (node != NULL)
	{
		if (min > node->min)
			min = node->min;
		node = node->next;
	}
	return (min);
}

//ANCHOR - to radian
double	ft_toradian(double degree)
{
	return ((degree * M_PI) / 180);
}

//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_point *point)
{
	mlx_string_put(window->mlx, window->win, 1, 1, 0xFFFF00,
		ft_strjoin("Width: ", ft_itoa(point->imagelength / point->scale)));
	mlx_string_put(window->mlx, window->win, 1, 15, 0xFFFF00,
		ft_strjoin("Height: ", ft_itoa(point->imageheight / point->scale)));
	mlx_string_put(window->mlx, window->win, 1, 30, 0xFFFF00,
		ft_strjoin("Scale: ", ft_itoa((int)point->scale)));
}
//!SECTION

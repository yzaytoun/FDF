/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/10 16:47:18 by yzaytoun         ###   ########.fr       */
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
void	ft_toradian(t_vector *angle)
{
	angle->x = (angle->x * M_PI) / 180;
	angle->y = (angle->y * M_PI) / 180;
	angle->z = (angle->z * M_PI) / 180;
}

//ANCHOR - To integer
int	ft_toint(float num)
{
	return ((int)roundf(num));
}

//!SECTION

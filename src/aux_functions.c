/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/18 20:56:48 by yzaytoun         ###   ########.fr       */
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

//!SECTION

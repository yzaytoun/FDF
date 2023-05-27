/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:59:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/27 20:00:16 by yzaytoun         ###   ########.fr       */
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

//ANCHOR New map node
t_map	*ft_new_mapnode(int *x, int y, int *color, int width)
{
	t_map	*node;

	node = ft_calloc(1, sizeof(t_map));
	if (!node)
		return (NULL);
	node->x = ft_copyarr(x, width);
	node->y = y;
	node->color = ft_copyarr(color, width);
	node->width = width;
	node->min = ft_arraymin(node->x, width);
	node->next = NULL;
	return (node);
}

//ANCHOR - Copy map
t_map	*ft_copymap(t_map *map)
{
	t_map	*copy;

	if (!map)
		return (NULL);
	else
	{
		copy = ft_new_mapnode(map->x, map->y, map->color, map->width);
		copy->next = ft_copymap(map->next);
	}
	return (copy);
}

//!SECTION

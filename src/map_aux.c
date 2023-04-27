/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:46:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/27 20:28:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map AUX
//FIXME - To be deleted -> Printer
void	ft_printmap(t_map *map)
{
	t_map	*node;
	int		index;

	index = 0;
	if (map == NULL || map->size == 0)
		return ;
	node = map;
	while (node != NULL)
	{
		index = 0;
		printf("x = ");
		while (index < map->size)
		{
			printf("%d\r", node->x[index]);
			index++;
		}

		printf("\t index = %d", node->y);
		node = node->next;
	}
}

//ANCHOR - From string array to integer array
int	*ft_arr(char **str, int *size)
{
	int	index;
	int	*arr;

	arr = ft_calloc(ft_strlen_arr(str), sizeof(int));
	if (!arr)
		return (0);
	index = 0;
	if (!str || *str == NULL)
		return (0);
	while (str[index])
	{
		if (ft_isdigitstr(str[index]) == TRUE)
			arr[index] = ft_atoi(str[index]);
		++index;
	}
	*size = index;
	return (arr);
}
//!SECTION
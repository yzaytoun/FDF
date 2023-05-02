/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:46:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/02 20:30:30 by yzaytoun         ###   ########.fr       */
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
		while (index < node->size)
		{
			printf("%d ", node->x[index]);
			index++;
		}

		printf("\t\t index = %d\n", node->y);
		node = node->next;
	}
}
//FIXME - Finish Atoi base
//ANCHOR - Get color
static int	ft_getcolor(char *str, t_map *map, int index)
{
	int	pos;

	if (!str || !map)
		return (FALSE);
	pos = ft_charpos(str, ',');
	map->color = ft_atoibase((ft_strchr(str, ',') + 1), 16);
	if (ft_isdigitstr(ft_substr(str, 0, pos)) == TRUE)
		map->x[index] = ft_atoi(ft_substr(str, 0, pos));
	else
		return (FALSE);
	return (TRUE);
}

//ANCHOR - From string array to integer array
int	ft_readarr(char **str, t_map **map)
{
	int	index;

	index = 0;
	if (!str || *str == NULL)
		return (FALSE);
	(*map)->x = ft_calloc(ft_strlen_arr(str), sizeof(int));
	if (!(*map)->x)
		return (FALSE);
	(*map)->color = NULL;
	while (str[index])
	{
		if (ft_findchr(str[index], ',') == TRUE)
		{
			if (ft_getcolor(str[index], *map, index) != TRUE)
				ft_exception("Invalid Map");
		}
		else if (ft_isdigitstr(str[index]) == TRUE)
			(*map)->x[index] = ft_atoi(str[index]);
		else
			ft_exception("Invalid Map");
		++index;
	}
	(*map)->size = index;
	return (TRUE);
}

//ANCHOR - Map Reverse
void	ft_mapreverse(t_map **map)
{
	t_map	*next;
	t_map	*current;
	t_map	*prev;

	next = NULL;
	prev = NULL;
	current = (*map);
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*map) = prev;
}

//!SECTION
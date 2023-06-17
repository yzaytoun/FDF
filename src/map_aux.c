/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:46:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/17 15:14:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map AUX
//ANCHOR - Get color
static int	ft_getcolor(char *str, t_map *map, int index)
{
	int	pos;

	if (!str || !map)
		return (FALSE);
	pos = ft_charpos(str, ',');
	map->color[index] = ft_atoibase((ft_strchr(str, ',') + 1), 16);
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
	(*map)->x = ft_createarray(ft_strlen_arr(str));
	(*map)->color = ft_createarray(ft_strlen_arr(str));
	if (!(*map)->color || !(*map)->x)
		ft_exception("Failed to create int array");
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
	(*map)->width = index;
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

//ANCHOR - Color Flood
void	ft_colorflood(int **array, int size, int color)
{
	int	index;

	index = 0;
	if (!*array || !size || !color || size == 0)
		return ;
	while (index < size)
	{
		if ((*array)[index] == 0)
			(*array)[index] = color;
		index++;
	}
}

//!SECTION

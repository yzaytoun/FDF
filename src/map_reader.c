/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:12:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/10 20:09:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
//SECTION - Map Reader
//ANCHOR - Create Map
int	ft_createmap(t_map **map, char *x, int y)
{
	t_map	*new;
	char	**buff;

	new = ft_calloc(sizeof(t_map), 1);
	if (!new)
		return (FALSE);
	buff = ft_split(x, ' ');
	if (ft_readarr(buff, &new) == FALSE)
		return (FALSE);
	ft_colorflood(&new->color, new->width, 0xFFFFFF);
	new->y = y;
	new->next = (*map);
	(*map) = new;
	ft_freestr_arr(buff);
	return (TRUE);
}

//ANCHOR - Read File
char	*ft_readfile(char **av)
{
	int		fd;
	char	*line;
	char	*buff;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = "";
	buff = ft_calloc(1, sizeof(char));
	if (!buff)
	{
		close(fd);
		return (NULL);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			buff = ft_strjoin_get(buff, line);
		free(line);
	}
	close(fd);
	return (buff);
}

//ANCHOR - Read Map
t_map	*ft_readmap(char **av, int *height)
{
	t_map	*map;
	char	**buff;

	map = NULL;
	if (ft_strnstr(av[1], ".fdf", ft_strlen(av[1])) == NULL)
		return (NULL);
	buff = ft_split(ft_readfile(av), '\n');
	if (buff == NULL)
		return (NULL);
	while (buff[*height] != NULL)
	{
		if (ft_createmap(&map, buff[*height], *height) != TRUE)
		{
			ft_freestr_arr(buff);
			ft_deletemap(&map);
			ft_exception("Read map");
		}
		*height += 1;
	}
	ft_freestr_arr(buff);
	ft_mapreverse(&map);
	return (map);
}

//ANCHOR - Free Map
void	ft_deletemap(t_map **map)
{
	t_map	*node;

	if (map == NULL)
		return ;
	node = (*map);
	while (node != NULL)
	{
		(*map) = (*map)->next;
		free(node->x);
		free(node->color);
		free(node);
		node = (*map);
	}
	free((*map));
}

//ANCHOR - Check Map
int	ft_checkmap(t_map *map)
{
	t_map	*node;

	node = map;
	if (node->next != NULL)
	{
		if (node->width != node->next->width)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

//!SECTION

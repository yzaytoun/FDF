/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:12:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/22 18:40:42 by yzaytoun         ###   ########.fr       */
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
	new->x = ft_arr(buff);
	if (new->x == FALSE)
	{
		free(new);
		ft_freestr_arr(buff);
		return (FALSE);
	}
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
t_map	*ft_readmap(char **av)
{
	t_map	*map;
	char	**buff;
	int		index;

	map = NULL;
	index = 0;
	if (ft_strnstr(av[1], ".fdf", ft_strlen(av[1])) == NULL)
		return (NULL);
	buff = ft_split(ft_readfile(av), '\n');
	while (buff[index] != NULL)
	{
		if (ft_createmap(&map, buff[index], index) != TRUE)
		{
			ft_putstr_fd("Error\n", 2);
			ft_freestr_arr(buff);
			ft_deletemap(&map);
			return (NULL);
		}
		index++;
	}
	ft_freestr_arr(buff);
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
		free(node);
		node = (*map);
	}
	free((*map));
}

//!SECTION
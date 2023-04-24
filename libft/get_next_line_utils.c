/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:55:39 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 20:50:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*join;
	size_t	size_1;
	size_t	size_2;

	size_1 = 0;
	size_2 = 0;
	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	while (s1[size_1] != '\0')
		++size_1;
	while (s2[size_2] != '\0')
		++size_2;
	join = ft_calloc(sizeof(char), size_1 + size_2 + 1);
	if (!join)
		return (NULL);
	ft_memmove(join, s1, size_1);
	ft_memmove(join + size_1, s2, size_2);
	join[size_1 + size_2] = '\0';
	free(s1);
	return (join);
}

char	*ft_get_line(char **str, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!*str || n == 0)
		return (NULL);
	dest = ft_calloc(sizeof(char), n + 1);
	if (!dest)
		return (NULL);
	while ((*str)[i] != '\0' && i < n)
	{
		dest[i] = (*str)[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_next(char *stat, size_t new_l, size_t len)
{
	char	*new_char;
	size_t	i;

	i = 0;
	if (!stat || new_l == 0 || len == 0)
	{
		free(stat);
		return (NULL);
	}
	new_char = ft_calloc(sizeof(char), ((len - new_l) + 1));
	if (!new_char)
		return (NULL);
	while (stat[new_l + i] != '\0' && i < (len - new_l))
	{
		new_char[i] = stat[new_l + i];
		i++;
	}
	new_char[i] = '\0';
	free(stat);
	return (new_char);
}

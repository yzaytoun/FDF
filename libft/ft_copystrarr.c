/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copystrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:08:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/22 18:02:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copystrarr(char **s, int input, int *count)
{
	char	**newstr;
	int		i;
	int		index;

	index = 0;
	if (input == STDIN_FILENO)
		i = 1;
	else
		i = 0;
	if (!s || *s == NULL)
		return (NULL);
	newstr = ft_calloc(sizeof(char *), ft_strlen_arr(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[i] != NULL)
	{
		newstr[index] = ft_strdup(s[i]);
		++i;
		++index;
	}
	*count = index;
	newstr[index] = NULL;
	return (newstr);
}

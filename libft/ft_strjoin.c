/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:09:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/01 14:21:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full_string;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	full_string = (char *)malloc(sizeof(char) * total_len);
	if (!full_string)
		return (NULL);
	ft_memmove(full_string, s1, ft_strlen(s1));
	ft_memmove(full_string + (ft_strlen(s1)), s2, ft_strlen(s2));
	full_string[total_len - 1] = '\0';
	return (full_string);
}

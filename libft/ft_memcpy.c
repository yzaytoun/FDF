/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:24:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/30 19:49:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	if (!dst || !src || !n)
		return (NULL);
	dest = (char *)dst;
	source = (const char *)src;
	if ((dst == src) || n == 0)
		return (dst);
	while (n--)
			dest[n] = source[n];
	return (dst);
}

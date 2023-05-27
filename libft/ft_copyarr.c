/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:05:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/27 18:12:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_copyarr(int	*arr, int size)
{
	int		*copy;
	int		count;

	count = 0;
	if (!arr)
		return (0);
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (0);
	while (count < size)
	{
		copy[count] = arr[count];
		++count;
	}
	return (copy);
}

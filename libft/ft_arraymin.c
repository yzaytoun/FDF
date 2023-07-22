/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:54:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/17 17:45:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arraymin(int *arr, int size)
{
	int	min;
	int	index;

	index = 0;
	if (!arr || size == 0)
		return (0);
	min = *arr;
	while (index < size)
	{
		if (min > arr[index])
			min = arr[index];
		++index;
	}
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:59:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/11 19:27:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_createarray(int size)
{
	int	*array;

	if (!size)
		return ((int *)-1);
	if (size == 0)
		size = 1;
	array = ft_calloc(size, sizeof(int));
	if (!array)
		return ((int *)-1);
	return (array);
}

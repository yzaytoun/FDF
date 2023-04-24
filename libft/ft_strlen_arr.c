/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:03:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/22 18:05:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_arr(char **strarr)
{
	int	i;

	i = 0;
	if (!strarr)
		return (i);
	else
	{
		while (strarr[i] != NULL)
			++i;
	}
	return (i);
}

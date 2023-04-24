/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:46:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/22 18:37:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map AUX
//ANCHOR - From string array to integer array
int	*ft_arr(char **str)
{
	int	index;
	int	*arr;

	arr = ft_calloc(ft_strlen_arr(str), sizeof(int));
	if (!arr)
		return (0);
	index = 0;
	if (!str || *str == NULL)
		return (0);
	while (str[index])
	{
		if (ft_isdigitstr(str[index]) == TRUE)
			arr[index] = ft_atoi(str[index]);
		++index;
	}
	return (arr);
}
//!SECTION
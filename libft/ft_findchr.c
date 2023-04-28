/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:48:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/28 18:56:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (FALSE);
	while (str[i])
	{
		if (str[i] == c)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

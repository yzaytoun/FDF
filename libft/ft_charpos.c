/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:04:27 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/28 19:04:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charpos(const char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (0);
}

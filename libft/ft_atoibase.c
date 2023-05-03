/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:29:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/03 19:35:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkdigit(char c, int base)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	while (i < base)
	{
		if (str[i] == c || ft_toupper(str[i]) == c)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

static int	ft_getbase(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

static int	ft_convert(const char *str, int base, int index)
{
	int		result;

	result = 0;
	while (str[index] != '\0' && ft_checkdigit(str[index], base) != 0)
	{
		if (str[index] == '0'
			&& (str[index + 1] == 'x' || str[index + 1] == 'X'))
			index += 2;
		result = (result * base) + ft_getbase(str[index]);
		++index;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	else
		return (result);
}

int	ft_atoibase(const char *str, int base)
{
	int		index;
	int		sign;

	if (!str || !base)
		return (0);
	sign = 1;
	index = 0;
	while (!ft_isprint(str[index]) && str[index] != '\0')
		++index;
	if (index > 0)
	{
		if (str[index - 1] == '-')
			sign = -1;
	}
	return (ft_convert(str, base, index) * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:51:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/02 20:02:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tobinary(char *str)
{
	int	bit;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		result = (result * 2) + (str[i++] - '0');
}

int	ft_tohex(char *str)
{

}

int	ft_toocta(char *str)
{

}

int	ft_convert(char *str, int base)
{
	int	result;

	result = 0;
	if (str == NULL)
		return (0);
	if (base == 2)
		result = ft_tobinary(str);
	else if (base == 16)
		result = ft_tohex(str);
	else if (base == 8)
		result = ft_toocta(str);
	else
	{
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i++] - '0');
	}
	return (result);
}

int	ft_atoibase(const char *str, int base)
{
	int		i;
	int		sign;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] != '\0' && str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (ft_convert(str) * sign);
}

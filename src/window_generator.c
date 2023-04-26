/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:02:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/26 20:25:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*ft_window(int action)
{
	void	*mlx;

	if (action == 'CREATE')
	{
		mlx = mlx_init();
		if (mlx == NULL)
			return (NULL);
	}
	else if (action == 'DESTROY')
	{
		//Destroy
	}
	return (mlx);
}

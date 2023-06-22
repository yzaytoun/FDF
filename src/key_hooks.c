/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:32:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/22 20:01:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Key Events
//ANCHOR - Close Window
static int	ft_printkeys(int keycode, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (keycode == KEY_ESCAPE)
	{
		//mlx_destroy_image(window->mlx, window->win);
		mlx_destroy_window(params->window->mlx, params->window->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13)
		params->fdf->angle.z += ft_toradian(20);
	printf("keycode = %i\n", keycode);
	return (TRUE);
}
/*
static int	ft_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 13)
		fdf->angle.z *= 10;
	return (TRUE);
}
*/

//ANCHOR - Main Func
void	ft_keyhooks(t_params *params)
{
	mlx_key_hook(params->window->win, ft_printkeys, params);
}
//!SECTION

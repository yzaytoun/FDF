/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:32:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/02 19:51:37 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Key Events
//ANCHOR - Magnify
static void	ft_keymagnify(int keycode, t_params *params)
{
	if (keycode == 78)
	{
		params->fdf->distance_x -= 1;
		params->fdf->distance_y -= 1;
	}
	else if (keycode == 69)
	{
		params->fdf->distance_x += 1;
		params->fdf->distance_y += 1;
	}
}

//ANCHOR - Key Move
static void	ft_keymove(int keycode, t_params *params)
{
	if (keycode == 126)
		params->fdf->flags.translation_y -= 10;
	else if (keycode == 125)
		params->fdf->flags.translation_y += 10;
	else if (keycode == 123)
		params->fdf->flags.translation_x -= 10;
	else if (keycode == 124)
		params->fdf->flags.translation_x += 10;
}

//ANCHOR - Key rotate
static void	ft_keyrotate(int keycode, t_params *params)
{
	if (keycode == 2)
		params->fdf->angle.z += ft_toradian(20);
	else if (keycode == 0)
		params->fdf->angle.z -= ft_toradian(20);
	else if (keycode == 13)
		params->fdf->angle.x += ft_toradian(20);
	else if (keycode == 1)
		params->fdf->angle.x -= ft_toradian(20);
	else if (keycode == 14)
		params->fdf->angle.y += ft_toradian(20);
	else if (keycode == 12)
		params->fdf->angle.y -= ft_toradian(20);
}

//ANCHOR - Main Func
int	ft_keyhooks(int keycode, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(params->window->mlx, params->window->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode <= 126 && keycode >= 123)
		ft_keymove(keycode, params);
	else if (keycode >= 0 && keycode <= 14)
		ft_keyrotate(keycode, params);
	else if (keycode == 69 || keycode == 78)
		ft_keymagnify(keycode, params);
	printf("keycode = %i\n", keycode);
	return (TRUE);
}
//!SECTION

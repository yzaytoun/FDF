/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:32:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/03 16:18:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Key Events
//ANCHOR - Magnify
static void	ft_keymagnify(int keycode, t_params *params)
{
	if (keycode == 78)
	{
		params->fdf->distance_x -= 5;
		params->fdf->distance_y -= 5;
	}
	else if (keycode == 69)
	{
		params->fdf->distance_x += 5;
		params->fdf->distance_y += 5;
	}
	else if (keycode == 6)
		params->fdf->distance_z += 1;
	else if (keycode == 7)
		params->fdf->distance_z -= 1;
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
	else if (keycode == 88)
		params->fdf->flags.offset += 10;
	else if (keycode == 86)
		params->fdf->flags.offset -= 10;
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
	else if (keycode == 34)
		params->fdf->flags.iso = TRUE;
	else if (keycode == 31)
		params->fdf->flags.iso = FALSE;
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
	if ((keycode <= 126 && keycode >= 123) || keycode == 86 || keycode == 88)
		ft_keymove(keycode, params);
	else if (keycode == 15)
		params->fdf->flags.reset = TRUE;
	else if (keycode == 69 || keycode == 78 || keycode == 6 || keycode == 7)
		ft_keymagnify(keycode, params);
	else if (keycode >= 0 && keycode <= 40)
		ft_keyrotate(keycode, params);
	printf("keycode = %i\n", keycode);
	return (TRUE);
}
//!SECTION

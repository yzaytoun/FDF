/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 20:29:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Events
//ANCHOR - Mouse Motion tracker
static int	ft_motiontracker(int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (params->hook->button_1_press == TRUE)
	{
		params->fdf->flags.translation_y = y;
		params->fdf->flags.translation_x = x;
	}
	if (params->hook->button_2_press == TRUE
		&& params->hook->button_1_press == TRUE && params->hook->y > y)
		params->fdf->angle.x += ft_toradian(1);
	if (params->hook->button_2_press == TRUE
		&& params->hook->button_1_press == TRUE && params->hook->y < y)
		params->fdf->angle.x -= ft_toradian(1);
	if (params->hook->button_2_press == TRUE && params->hook->x > x)
		params->fdf->angle.z += ft_toradian(1);
	if (params->hook->button_2_press == TRUE && params->hook->x < x)
		params->fdf->angle.z -= ft_toradian(1);
	return (EXIT_SUCCESS);
}

static int	ft_buttonrelease(int button, int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	params->hook->x = x;
	params->hook->y = y;
	if (button == 1)
		params->hook->button_1_press = 0;
	if (button == 2)
		params->hook->button_2_press = 0;
	return (EXIT_SUCCESS);
}

//ANCHOR - Main Func
void	ft_mousehooks(t_params *params)
{
	mlx_hook(params->window->win, 17, 0, ft_closewindow, params);
	mlx_hook(params->window->win, 5, 1L << 3, ft_buttonrelease, params);
	mlx_hook(params->window->win, 6, 1L << 6, ft_motiontracker, params);
	mlx_mouse_hook(params->window->win, ft_mousebutton, params);
}

//!SECTION

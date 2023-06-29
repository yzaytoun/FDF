/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/29 19:55:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Events
//ANCHOR - Mouse Motion tracker
static int	ft_motiontracker(int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (params->hook->buttonpress == 1)
	{
		params->fdf->flags.translation_y = y - params->fdf->margin;
		params->fdf->flags.translation_x = x - params->fdf->margin;
	}
	return (EXIT_SUCCESS);
}

static int	ft_buttonrelease(int button, int x, int y,void *param)
{
	t_params	*params;

	params = (t_params *)param;
	params->hook->x = x;
	params->hook->y = y;
	if (button == 1)
		params->hook->buttonpress = 0;
	return (EXIT_SUCCESS);
}

//ANCHOR - Main Func
void	ft_mousehooks(t_params *params)
{
	mlx_hook(params->window->win, 17, 0, ft_closewindow, params->window);
	mlx_hook(params->window->win, 5, 1L << 3, ft_buttonrelease, params);
	mlx_hook(params->window->win, 6, 1L << 6, ft_motiontracker, params);
	mlx_mouse_hook(params->window->win, ft_mousebutton, params);
}

//!SECTION

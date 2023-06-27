/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:31:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/27 21:12:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Hooks
//ANCHOR - Close Window
int	ft_closewindow(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
}

//ANCHOR - Mouse Magnify
static void	ft_mousemagnify(int button, t_params *params)
{
	if (button == 4)
	{
		params->fdf->distance_x -= 1;
		params->fdf->distance_y -= 1;
	}
	else if (button == 5)
	{
		params->fdf->distance_x += 1;
		params->fdf->distance_y += 1;
	}
}

//ANCHOR - Mouse Button
int	ft_mousebutton(int button, int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (button == 4 || button == 5)
		ft_mousemagnify(button, params);
	if (button == 1)
		params->hook->buttonpress = 1;
	printf("button = %d\t x = %d\t y = %d\n", button, x, y);
	return (TRUE);
}

//!SECTION
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:28:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/02 12:52:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Events
//ANCHOR - Close Window
static int	ft_closewindow(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	//mlx_destroy_image(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
}

//ANCHOR - Main Func
void	ft_mousehooks(t_window *window)
{
	mlx_hook(window->win, 17, 0, ft_closewindow, window);
	//mlx_mouse_hook(window->win, ft_mousebutton, NULL);
}

//!SECTION
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/17 15:31:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Events
//ANCHOR - Close Window
static int	ft_closewindow(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	//mlx_clear_image(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
}

static int	ft_mousebutton(int button, int x, int y)
{
	printf("button = %d\t x = %d\t y = %d\n", button, x, y);
	return (TRUE);
}


//ANCHOR - Main Func
void	ft_mousehooks(t_window *window)
{
	mlx_hook(window->win, 17, 0, ft_closewindow, window);
	mlx_mouse_hook(window->win, ft_mousebutton, NULL);
}

//!SECTION

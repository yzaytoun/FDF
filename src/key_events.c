/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:28:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/02 18:37:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Key Events
//ANCHOR - Close Window
static int	ft_closewindow(int keycode, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (keycode == KEY_ESCAPE)
	{
		//mlx_destroy_image(window->mlx, window->win);
		mlx_destroy_window(window->mlx, window->win);
	}
	exit(EXIT_SUCCESS);
}

//ANCHOR - Key =?
static int	ft_printkeys(int keycode)
{
	printf("keycode = %i\n", keycode);
	return (TRUE);
}

//ANCHOR - Main Func
void	ft_keyhooks(t_window *window)
{
	mlx_key_hook(window->win, ft_closewindow, window);
	mlx_key_hook(window->win, ft_printkeys, window);
}
//!SECTION
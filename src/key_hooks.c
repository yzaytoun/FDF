/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:32:02 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/17 18:02:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Key Events
//ANCHOR - Close Window
static int	ft_printkeys(int keycode, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (keycode == KEY_ESCAPE)
	{
		//mlx_destroy_image(window->mlx, window->win);
		mlx_destroy_window(window->mlx, window->win);
		exit(EXIT_SUCCESS);
	}
	printf("keycode = %i\n", keycode);
	return (TRUE);
}

//ANCHOR - Main Func
void	ft_keyhooks(t_window *window)
{
	mlx_key_hook(window->win, ft_printkeys, window);
}
//!SECTION

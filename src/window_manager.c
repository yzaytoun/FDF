/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:11:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/28 20:38:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Window Manager
//ANCHOR - Create Window
t_window	*ft_createwindow(t_map *map, char *title)
{
	t_window	*window;

	window = ft_calloc(sizeof(t_window), 1);
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (NULL);
	window->win = mlx_new_window(window->mlx,
			map->size * 100, map->y * 100, title);
	if (window->win == NULL)
		ft_exception("New Window");
	return (window);
}

//ANCHOR - Destroy Window
void	ft_destroywindow(t_window **window, t_map *map)
{
	ft_deletemap(&map);
	free((*window)->mlx);
	free((*window)->win);
	free(*window);
}

//ANCHOR - Run Window
void	ft_runwindow(t_window *window)
{
	ft_mousehooks(window);
	mlx_loop(window->mlx);
}
//!SECTION
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:11:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/08 18:04:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Window Manager
//ANCHOR - Create Window
t_window	*ft_createwindow(char *title, int width, int height, int scale)
{
	t_window	*window;

	window = ft_calloc(sizeof(t_window), 1);
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (NULL);
	if (ft_strrchr(title, '/') == NULL)
		window->win
			= mlx_new_window(window->mlx, width * scale, height * scale, title);
	else
		window->win
			= mlx_new_window(window->mlx, width * scale, height * scale,
				ft_strrchr(title, '/') + 1);
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
	free((*window)->img);
	free((*window)->addr);
	free(*window);
}

//ANCHOR - Run Window
void	ft_windowloop(t_window *window, t_map *map, int height, int scale)
{
	t_point	*point;

	window->img
		= mlx_new_image(window->mlx, map->width * scale, height * scale);
	if (!window->img)
		return ;
	point = ft_calloc(1, sizeof(t_point));
	if (!point)
		return ;
	point->height = height;
	point->scale = scale;
	point->width = map->width;
	ft_drawmap(window, map, point);
	free(point);
	ft_mousehooks(window);
	ft_keyhooks(window);
	mlx_loop(window->mlx);
}
//!SECTION

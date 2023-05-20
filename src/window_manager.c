/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:11:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/20 19:16:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Window Manager
//ANCHOR - Point init
static void	ft_pointinit(t_point *point, t_map *map, int height, double scale)
{
	point->scale = scale;
	point->imagelength = map->width * scale;
	point->imageheight = height * scale;
	point->distance_x = (point->imagelength / map->width) * scale;
	point->distance_y = (point->imageheight / height) * scale;
	if (point->imageheight > point->imagelength)
		point->margin = (point->imageheight / 10);
	else
		point->margin = (point->imageheight / 10);
	point->min = ft_mapmin(map);
}

//ANCHOR - Get Scale
static double	ft_getscale(int width, int height)
{
	if (width < 30 && height < 30)
		return (50);
	else if (width < MAX_HEIGHT && height < MAX_WIDTH)
		return (8);
	else if (width > 1000 || height > 1000)
		return (1);
	else
		return (2);
}

//ANCHOR - Create Window
t_window	*ft_createwindow(char *title, int width, int height)
{
	t_window	*window;
	double		scale;

	window = ft_calloc(sizeof(t_window), 1);
	if (!window)
		return (NULL);
	scale = ft_getscale(width, height);
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
void	ft_windowloop(t_window *window, t_map *map, int height)
{
	t_point	*point;
	int		scale;

	scale = ft_getscale(map->width, height);
	window->img
		= mlx_new_image(window->mlx, map->width * scale, height * scale);
	if (!window->img)
		return ;
	point = ft_calloc(1, sizeof(t_point));
	if (!point)
		return ;
	ft_pointinit(point, map, height, scale);
	if (point->min < 0)
		ft_normalizemap(map, point);
	ft_drawmap(window, map, point);
	free(point);
	ft_mousehooks(window);
	ft_keyhooks(window);
	mlx_loop(window->mlx);
}
//!SECTION

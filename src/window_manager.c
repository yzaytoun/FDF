/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:11:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/26 19:54:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Window Manager
//ANCHOR - Point init
static void	ft_pointinit(t_point *point, t_map *map, int height, double scale)
{
	point->scale = scale;
	point->imagelength = (map->width * scale);
	point->imageheight = (height * scale);
	point->distance_x = (point->imagelength / map->width);
	point->distance_y = (point->imageheight / height);
	if (point->imageheight > point->imagelength)
		point->margin = (point->imageheight / 10);
	else
		point->margin = (point->imagelength / 10);
	point->min = ft_mapmin(map);
}

//ANCHOR - Get Scale
static double	ft_getscale(int width, int height)
{
	double	scale;

	if (!width || !height)
		return (0);
	scale = 0;
	if (width > height)
		scale = width;
	else
		scale = height;
	if (scale <= 25)
		scale = 50;
	else if (scale <= 50)
		scale = 10;
	else if (scale <= 100)
		scale = 5;
	else if (scale <= MAX_WIDTH)
		scale = 2;
	else
		scale = 1;
	return (scale);
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
			= mlx_new_window(window->mlx, scale * width, scale * height, title);
	else
		window->win
			= mlx_new_window(window->mlx, scale * width, scale * height,
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
		= mlx_new_image(window->mlx, scale * map->width, scale * height);
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

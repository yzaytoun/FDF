/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:11:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/03 12:12:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Window Manager
//ANCHOR - Point init
static void	ft_pointinit(t_fdf *fdf, t_map *map, int height, double scale)
{
	fdf->scale = scale;
	fdf->imagelength = (map->width * scale);
	fdf->imageheight = (height * scale);
	fdf->distance_x = (fdf->imagelength / map->width) / 2;
	fdf->distance_y = (fdf->imageheight / height) / 2;
	if (fdf->imageheight > fdf->imagelength)
		fdf->margin = (fdf->imageheight / 10);
	else
		fdf->margin = (fdf->imagelength / 10);
	fdf->min_x = ft_mapmin(map);
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
	t_fdf	*fdf;
	int		scale;

	scale = ft_getscale(map->width, height);
	window->img
		= mlx_new_image(window->mlx, scale * map->width, scale * height);
	if (!window->img)
		return ;
	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return ;
	ft_pointinit(fdf, map, height, scale);
	if (fdf->min_x < 0)
		ft_normalizemap(map, fabs(fdf->min_x));
	ft_drawmap(window, map, fdf);
	free(fdf);
	ft_mousehooks(window);
	ft_keyhooks(window);
	mlx_loop(window->mlx);
}
//!SECTION

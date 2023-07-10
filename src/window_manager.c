/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:11:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 20:42:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Window Manager
//ANCHOR - Point init
static void	ft_initfdf(t_fdf *fdf, t_map *map, int height)
{
	fdf->imagelength = (map->width * fdf->scale);
	fdf->imageheight = (height * fdf->scale);
	fdf->distance_x = (fdf->imagelength / map->width) / 3;
	fdf->distance_y = (fdf->imageheight / height) / 3;
	fdf->distance_z = fdf->scale / 4;
	if (fdf->imageheight > fdf->imagelength)
		fdf->margin = (fdf->imageheight / 10);
	else
		fdf->margin = (fdf->imagelength / 10);
	fdf->flags.translation_x = fdf->imagelength / 2;
	fdf->flags.translation_y = fdf->imageheight / 2;
	fdf->flags.translation_z = fdf->imageheight / 2;
	fdf->flags.iso = TRUE;
	fdf->flags.focal_distance = 1;
	fdf->isoangle = 30;
	fdf->angle.x = ft_toradian(60);
	fdf->angle.y = ft_toradian(220);
	fdf->angle.z = ft_toradian(120);
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
	if (scale <= 50)
		scale = 50;
	else if (scale <= 100)
		scale = 10;
	else if (scale <= 200)
		scale = 7;
	else if (scale <= MAX_WIDTH)
		scale = 2;
	else
		scale = 1;
	return (scale);
}

//ANCHOR - initiate struct
t_fdf	*ft_initstructs(t_window *window, t_map *map, int height)
{
	t_fdf	*fdf;

	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->scale = ft_getscale(map->width, height);
	ft_initfdf(fdf, map, height);
	ft_createimage(window, fdf);
	return (fdf);
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
		ft_exception("Error : New Window");
	return (window);
}

//ANCHOR - Destroy Window
void	ft_destroywindow(t_window **window, t_map *map)
{
	ft_deletemap(&map);
	if ((*window)->freed == FALSE)
	{
		free((*window)->mlx);
		free((*window)->win);
	}
	free((*window)->img);
	free((*window)->addr);
	free(*window);
}


//!SECTION

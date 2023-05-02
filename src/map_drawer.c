/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:12:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/02 19:45:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map Drawer
//ANCHOR - Put image
void	ft_putimg(t_window *window, t_map *map)
{
	(void)map;
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, 0, 0);
	printf("image = %s\n",mlx_get_data_addr(window->img, &window->bpp,
		&window->size, &window->endian));
	printf("pixel per bite = %d\n",  window->bpp);
	printf("line_size = %d\n",  window->size);
	printf("Endian = %d\n",  window->endian);
}

//ANCHOR - Draw Map
void	ft_drawmap(t_window *window, t_map *map)
{
	window->img = mlx_new_image(window->mlx, map->size, map->size);
	if (!window->img)
		return ;
	mlx_get_color_value(window->mlx, map->color);
	ft_putimg(window, map);
}

//!SECTION
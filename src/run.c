/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/22 20:25:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Run program
//ANCHOR - Create Image
void	ft_createimage(t_window *window, t_fdf *fdf)
{
	window->img = mlx_new_image(window->mlx, fdf->imagelength,
			fdf->imageheight);
	if (!window->img)
		return ;
	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
}

//ANCHOR - Run Window
void	ft_run(t_window *window, t_map *map, int height)
{
	t_params	*params;

	if (!map || !window)
		return ;
	params = ft_calloc(sizeof(t_params), 1);
	if (!params)
		return ;
	params->fdf = ft_initstructs(window, map, height);
	params->matrix
		= ft_creatematrix(params->fdf->imagelength / params->fdf->scale,
			params->fdf->imageheight / params->fdf->scale);
	if (!params->matrix)
		return ;
	params->window = window;
	params->map = map;
	ft_mousehooks(window);
	ft_keyhooks(params);
	mlx_loop_hook(window->mlx, ft_plotmap, params);
	mlx_loop(window->mlx);
}
//!SECTION

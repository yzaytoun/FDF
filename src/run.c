/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/28 21:46:36 by cxb0541          ###   ########.fr       */
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
	params->hook = ft_calloc(sizeof(t_hook), 1);
	if (!params->hook)
		return ;
	params->fdf->maxlen_x = params->fdf->imagelength;
	params->fdf->maxlen_y = params->fdf->imageheight - (2 * params->fdf->margin);
	ft_mousehooks(params);
	mlx_key_hook(params->window->win, ft_keyhooks, params);
	mlx_loop_hook(window->mlx, ft_plotmap, params);
	mlx_loop(window->mlx);
}
//!SECTION

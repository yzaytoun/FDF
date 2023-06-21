/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/21 21:20:51 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Run program

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
	params->matrix = ft_creatematrix(params->fdf->imagelength / params->fdf->scale,
			params->fdf->imageheight / params->fdf->scale);
	if (!params->matrix)
		return ;
	params->win = window;
	params->map = map;
	ft_fdfinit(params->fdf);
	ft_mousehooks(window);
	ft_keyhooks(params);
	mlx_loop_hook(window->mlx, ft_plotmap, params);
	mlx_loop(window->mlx);
}
//!SECTION

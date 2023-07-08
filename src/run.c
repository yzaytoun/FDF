/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/08 16:37:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Run program
//ANCHOR - Free All
static void	ft_free_all(t_params *params)
{
	mlx_destroy_window(params->window->mlx, params->window->win);
	ft_destroyvector(&params->matrix->vector, params->matrix->height);
	free(params->matrix);
	ft_destroywindow(&params->window, params->map);
	free(params->fdf);
	free(params->hook);
	free(params);
}

//ANCHOR - FDF AUX
static void	ft_fdf_aux(t_fdf *fdf)
{
	fdf->maxlen_x = fdf->imagelength;
	fdf->maxlen_y = fdf->imageheight - (2 * fdf->margin);
}

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
	ft_fdf_aux(params->fdf);
	ft_mousehooks(params);
	mlx_key_hook(params->window->win, ft_keyhooks, params);
	mlx_loop_hook(window->mlx, ft_plotmap, params);
	mlx_loop(window->mlx);
	ft_free_all(params);
}
//!SECTION

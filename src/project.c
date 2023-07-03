/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/03 11:12:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Project
//ANCHOR - Create Wireframe
static void	ft_createwireframe(t_vector *vector, t_fdf *fdf)
{
	ft_tocenter(vector, fdf);
	ft_rotate_z(vector, fdf);
	ft_rotate_y(vector, fdf);
	ft_rotate_x(vector, fdf);
	ft_translate(vector, fdf);
}

//ANCHOR - Reset image
static void	ft_resetimage(t_window *window, t_fdf *fdf)
{
	mlx_destroy_image(window->mlx, window->img);
	ft_createimage(window, fdf);
}

//ANCHOR - Project matrix
static void	ft_project_to_image(t_window *window, t_fdf *fdf, t_matrix *matrix,
	t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_matrix_map(map, &matrix);
	fdf->flags.operation = ADD;
	ft_apply(matrix, ft_scale, fdf);
	ft_get_midpoint(fdf, matrix);
	ft_apply(matrix, ft_createwireframe, fdf);
	ft_plot(window, fdf, matrix);
}

void
	ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix, t_map *map)
{
	ft_resetimage(window, fdf);
	ft_project_to_image(window, fdf, matrix, map);
	ft_closeshape(window, fdf, matrix);
}

//!SECTION
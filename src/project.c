/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 20:20:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Project
//ANCHOR - reset parameters
static void	ft_reset_parameters(t_fdf *fdf)
{
	fdf->distance_x = fdf->imagelength / ((fdf->imagelength * 3 / fdf->scale));
	fdf->distance_y = fdf->imageheight / ((fdf->imageheight * 3 / fdf->scale));
	fdf->flags.translation_x = fdf->imagelength / 2;
	fdf->flags.translation_y = fdf->imageheight / 2;
	fdf->flags.translation_z = fdf->imageheight / 2;
	fdf->distance_z = fdf->scale / 4;
	fdf->flags.iso = TRUE;
	fdf->flags.reset = FALSE;
	fdf->angle.x = ft_toradian(60);
	fdf->angle.y = ft_toradian(220);
	fdf->angle.z = ft_toradian(120);
	fdf->flags.focal_distance = 1;
}

//ANCHOR - Rotate Wireframe
static void	ft_rotatewireframe(t_vector *vector, t_fdf *fdf)
{
	ft_tocenter(vector, fdf);
	ft_rotate_z(vector, fdf);
	ft_rotate_y(vector, fdf);
	ft_rotate_x(vector, fdf);
}

//ANCHOR - Create Wireframe
static void	ft_createwireframe(t_vector *vector, t_fdf *fdf)
{
	ft_set_projection(vector, fdf);
	ft_magnify(vector, fdf);
	ft_translate(vector, fdf);
}

//ANCHOR - Reset image
static void	ft_resetimage(t_window *window, t_fdf *fdf)
{
	mlx_destroy_image(window->mlx, window->img);
	ft_createimage(window, fdf);
}

//ANCHOR - Project matrix
void	ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix,
	t_map *map)
{
	if (!window || !fdf || !matrix)
		return ;
	ft_resetimage(window, fdf);
	ft_matrix_map(map, &matrix);
	ft_apply(matrix, ft_scale, fdf);
	if (fdf->flags.addcolor == TRUE)
		ft_apply(matrix, ft_addcolor, fdf);
	ft_get_midpoint(fdf, matrix);
	if (fdf->flags.reset == TRUE)
		ft_reset_parameters(fdf);
	ft_apply(matrix, ft_rotatewireframe, fdf);
	ft_get_blackpoints(matrix);
	ft_apply(matrix, ft_createwireframe, fdf);
	ft_plot(window, fdf, matrix);
	ft_closeshape(window, fdf, matrix);
}
//!SECTION
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 19:09:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MATH_H		/*FDF MATH*/
# define FDF_MATH_H

# include "fdf_struct.h"
/*FUNCTIONS*/
//ANCHOR - AUX
void		ft_exception(char *str);
float		ft_toradian(double angle);
int			ft_toint(float num);
void		ft_get_midpoint(t_fdf *fdf, t_matrix *matrix);
void		ft_get_blackpoints(t_matrix *matrix);

//ANCHOR - Project
void		ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix,
				t_map *map);

//ANCHOR - Bresenham
void		ft_getcoord(t_fdf *fdf, int x, int y, int point);
void		ft_printheader(t_window *window, t_fdf *fdf);
void		ft_markpoint(t_fdf *fdf, t_matrix *matrix);
void		ft_bresenham(t_window *window, t_fdf *fdf);

//ANCHOR - Matrix
t_matrix	*ft_creatematrix(int dim_x, int dim_y);
void		ft_destroyvector(t_vector ***vector, int size);
void		ft_matrix_map(t_map *map, t_matrix **matrix);

//ANCHOR - Apply
void		ft_apply(t_matrix *matrix, void (*func)(t_vector *, t_fdf *),
				t_fdf *fdf);
void		ft_tocenter(t_vector *vector, t_fdf *fdf);
void		ft_scale(t_vector *vector, t_fdf *fdf);
void		ft_translate(t_vector *vector, t_fdf *fdf);
void		ft_magnify(t_vector *vector, t_fdf *fdf);

//ANCHOR - Apply AUX
void		ft_addcolor(t_vector *vector, t_fdf *fdf);

//ANCHOR - Rotate
void		ft_set_projection(t_vector *vector, t_fdf *fdf);
void		ft_rotate_y(t_vector *vector, t_fdf *fdf);
void		ft_rotate_z(t_vector *vector, t_fdf *fdf);
void		ft_rotate_x(t_vector *vector, t_fdf *fdf);

//ANCHOR - Plot
void		ft_closeshape(t_window *window, t_fdf *fdf, t_matrix *matrix);
void		ft_plot(t_window *window, t_fdf *fdf, t_matrix *matrix);
int			ft_plotmap(void *param);

//ANCHOR - color
int			ft_get_colorgradient(t_fdf *fdf, int p_start,
				int p_end, int p_current);

#endif 					/*END FDF_MATH*/
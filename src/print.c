/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:29:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/11 10:47:08 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Print
#define GET_VARIABLE_NAME(Variable) (#Variable)
//FIXME - To be deleted
void	ft_printmatrix(t_matrix *matrix)
{
	if (!matrix || !matrix->vector)
		return ;
	matrix->count_x = 0;
	matrix->count_y = 0;
	printf("Matrix Name : %s\n", GET_VARIABLE_NAME(matrix));
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			printf("(%.0f, %.0f, %.0f)\t",
				matrix->vector[matrix->count_y][matrix->count_x].x,
				matrix->vector[matrix->count_y][matrix->count_x].y,
				matrix->vector[matrix->count_y][matrix->count_x].z);
			++matrix->count_x;
		}
		printf("\n");
		++matrix->count_y;
	}

}

//ANCHOR - To be deleted
void	ft_printfdf(t_fdf *fdf)
{
	ft_printf("\nParameters:\n");
	ft_printf("\
	*Margin = %i\n\
	*Distance_x = %i\n\
	*Distance_y = %i\n\
	*Imagelength = %i\n\
	*Imageheight = %i\n",
		fdf->margin, fdf->distance_x, fdf->distance_y, fdf->imagelength,
		fdf->imageheight);
}

//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_fdf *fdf)
{
	mlx_string_put(window->mlx, window->win, 1, 1, 0xFFFF00,
		ft_strjoin("Width: ", ft_itoa(fdf->imagelength / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 15, 0xFFFF00,
		ft_strjoin("Height: ", ft_itoa(fdf->imageheight / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 30, 0xFFFF00,
		ft_strjoin("Scale: ", ft_itoa((int)fdf->scale)));
}

//!SECTION
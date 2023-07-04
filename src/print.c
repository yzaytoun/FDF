/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:29:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/04 17:31:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Print
//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_fdf *fdf)
{
	mlx_string_put(window->mlx, window->win, 1, 1, 0xFFFF00,
		ft_strjoin("Width: ", ft_itoa(fdf->imagelength / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 15, 0xFFFF00,
		ft_strjoin("Height: ", ft_itoa(fdf->imageheight / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 30, 0xFFFF00,
		ft_strjoin("Scale: ", ft_itoa((int)fdf->scale)));
	mlx_string_put(window->mlx, window->win, fdf->imagelength / 2,
		1, 0xFFFF00, "Rotate X: W/S");
	mlx_string_put(window->mlx, window->win, fdf->imagelength / 2,
		15, 0xFFFF00, "Rotate Z: D/A");
	mlx_string_put(window->mlx, window->win, fdf->imagelength / 2,
		30, 0xFFFF00, "Spin: M");
}

//!SECTION
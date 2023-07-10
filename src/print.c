/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:29:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 21:04:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Print
//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_fdf *fdf)
{
	mlx_string_put(window->mlx, window->win, fdf->imagelength * 0.85,
		1, 0xFFFF00, "Rotate X: W/S");
	mlx_string_put(window->mlx, window->win, fdf->imagelength * 0.85,
		15, 0xFFFF00, "Rotate Z: D/A");
	mlx_string_put(window->mlx, window->win, fdf->imagelength * 0.85,
		30, 0xFFFF00, "Spin: M");
	mlx_string_put(window->mlx, window->win, fdf->imagelength * 0.45,
		1, 0xFFFF00, "Rotate Y: Q/E");
	mlx_string_put(window->mlx, window->win, fdf->imagelength * 0.45,
		15, 0xFFFF00, "Increment Z: Z/X");
	mlx_string_put(window->mlx, window->win, fdf->imagelength * 0.45,
		30, 0xFFFF00, "Add color: C");
}

//!SECTION
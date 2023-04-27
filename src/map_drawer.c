/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:12:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/27 19:38:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_map_drawer(t_window *window, t_map *map)
{
	mlx_string_put(window->mlx, window->win, map->size, map->y)//, color, string);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:05:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/08 18:01:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	t_window	*window;
	t_map		*map;
	int			height;
	int			scale;

	if (ac == 2)
	{
		height = 0;
		scale = 50;
		map = ft_readmap(av, &height);
		if (!map)
			ft_exception("Map reader");
		window = ft_createwindow(av[1], map->width, height, scale);
		if (window == NULL)
			ft_exception("Window");
		if (ft_checkmap(map) != TRUE)
			ft_exception("Invalide Map");
		ft_windowloop(window, map, height, scale);
		ft_destroywindow(&window, map);
	}
	else
		ft_exception("Map reader");
	return (EXIT_SUCCESS);
}

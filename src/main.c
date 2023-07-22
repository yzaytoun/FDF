/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:05:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 15:39:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_window	*window;
	t_map		*map;
	int			height;

	if (ac == 2)
	{
		height = 0;
		map = ft_readmap(av, &height);
		if (!map)
			ft_exception("Map reader");
		if (ft_checkmap(map) != TRUE)
			ft_exception("Invalide Map");
		if (ft_checkinput(map) != TRUE)
			ft_exception("Invalide Map");
		window = ft_createwindow(av[1], map->width, height);
		if (window == NULL)
			ft_exception("Window");
		ft_run(window, map, height);
	}
	else
		ft_exception("Map reader");
	return (EXIT_SUCCESS);
}

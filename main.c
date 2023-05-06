/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:05:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/06 17:50:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	t_window	*window;
	t_map		*map;

	if (ac == 2)
	{
		map = ft_readmap(av);
		if (!map)
			ft_exception("Map reader");
		window = ft_createwindow(map, av[1]);
		if (window == NULL)
			ft_exception("Window");
		window->map = ft_readmap(av);
		if (!window->map)
			ft_exception("Map reader");
		if (ft_checkmap(window->map) != TRUE)
			ft_exception("Invalide Map");
		ft_runwindow(window, window->map);
		ft_destroywindow(&window, window->map);
	}
	else
		ft_exception("Map reader");
	return (EXIT_SUCCESS);
}

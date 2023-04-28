/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:05:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/28 20:34:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	t_map		*map;
	t_window	*window;

	if (ac == 2)
	{
		map = ft_readmap(av);
		if (!map)
			ft_exception("Map reader");
		if (ft_checkmap(map) != TRUE)
			ft_exception("Invalide Map");
		window = ft_createwindow(map, av[1]);
		if (window == NULL)
			ft_exception("Window");
		ft_runwindow(window);
		ft_destroywindow(&window, map);
	}
	else
		ft_exception("Map reader");
	return (EXIT_SUCCESS);
}

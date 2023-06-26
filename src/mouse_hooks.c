/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/26 19:32:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Events

static int	ft_move(int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	//if (params->hook.buttonpress == 1)
	printf("x=%i y=%i\n", x, y);
	return (EXIT_SUCCESS);
}

static void	ft_mousemove(int button, t_params *params)
{
	if (button == 2)
	{
		params->fdf->flags.translation_y -= 10;
		params->fdf->flags.translation_x -= 10;
	}
}


static void	ft_mousemagnify(int button, t_params *params)
{
	if (button == 4)
	{
		params->fdf->distance_x -= 1;
		params->fdf->distance_y -= 1;
	}
	else if (button == 5)
	{
		params->fdf->distance_x += 1;
		params->fdf->distance_y += 1;
	}
}

//ANCHOR - Mouse Button
static int	ft_mousebutton(int button, int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (button == 4 || button == 5)
		ft_mousemagnify(button, params);
	if (button == 1 || button == 2)
		ft_mousemove(button, params);
	printf("button = %d\t x = %d\t y = %d\n", button, x, y);
	return (TRUE);
}

static int	ft_buttonrelease(int button, int x, int y,void *param)
{
	t_params	*params;

	params = (t_params *)param;
	printf("%i --> x=%d y=%d", button, x, y);
	if (button == 1)
		params->hook->buttonrelease = 1;
	printf("%i\n", params->hook->buttonpress);
	return (EXIT_SUCCESS);
}

static int	ft_buttonpress(int button, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	printf("%i\n", button);
	if (button == 1)
		params->hook->buttonpress = 1;
	return (EXIT_SUCCESS);
}

//ANCHOR - Close Window
static int	ft_closewindow(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
}

//ANCHOR - Main Func
void	ft_mousehooks(t_params *params)
{
	mlx_hook(params->window->win, 17, 0, ft_closewindow, params->window);
	mlx_hook(params->window->win, 4, 1L << 2, ft_buttonpress, params);
	mlx_hook(params->window->win, 5, 1L << 3, ft_buttonrelease, params);
	mlx_hook(params->window->win, 6, 1L << 6, ft_move, params);
	mlx_mouse_hook(params->window->win, ft_mousebutton, params);
}

//!SECTION

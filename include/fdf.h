/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/03 13:17:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H	/*FDF HEADER*/
# define FDF_H

/*Libraries*/
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "fdf_math.h"

/***********************Marcos************************/
/*Keyboard keys*/
# define KEY_ESCAPE	0x35

/*Macros*/
# define MAX_WIDTH 500
# define LOWERLEFT 1
# define LOWERRIGHT 2
# define UPPERLEFT 3
# define UPPERRIGHT 4
# define SUB 1
# define ADD 2
# define FIRST_POINT 0
# define SECOND_POINT 1

/*MAIN Struct*/
typedef struct s_hook
{
	int		buttonpress;
	int		x;
	int		y;
}			t_hook;

typedef struct s_params
{
	t_fdf		*fdf;
	t_matrix	*matrix;
	t_window	*window;
	t_map		*map;
	t_hook		*hook;
}			t_params;

/*Basic Functions*/
//ANCHOR - Map Reader
int			ft_createmap(t_map **map, char *x, int y);
char		*ft_readfile(char **av);
t_map		*ft_readmap(char **av, int *height);
void		ft_deletemap(t_map **map);
int			ft_checkmap(t_map *map);

//FIXME - Print
void		ft_printmap(t_map *map);
void		ft_printmatrix(t_matrix *matrix);
void		ft_printfdf(t_fdf *fdf);

//ANCHOR - Map Aux
int			ft_readarr(char **str, t_map **map);
void		ft_mapreverse(t_map **map);
void		ft_colorflood(int **array, int size, int color);

//ANCHOR - Window Manager
t_window	*ft_createwindow(char *title, int width, int height);
void		ft_destroywindow(t_window **window, t_map *map);
t_fdf		*ft_initstructs(t_window *window, t_map *map, int height);

//ANCHOR - Run Program
void		ft_createimage(t_window *window, t_fdf *fdf);
void		ft_run(t_window *window, t_map *map, int height);

//ANCHOR - Mouse Events
int			ft_mousebutton(int button, int x, int y, void *param);
int			ft_closewindow(void *param);
void		ft_mousehooks(t_params *params);

//ANCHOR - Key Events
int			ft_keyhooks(int keycode, void *param);

#endif /*FDF HEADER*/

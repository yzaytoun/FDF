/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/06 17:51:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H	/*FDF HEADER*/
# define FDF_H

/*Libraries*/
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

/***********************Marcos************************/
/*Keyboard keys*/
# define KEY_ESCAPE	0x35

/*Struct*/
typedef struct s_map
{
	int				*x;
	int				size;
	int				y;
	int				*color;
	struct s_map	*next;
}					t_map;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_map	*map;
}				t_window;

typedef struct s_point
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		step;
	int		i;
}			t_point;


/*Basic Functions*/
//ANCHOR - Map Reader
int			ft_createmap(t_map **map, char *x, int y);
char		*ft_readfile(char **av);
t_map		*ft_readmap(char **av);
void		ft_deletemap(t_map **map);
int			ft_checkmap(t_map *map);

//ANCHOR - Map Aux
int			ft_readarr(char **str, t_map **map);
void		ft_printmap(t_map *map);
void		ft_mapreverse(t_map **map);
void		ft_colorflood(int **array, int size, int color);

//ANCHOR - Window Generator
t_window	*ft_createwindow(t_map *map, char *title);
void		ft_destroywindow(t_window **window, t_map *map);
void		ft_runwindow(t_window *window, t_map *map);

//ANCHOR - AUX
void		ft_exception(char *str);

//ANCHOR - Mouse Events
void		ft_mousehooks(t_window *window);

//ANCHOR - Key Events
void		ft_keyhooks(t_window *window);

//ANCHOR - Key Events
void		ft_drawmap(t_window *window, t_map *map);
#endif /*FDF HEADER*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/15 19:55:18 by yzaytoun         ###   ########.fr       */
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

/*Macros*/
# define MAX_WIDTH 200
# define MAX_HEIGHT 200

/*Struct*/
typedef struct s_map
{
	int				*x;
	int				width;
	int				y;
	int				*color;
	int				min;
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
}				t_window;

typedef struct s_point
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		z;
	int		color0;
	int		color1;
	int		step;
	int		scale;
	int		width;
	int		height;
	int		drawlength;
	int		extend;
}			t_point;


/*Basic Functions*/
//ANCHOR - Map Reader
int			ft_createmap(t_map **map, char *x, int y);
char		*ft_readfile(char **av);
t_map		*ft_readmap(char **av, int *height);
void		ft_deletemap(t_map **map);
int			ft_checkmap(t_map *map);

//ANCHOR - Map Aux
int			ft_readarr(char **str, t_map **map);
void		ft_printmap(t_map *map);
void		ft_mapreverse(t_map **map);
void		ft_colorflood(int **array, int size, int color);

//ANCHOR - Window Generator
t_window	*ft_createwindow(char *title, int width, int height);
void		ft_destroywindow(t_window **window, t_map *map);
void		ft_windowloop(t_window *window, t_map *map, int height);

//ANCHOR - AUX
void		ft_exception(char *str);
int			ft_mapmin(t_map *map);

//ANCHOR - Mouse Events
void		ft_mousehooks(t_window *window);

//ANCHOR - Key Events
void		ft_keyhooks(t_window *window);

//ANCHOR - Key Events
void		ft_drawmap(t_window *window, t_map *map, t_point *point);

//ANCHOR - Draw Aux
void		ft_markpoint(t_point *point, t_map *map, int count);
void		ft_pixelput(t_window *window, int dist_x, int dist_y, int color);

#endif /*FDF HEADER*/

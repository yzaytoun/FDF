/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/30 19:12:12 by cxb0541          ###   ########.fr       */
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
# define MAX_WIDTH 500

/*Struct*/
typedef struct s_map
{
	int				*x;
	int				y;
	int				width;
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

typedef struct s_vector
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_vector;

typedef struct s_point
{
	t_vector	v0;
	t_vector	v1;
	int			distance_x;
	int			distance_y;
	int			imagelength;
	int			imageheight;
	double		scale;
	int			margin;
	int			min;
}			t_point;

typedef struct	s_matrix
{
	t_vector	**vector;
	int			length;
	int			height;
}				t_matrix;


/*Basic Functions*/
//ANCHOR - Map Reader
int			ft_createmap(t_map **map, char *x, int y);
char		*ft_readfile(char **av);
t_map		*ft_readmap(char **av, int *height);
void		ft_deletemap(t_map **map);
int			ft_checkmap(t_map *map);

//FIXME - To be deleted
void		ft_printmap(t_map *map);
void		ft_printmatrix(t_matrix *matrix);
//ANCHOR - Map Aux
int			ft_readarr(char **str, t_map **map);
void		ft_mapreverse(t_map **map);
void		ft_colorflood(int **array, int size, int color);
void		ft_normalizemap(t_map *map, int min);

//ANCHOR - Window Generator
t_window	*ft_createwindow(char *title, int width, int height);
void		ft_destroywindow(t_window **window, t_map *map);
void		ft_windowloop(t_window *window, t_map *map, int height);

//ANCHOR - AUX
void		ft_exception(char *str);
int			ft_mapmin(t_map *map);
double		ft_toradian(double degree);
t_map		*ft_new_mapnode(int *x, int y, int *color, int width);
t_map		*ft_copymap(t_map *map);

//ANCHOR - Mouse Events
void		ft_mousehooks(t_window *window);

//ANCHOR - Key Events
void		ft_keyhooks(t_window *window);

//ANCHOR - Key Events
void		ft_drawmap(t_window *window, t_map *map, t_point *point);

//ANCHOR - Draw Aux
void		ft_printheader(t_window *window, t_point *point);
void		ft_markpoint(t_point *point, t_matrix *matrix, int count_x, int count_y);
void		ft_pixelput(t_window *window, int dist_x, int dist_y, int color);
void		ft_isoprojection(int *x, int *y, int angle);
void		ft_draw_xy(t_window *window, t_point *point);

//ANCHOR - Matrix
t_matrix	*ft_creatematrix(t_map *map, t_point *point);
void		ft_destroyvector(t_vector ***vector, int size);
t_vector	**ft_createvector(int length, int height);
void		ft_fillmatrix(t_map *map, t_matrix *matrix);
#endif /*FDF HEADER*/

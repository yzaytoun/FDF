/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/03 17:57:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H	/*FDF HEADER*/
# define FDF_H

/*Libraries*/
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <math.h>
# include <mlx.h>

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
	float	x;
	float	y;
	float	z;
	int		color;
}				t_vector;

typedef struct s_line
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_line;

typedef struct s_ham
{
	int		dx;
	int		dy;
	int		err;
	int		e2;
	int		sy;
	int		sx;
	int		x2;
	int		ed;
}			t_ham;


typedef struct s_fdf
{
	t_line	v0;
	t_line	v1;
	t_ham	ham;
	int		distance_x;
	int		distance_y;
	int		imagelength;
	int		imageheight;
	double	scale;
	int		margin;
	float	min_x;
	float	min_y;
}			t_fdf;

typedef struct s_matrix
{
	t_vector	**vector;
	int			length;
	int			height;
	int			count_x;
	int			count_y;
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
void		ft_printfdf(t_fdf *fdf);
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
float		ft_toradian(float degree);
int			ft_toint(float num);

//ANCHOR - Mouse Events
void		ft_mousehooks(t_window *window);

//ANCHOR - Key Events
void		ft_keyhooks(t_window *window);

//ANCHOR - Key Events
void		ft_drawmap(t_window *window, t_map *map, t_fdf *point);

//ANCHOR - Draw Aux
void		ft_printheader(t_window *window, t_fdf *point);
void		ft_markpoint(t_fdf *point, t_matrix *matrix);
void		ft_pixelput(t_window *window, int dist_x, int dist_y, int color);
void		ft_draw_xy(t_window *window, t_fdf *point);

//ANCHOR - Matrix
t_matrix	*ft_creatematrix(t_map *map, t_fdf *point);
void		ft_destroyvector(t_vector ***vector, int size);
t_vector	**ft_createvector(int length, int height);
void		ft_fillmatrix(t_map *map, t_matrix **matrix);

//ANCHOR - AUX Matrix
void		ft_matrixmin(t_matrix *matrix, t_fdf *fdf);

//ANCHOR - Transform
void		ft_transform(t_matrix *matrix, void (*func)(t_vector *, t_fdf *),
				t_fdf *point);
void		ft_isoprojection(t_vector *vector, t_fdf *point);
void		ft_topositive(t_vector *vector, t_fdf *point);
void		ft_translate(t_vector *vector, t_fdf *point);
#endif /*FDF HEADER*/

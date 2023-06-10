/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/10 18:04:49 by yzaytoun         ###   ########.fr       */
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
}				t_vector;

typedef struct s_line
{
	int		x;
	int		y;
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
	t_line		v0;
	t_line		v1;
	t_ham		ham;
	t_vector	angle;
	int			distance_x;
	int			distance_y;
	int			imagelength;
	int			imageheight;
	double		scale;
	int			margin;
	float		min_x;
	float		min_y;
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

//FIXME - Printers
void		ft_printmap(t_map *map);
void		ft_printmatrix(t_matrix *matrix);
void		ft_printfdf(t_fdf *fdf);

//ANCHOR - Map Aux
int			ft_readarr(char **str, t_map **map);
void		ft_mapreverse(t_map **map);
void		ft_colorflood(int **array, int size, int color);
void		ft_normalizemap(t_map *map, int min);

//ANCHOR - Window Manager
t_window	*ft_createwindow(char *title, int width, int height);
void		ft_destroywindow(t_window **window, t_map *map);
t_fdf		*ft_initstructs(t_window *window, t_map *map, int height);

//ANCHOR - Run Program
void		ft_run(t_window *window, t_map *map, int height);

//ANCHOR - AUX
void		ft_exception(char *str);
int			ft_mapmin(t_map *map);
void		ft_toradian(t_vector *angle);
int			ft_toint(float num);

//ANCHOR - Mouse Events
void		ft_mousehooks(t_window *window);

//ANCHOR - Key Events
void		ft_keyhooks(t_window *window);

//ANCHOR - Draw
void		ft_plotmap(t_window *window, t_map *map, t_fdf *fdf,
				t_matrix *matrix);
void		ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix,
				t_map *map);

//ANCHOR - Draw Aux
void		ft_printheader(t_window *window, t_fdf *fdf);
void		ft_markpoint(t_fdf *fdf, t_matrix *matrix);
void		ft_pixelput(t_window *window, int dist_x, int dist_y, int color);
void		ft_bresenham(t_window *window, t_fdf *fdf);

//ANCHOR - Matrix
t_matrix	*ft_creatematrix(int dim_x, int dim_y);
void		ft_destroyvector(t_vector ***vector, int size);
void		ft_matrix_map(t_map *map, t_matrix **matrix);

//ANCHOR - AUX Matrix
void		ft_matrixmin(t_matrix *matrix, t_fdf *fdf);

//ANCHOR - Apply
void		ft_apply(t_matrix *matrix, void (*func)(t_vector *, t_fdf *),
				t_fdf *fdf);
void		ft_normalize(t_vector *vector, t_fdf *fdf);
void		ft_translate(t_vector *vector, t_fdf *fdf);
void		ft_to2d(t_vector *vector, t_fdf *fdf);
void		ft_matrotate(t_vector *vector, t_fdf *fdf);

//ANCHOR - Rotate
void		ft_angleinit(t_vector *vector, t_fdf *fdf);
t_matrix	*ft_rotate_matrix(t_vector *vector, t_fdf *fdf);

#endif /*FDF HEADER*/

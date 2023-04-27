/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/27 20:28:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H	/*FDF HEADER*/
# define FDF_H

/*Libraries*/
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

/*Marcos*/

/*Struct*/
typedef struct s_map
{
	int				*x;
	int				size;
	int				y;
	struct s_map	*next;
}					t_map;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}				t_window;


/*Basic Functions*/
//ANCHOR - Map Reader
int			ft_createmap(t_map **map, char *x, int y);
char		*ft_readfile(char **av);
t_map		*ft_readmap(char **av);
void		ft_deletemap(t_map **map);

//ANCHOR - Map Aux
int			*ft_arr(char **str, int *size);
void		ft_printmap(t_map *map);

//ANCHOR - Window Generator
t_window	*ft_createwindow(t_map *map, char *title);
void		ft_destroywindow(t_window **window);
void		ft_runwindow(t_window *window);

//ANCHOR - AUX
void		ft_exception(char *str);

#endif /*FDF HEADER*/
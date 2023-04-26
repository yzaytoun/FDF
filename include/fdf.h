/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/26 20:25:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H	/*FDF HEADER*/
# define FDF_H

/*Libraries*/
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <math.h>
# include "../minilibx/minilibx_macos/mlx.h"

/*Marcos*/
# define CREATE 4
# define DESTROY 5

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
}				t_window;


/*Basic Functions*/
//ANCHOR - Map Reader
int		ft_createmap(t_map **map, char *x, int y);
char	*ft_readfile(char **av);
t_map	*ft_readmap(char **av);
void	ft_deletemap(t_map **map);

//ANCHOR - Map Aux
int		*ft_arr(char **str);
void	ft_printmap(t_map *map);

//ANCHOR - Window Generator
void	*ft_window(int action);

#endif /*FDF HEADER*/
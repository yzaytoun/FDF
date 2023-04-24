/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:12 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/24 18:32:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H	/*FDF HEADER*/
# define FDF_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <math.h>
/*# include "../minilibx/minilibx/mlx.h"
# include "../minilibx/minilibx/mlx_int.h"
# include "../minilibx/minilibx_marcos/mlx.h"
# include "../minilibx/minilibx_marcos/mlx_int.h"
*/
typedef struct s_map
{
	int				*x;
	int				y;
	struct s_map	*next;
}					t_map;

//ANCHOR - Map Reader
int		ft_createmap(t_map **map, char *x, int y);
char	*ft_readfile(char **av);
t_map	*ft_readmap(char **av);
void	ft_deletemap(t_map **map);

//ANCHOR - Map Aux
int		*ft_arr(char **str);
#endif /*FDF HEADER*/
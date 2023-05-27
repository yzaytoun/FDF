/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:19:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/27 19:43:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw
static t_map	*ft_transform(t_map *map)
{
	t_map	*node;
	t_map	*transformed;
	int		count;
	int		y;

	if (!map)
		return (NULL);
	transformed = ft_copymap(map);
	node = transformed;
	count = 0;
	y = 0;
	while (node != NULL)
	{
		count = 0;
		y = node->y;
		while (count < node->width)
		{
			ft_isoprojection(&node->x[count], &y, 60);
			++count;
		}
		node = node->next;
	}
	return (transformed);
}

//ANCHOR - Draw Net
static void	ft_draw_xy(t_window *window, t_point *point)
{
	register int	pixel;
	int				dx;
	int				dy;

	dx = fabs(point->x1 - point->x0);
	dy = fabs(point->y1 - point->y0);
	pixel = (2 * dy) - dx;
	while (point->x0 <= point->x1)
	{
		if (point->x0 < point->imagelength && point->y0 < point->imageheight)
		{
			ft_pixelput(window, point->x0, point->y0, point->color0);
			ft_pixelput(window, point->y0, point->x0, point->color0);
		}
		point->x0 += 1;
		if (pixel >= 0)
		{
			pixel += 2 * (dy - dx);
			point->y0 += 1;
		}
		else
			pixel += 2 * dy;
	}
}

//ANCHOR - Draw borders
static void	ft_drawaxis(t_window *window, t_point *point)
{
	register int	pixel;
	int				maxlen;
	int				maxwidth;

	pixel = 0;
	maxwidth = point->imagelength - point->margin - (point->imagelength * 0.1);
	maxlen = point->imageheight - point->margin - (point->imageheight * 0.1);
	while (pixel < maxwidth)
	{
		ft_pixelput(window, pixel, 0, 0x00FF00);
		pixel++;
	}
	pixel = 0;
	while (pixel < maxlen)
	{
		ft_pixelput(window, 0, pixel, 0xFFFF00);
		pixel++;
	}
}

//ANCHOR - Main func
void	ft_drawmap(t_window *window, t_map *map, t_point *point)
{
	t_map	*node;
	int		count;
	t_map	*transform;

	window->addr = mlx_get_data_addr(window->img,
			&window->bpp, &window->size_line, &window->endian);
	ft_drawaxis(window, point);
	transform = ft_transform(map);
	ft_printmap(transform);
	ft_normalizemap(transform, abs(ft_mapmin(transform)));
	ft_printmap(transform);
	count = 0;
	node = transform;
	while (node != NULL)
	{
		count = 0;
		while (count < node->width)
		{
			ft_markpoint(point, node, count);
			ft_draw_xy(window, point);
			++count;
		}
		node = node->next;
	}
	ft_printheader(window, point);
	mlx_put_image_to_window(window->mlx, window->win,
		window->img, point->margin + 5, point->margin + 5);
	ft_deletemap(&transform);
}
//!SECTION

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:14:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/11 10:05:16 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Matrix Functions
//ANCHOR Destroy Vector
void	ft_destroyvector(t_vector ***vector, int size)
{
	int	count;

	count = 0;
	if (!vector || (*vector) == NULL)
		return ;
	while (count < size)
	{
		free((*vector)[count]);
		++count;
	}
	free(*vector);
}

//ANCHOR Create Vector
static t_vector	**ft_createvector(int length, int height)
{
	t_vector	**vector;
	int			count;

	count = 0;
	vector = ft_calloc(height, sizeof(t_vector));
	if (!vector)
		return (NULL);
	while (count < height)
	{
		vector[count] = ft_calloc(length, sizeof(t_vector));
		if (!vector[count])
		{
			ft_destroyvector(&vector, height);
			return (NULL);
		}
		++count;
	}
	return (vector);
}

void	ft_matrix_map(t_map *map, t_matrix **matrix)
{
	t_map	*node;

	if (!map || !(*matrix) || !(*matrix)->vector)
		return ;
	node = map;
	while (node != NULL)
	{
		(*matrix)->count_x = 0;
		(*matrix)->count_y = node->y;
		while ((*matrix)->count_x < node->width)
		{
			(*matrix)->vector[(*matrix)->count_y][(*matrix)->count_x].x
				= (*matrix)->count_x;
			(*matrix)->vector[(*matrix)->count_y][(*matrix)->count_x].y
				= (*matrix)->count_y;
			(*matrix)->vector[(*matrix)->count_y][(*matrix)->count_x].z
				= node->x[(*matrix)->count_x];
			(*matrix)->count_x += 1;
		}
		node = node->next;
	}
}

//ANCHOR Create Matrix
t_matrix	*ft_creatematrix(int dim_x, int dim_y)
{
	t_matrix	*matrix;

	if (dim_x <= 0 || dim_y <= 0)
		return (NULL);
	matrix = ft_calloc(1, sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->length = dim_x;
	matrix->height = dim_y;
	matrix->vector = ft_createvector(matrix->length, matrix->height);
	return (matrix);
}

//!SECTION

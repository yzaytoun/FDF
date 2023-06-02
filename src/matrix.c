/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:14:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/02 20:16:49 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION Matrix Functions
//FIXME - To be deleted
void	ft_printmatrix(t_matrix *matrix)
{
	if (!matrix || !matrix->vector)
		return ;
	matrix->count_x = 0;
	matrix->count_y = 0;
	while (matrix->count_y < matrix->height)
	{
		matrix->count_x = 0;
		while (matrix->count_x < matrix->length)
		{
			printf("(%f, %f, %f, %x)\t", 
				matrix->vector[matrix->count_y][matrix->count_x].x,
				matrix->vector[matrix->count_y][matrix->count_x].y,
				matrix->vector[matrix->count_y][matrix->count_x].z,
				matrix->vector[matrix->count_y][matrix->count_x].color);
			++matrix->count_x;
		}
		printf("\n");
		++matrix->count_y;
	}

}

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
t_vector	**ft_createvector(int length, int height)
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

void	ft_fillmatrix(t_map *map, t_matrix **matrix)
{
	t_map	*node;

	if (!map || !(*matrix) || !(*matrix)->vector)
		return ;
	(*matrix)->count_x = 0;
	node = map;
	(*matrix)->count_y = node->y;
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
			(*matrix)->vector[(*matrix)->count_y][(*matrix)->count_x].color
				= node->color[(*matrix)->count_x];
			(*matrix)->count_x += 1;
		}
		node = node->next;
	}
}

//ANCHOR Create Matrix
t_matrix	*ft_creatematrix(t_map *map, t_fdf *point)
{
	t_matrix	*matrix;

	if (!map)
		return (NULL);
	matrix = ft_calloc(1, sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->length = point->imagelength / point->scale;
	matrix->height = point->imageheight / point->scale;
	matrix->vector = ft_createvector(matrix->length, matrix->length);
	return (matrix);
}

//!SECTION

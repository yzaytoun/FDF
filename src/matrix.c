//HEADER

# include "../include/fdf.h"

//SECTION Matrix Functions 
//ANCHOR Create Vector
t_vector	**ft_createvector(int length, int height)
{
	t_vector	**vector;
	int			count;

	count = 0;
	vector = ft_calloc(sizeof(t_vector), height);
	if (!vector)
		return (NULL);
	while (count < height)
	{
		vector[count] = ft_calloc(sizeof(int), length);
		if (!vector[count])
		{
			ft_destroyvector(&vector);
			return (NULL);
		}
	}
	return (vector);
}

t_vector	**ft_fillvector(t_map *map, int length, int height)
{
	t_vector	**vector;
	t_map		*node;
	int			count_x;
	int			count_y;

	count_x = 0;
	count_y = 0;
	node = map;
	vector = ft_createvector(length, height);
	while (node != NULL)
	{
		count_x = 0;
		count_y = node->y;
		while (count_x < node->width)
		{
			vector[count_y][count_x].x = count_x;
			vector[count_y][count_x].y = count_y;
			vector[count_y][count_x].z = node->x[count_x];
			++count_x;
		}
		node = node->next;
	}
	return (vector);
}

//ANCHOR Get Matrix
t_matrix	*ft_creatematrix(t_map *map, t_point *point)
{
	t_matrix	*matrix;

	if (!map)
		return (NULL);
	matrix = ft_calloc(1, sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->length = point->imagelength / point->scale;
	matrix->height = point->imageheight / point->scale;
	matrix->vector = ft_fillvector(map, matrix->length, matrix->length);
	return (matrix);
}

//!SECTION

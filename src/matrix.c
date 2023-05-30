//HEADER

# include "../include/fdf.h"

//SECTION Matrix Functions
//FIXME - To be deleted
void	ft_printmatrix(t_matrix *matrix)
{
	int	count_x;
	int	count_y;

	if (!matrix || !matrix->vector)
		return ;
	count_x = 0;
	count_y = 0;
	while (count_y < matrix->height)
	{
		count_x = 0;
		while (count_x < matrix->length)
		{
			printf("(%d, %d, %d)\t", 
				matrix->vector[count_y][count_x].x,
				matrix->vector[count_y][count_x].y,
				matrix->vector[count_y][count_x].z);
			++count_x;
		}
		printf("\n");
		++count_y;
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
	vector = ft_calloc(sizeof(t_vector), height);
	if (!vector)
		return (NULL);
	while (count < height)
	{
		vector[count] = ft_calloc(sizeof(int), length);
		if (!vector[count])
		{
			ft_destroyvector(&vector, height);
			return (NULL);
		}
		++count;
	}
	return (vector);
}

void	ft_fillmatrix(t_map *map, t_matrix *matrix)
{
	t_map		*node;
	int			count_x;
	int			count_y;

	if (!map || !matrix || !matrix->vector)
		return ;
	count_x = 0;
	node = map;
	count_y = node->y;
	while (node != NULL)
	{
		count_x = 0;
		count_y = node->y;
		while (count_x < node->width)
		{
			matrix->vector[count_y][count_x].x = count_x;
			matrix->vector[count_y][count_x].y = count_y;
			matrix->vector[count_y][count_x].z = node->x[count_x];
			++count_x;
		}
		node = node->next;
	}

}

//ANCHOR Create Matrix
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
	matrix->vector = ft_createvector(matrix->length, matrix->length);
	return (matrix);
}

//!SECTION

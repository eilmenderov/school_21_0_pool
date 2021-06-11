/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaureen <tlaureen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:10:26 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/24 15:52:11 by tlaureen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	ft_get_value(unsigned int *matrix, long long int x,
								long long int y, t_data *data)
{
	if ((x < 0) || (y < 0))
		return (0);
	else
		return (matrix[x + y * data->width]);
}

unsigned int	ft_calc(unsigned int *matrix, long long int x,
							long long int y, t_data *data)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = ft_get_value(matrix, x - 1, y, data);
	b = ft_get_value(matrix, x, y - 1, data);
	c = ft_get_value(matrix, x - 1, y - 1, data);
	if ((a <= c) && (a <= b))
		return (a);
	if ((b <= c) && (b <= a))
		return (b);
	return (c);
}

void			ft_update_size(long long int x, long long int y,
								long long int size, t_data *data)
{
	if (size > data->found_size)
	{
		data->found_size = size;
		data->found_x = x - size + 1;
		data->found_y = y - size + 1;
	}
}

void			ft_find_size(unsigned int *matrix, t_data *data)
{
	long long int j;
	long long int i;

	j = 0;
	while (j < data->heght)
	{
		i = 0;
		while (i < data->width)
		{
			ft_update_size(i, j, matrix[i + j * data->width], data);
			i++;
		}
		j++;
	}
}

void			ft_solve_map(char **map, t_data *data)
{
	long long int	j;
	long long int	i;
	long long int	size;
	unsigned int	*matrix;

	matrix = malloc(sizeof(unsigned int) * data->heght * data->width);
	j = 0;
	while (j < data->heght)
	{
		i = 0;
		while (i < data->width)
		{
			if (map[j][i] == data->obstacle)
				matrix[i + j * data->width] = 0;
			else
			{
				size = (map[j][i] == data->empty) + ft_calc(matrix, i, j, data);
				matrix[i + j * data->width] = size;
			}
			i++;
		}
		j++;
	}
	ft_find_size(matrix, data);
	free(matrix);
}

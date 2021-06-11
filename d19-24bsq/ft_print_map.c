/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaureen <tlaureen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:31:01 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/24 16:47:38 by tlaureen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_fill_char(char **map, t_data *data)
{
	int i;
	int j;

	j = data->found_y;
	while (j < (data->found_y + data->found_size))
	{
		i = data->found_x;
		while (i < (data->found_x + data->found_size))
		{
			map[j][i] = data->full;
			i++;
		}
		j++;
	}
}

void	ft_print_map(char **map, t_data *data)
{
	unsigned int	j;
	unsigned int	i;
	char			c;

	ft_fill_char(map, data);
	j = 0;
	while (j < data->heght)
	{
		write(1, map[j], data->width);
		j++;
		write(1, "\n", 1);
	}
}

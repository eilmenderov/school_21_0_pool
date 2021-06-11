/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:33:46 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/25 11:14:59 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free_memory(char **map, t_data *data, int key)
{
	int	i;

	if (key > -4 && key < 0)
		return ;
	if (key > 0)
	{
		i = 0;
		while (i < (data->heght + 1) && data->heght != 1)
		{
			free(map[i]);
			i++;
		}
	}
	else
	{
		key = (-1) * key - 5;
		i = -1;
		while (i++ < key)
			free(map[i]);
	}
	free(map);
}

void	ft_clear_data(char **map, t_data *data)
{
	data->empty = '\0';
	data->obstacle = '\0';
	data->full = '\0';
	data->found_x = -1;
	data->found_y = -1;
	data->heght = -1;
	data->width = -1;
	data->found_size = -1;
	data->filename = 0;
}

void	ft_gen_blok(char **map, t_data *data)
{
	int	key;

	key = 0;
	key = ft_read_map(&map, data);
	if (key < 0)
		ft_puterror("map error");
	else
	{
		ft_solve_map(map, data);
		ft_print_map(map, data);
	}
	ft_free_memory(map, data, key);
}

int		ft_input_map(t_data *data)
{
	int		fd;
	int		wr;
	char	buf[1024];

	fd = open("temp_file", O_TRUNC | O_RDWR | O_CREAT, 0664);
	if (fd == -1)
		return (-1);
	while ((wr = read(0, buf, 1024)) != 0)
	{
		if (wr == -1)
		{
			close(fd);
			return (-1);
		}
		write(fd, buf, wr);
	}
	close(fd);
	data->filename = "temp_file";
	return (0);
}

int		main(int argc, char **argv)
{
	char	**map;
	t_data	data;
	int		i;

	ft_clear_data(map, &data);
	if (argc == 1)
	{
		ft_clear_data(map, &data);
		if (ft_input_map(&data) == -1)
			ft_puterror("map error");
		else
			ft_gen_blok(map, &data);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_clear_data(map, &data);
			data.filename = argv[i];
			ft_gen_blok(map, &data);
			i++;
			if (i != argc)
				write (1, "\n", 1);
		}
	}
	return (0);
}

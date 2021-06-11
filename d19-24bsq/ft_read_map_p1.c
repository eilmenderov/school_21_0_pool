/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_p1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:40:55 by vleida            #+#    #+#             */
/*   Updated: 2021/03/25 11:23:20 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_check_fstr(int f_open, t_data *data)
{
	char	*fstr;
	char	buf;
	int		i;

	fstr = malloc(sizeof(char) * MALSIZ);
	if (!fstr)
		return (-2);
	i = 0;
	while (read(f_open, &buf, 1))
	{
		if (buf == '\n')
			break ;
		fstr[i] = buf;
		i++;
	}
	if (i < 4)
		return (ft_frfstr(fstr));
	ft_pull_data(data, fstr, i);
	if (data->heght <= 0)
		return (ft_frfstr(fstr));
	free(fstr);
	return (0);
}

int		ft_check_lines(int pot, int i, t_data *data, char **map)
{
	int		j;
	char	buf;
	char	*newline;

	newline = malloc(sizeof(char) * data->width + 1);
	if (!newline)
		return (-3);
	map[i] = &newline[0];
	j = 0;
	while (read(pot, &buf, 1))
	{
		if (i == data->heght && buf != '\0')
			return (-3);
		if ((buf != data->empty && buf != data->obstacle && buf != '\n') ||
		(buf < 32 && buf != '\n') || buf > 127 || j > data->width)
			return (-3);
		if (buf == '\n')
			break ;
		newline[j++] = buf;
	}
	if (j != data->width && i < data->heght)
		return (-3);
	if (i == data->heght && (j > 0 || buf != '\n'))
		return (-3);
	return (0);
}

int		ft_check_for_one(int pot, char *newline)
{
	char	buf;
	int		i;

	if (read(pot, &buf, 1) == '\0')
	{
		free(newline);
		return (0);
	}
	else
	{
		return (-5);
	}
}

int		ft_check_arr(int pot, t_data *data, char ***map)
{
	int		i;
	char	*newline;

	*map = malloc(sizeof(char*) * data->heght + 1);
	if (!*map)
		return (-3);
	newline = malloc(sizeof(char) * MALSIZ + 1);
	if (!newline)
		return (-4);
	*map[0] = &newline[0];
	i = 0;
	if (ft_check_arrfl(data, pot, &i, newline))
		return (-5);
	if (data->heght == 1)
		return (ft_check_for_one(pot, newline));
	i = 0;
	while (i++ < data->heght)
	{
		if (ft_check_lines(pot, i, data, *map) != 0)
			return (i * (-1) - 5);
	}
	return (0);
}

int		ft_read_map(char ***map, t_data *data)
{
	int		f_open;
	int		num_chek;
	char	buf;

	num_chek = 0;
	if (data->filename)
		f_open = open(data->filename, O_RDONLY);
	if (f_open == -1)
		return (-1);
	if (ft_check_fstr(f_open, data) || ft_chek_sumb(data))
	{
		close(f_open);
		return (-2);
	}
	num_chek = ft_check_arr(f_open, data, map);
	if (num_chek)
	{
		close(f_open);
		return (num_chek);
	}
	close(f_open);
	return (1);
}

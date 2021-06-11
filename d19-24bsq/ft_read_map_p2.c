/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:48:06 by vleida            #+#    #+#             */
/*   Updated: 2021/03/24 23:01:29 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_number(char *stri, t_data *data)
{
	int	res;

	res = 0;
	while (*stri && (*stri == ' ' || (*stri > 8 && *stri < 14)))
		stri++;
	while (*stri && *stri >= '0' && *stri <= '9')
	{
		res = res * 10 + (*stri - 48);
		if (res < 0)
			return (res);
		stri++;
	}
	if (*stri != '\0')
		return (-2);
	return (res);
}

int		ft_frfstr(char *fstr)
{
	free(fstr);
	return (-2);
}

void	ft_pull_data(t_data *data, char *fstr, int i)
{
	data->full = fstr[i - 1];
	data->obstacle = fstr[i - 2];
	data->empty = fstr[i - 3];
	fstr[i - 3] = '\0';
	data->heght = ft_number(fstr, data);
}

int		ft_chek_sumb(t_data *data)
{
	if (data->empty == data->full || data->empty == data->obstacle)
		return (-3);
	if (data->full == data->obstacle)
		return (-3);
	return (0);
}

int		ft_check_arrfl(t_data *data, int pot, int *i, char *newline)
{
	char	buf;
	int		k;

	k = 0;
	while (read(pot, &buf, 1))
	{
		if ((buf != data->empty && buf != data->obstacle && buf != '\n') ||
		(buf < 32 && buf != '\n') || buf > 127)
			return (-3);
		if (buf == '\n')
		{
			k = 1;
			break ;
		}
		newline[*i] = buf;
		*i = *i + 1;
	}
	if (*i == 0 || k != 1)
		return (-3);
	data->width = *i;
	return (0);
}

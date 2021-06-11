/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_par2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:38:53 by vleida            #+#    #+#             */
/*   Updated: 2021/03/23 13:54:09 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ft.h"

int		ft_strlen_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_first_zero(char *buf, int text)
{
	int i;

	i = 1;
	if (*buf == '0')
	{
		while (*buf == '0')
			read(text, buf, 1);
	}
	return (buf);
}

int		ft_unik_help(int text, int len, char *buf, char num)
{
	int	i;
	int	key;
	int nul;

	ft_zanull(&i, &key, &nul);
	while (read(text, buf, 1) != '\0')
	{
		if (*buf > 47 && *buf < 58)
		{
			if (key == 0 && *buf == '0')
				buf = ft_first_zero(buf, text);
			if ((*buf == num && i == 0))
				key = 1;
			if (*buf == '0' && key == 1)
				nul++;
			i++;
			continue;
		}
		if (i == len && key == 1 && nul == len - 1)
			break ;
		ft_zanull(&i, &key, &nul);
	}
	if (*buf == '\0')
		return (0);
	return (1);
}

int		ft_unik_help1(int text, int len, char *buf, char num)
{
	int	i;
	int	key;
	int nul;

	ft_zanull(&i, &key, &nul);
	while (read(text, buf, 1) != '\0')
	{
		if (*buf > 47 && *buf < 58)
		{
			if ((*buf == num && i == 1))
				key = 1;
			if (key == 0 && *buf == '0')
				buf = ft_first_zero(buf, text);
			if (*buf == '0' && key == 1)
				nul++;
			i++;
			continue;
		}
		if (i == 2 && key == 1)
			break ;
		ft_zanull(&i, &key, &nul);
	}
	if (*buf == '\0')
		return (0);
	return (1);
}

void	ft_unik_all(int text, int len, char num)
{
	char	buf;
	int		i;
	int		k;

	i = 0;
	if (len == -1)
		k = ft_unik_help1(text, len, &buf, num);
	else
		k = ft_unik_help(text, len, &buf, num);
	while (read(text, &buf, 1) && k)
	{
		if (buf != ' ' && (buf != ':' || i == 1))
			break ;
		if (buf == ':')
			i++;
	}
	write(1, &buf, 1);
	while (read(text, &buf, 1) && k)
	{
		if (buf == '\n')
			break ;
		write(1, &buf, 1);
	}
}

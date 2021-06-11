/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:24:31 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:25:14 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define SIZ 1

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_red_loop(void)
{
	char buff;

	while (read(0, &buff, SIZ) > 0)
		write(1, &buff, SIZ);
}

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_check(int e, char *ar, char *ar1)
{
	char	*err;

	if (e != 0 && ft_strcmp(ar, "-") != 0)
	{
		err = strerror(e);
		write(2, basename(ar1), ft_strlen(basename(ar1)));
		write(2, ": ", 2);
		write(2, ar, ft_strlen(ar));
		write(2, ": ", 2);
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
}

int		main(int argc, char *argv[])
{
	int		fchek;
	int		i;
	int		key;
	char	buffer;

	if (argc == 1)
		ft_red_loop();
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			ft_red_loop();
		fchek = open(argv[i], O_RDONLY);
		if (fchek == -1)
			ft_check(errno, argv[i], argv[0]);
		if (fchek != -1)
		{
			while (read(fchek, &buffer, SIZ) != 0)
				write(1, &buffer, SIZ);
			write(1, "\n", 1);
		}
		close(fchek);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:24:31 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:25:52 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ft.h"

void	ft_rezult(char *arr, int kol_but, char *ar1)
{
	char	*last;
	int		i;
	int		pot;
	char	buf;

	last = malloc(sizeof(char) * kol_but + 1);
	if ((pot = open(arr, O_RDONLY)) == -1)
	{
		ft_check_op(errno, arr, ar1);
		return ;
	}
	else
	{
		while (read(pot, &buf, SIZ))
		{
			i = 0;
			while (++i < kol_but)
				last[i - 1] = last[i];
			last[i - 1] = buf;
			last[i] = '\0';
		}
	}
	close(pot);
	write(1, last, kol_but);
	free(last);
}

void	ft_rezult_plus(char *arr, int kol_but, char *ar1)
{
	char	*last;
	int		i;
	int		pot;
	char	buf;

	last = malloc(sizeof(char) * kol_but);
	if ((pot = open(arr, O_RDONLY)) == -1)
	{
		ft_check_op(errno, arr, ar1);
		return ;
	}
	if (pot != -1)
	{
		while (read(pot, &buf, SIZ) != 0)
		{
			i = 0;
			while (++i < kol_but)
				last[i - 1] = last[i];
			last[i - 1] = buf;
			last[i] = '\0';
		}
		close(pot);
		pech(last, kol_but, arr);
		free(last);
	}
}

void	ft_red_loop(int kol_but)
{
	char	buff;
	char	*last;
	int		i;

	last = malloc(sizeof(char) * kol_but);
	while (read(0, &buff, SIZ) > 0)
	{
		i = 1;
		while (i < kol_but)
		{
			last[i - 1] = last[i];
			i++;
		}
		last[i - 1] = buff;
	}
	write(1, last, kol_but);
	free(last);
}

int		main(int argc, char *argv[])
{
	int kol;
	int i;
	int pot;

	if (ft_check_num(argv[2]) != 1)
	{
		write(2, "ft_tail: illegal offset -- ", 27);
		write(2, basename(argv[3]), ft_strlen(basename(argv[3])));
		write(2, "\n", 1);
		return (0);
	}
	kol = ft_atoi(argv[2]);
	if (argc == 3)
		ft_red_loop(kol);
	if (argc == 4)
		ft_rezult(argv[4], kol, argv[0]);
	if (argc > 4)
	{
		i = 3;
		while (i < argc)
			ft_rezult_plus(argv[i], kol, argv[0]);
	}
	return (0);
}

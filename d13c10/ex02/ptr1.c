/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:07:11 by vleida            #+#    #+#             */
/*   Updated: 2021/03/16 19:45:09 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include <stdlib.h>
#include "my_ft.h"

void	ft_check_op(int e, char *ar, char *ar1)
{
	char	*err;

	if (e != 0)
	{
		err = strerror(e);
		write(2, basename(ar1), ft_strlen(basename(ar1)));
		write(2, ": ", 2);
		write(2, ar, ft_strlen(ar));
		write(2, ": ", 2);
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
	free(err);
}

int		ft_check_num(char *ar)
{
	while (*ar)
	{
		if (*ar < '0' || *ar > '9')
			return (0);
		ar++;
	}
	return (1);
}

void	pech(char *arr, int kol_but, char *last)
{
	write(1, "==> ", 4);
	write(1, arr, ft_strlen(arr));
	write(1, " <==\n", 5);
	write(1, last, kol_but);
	write(1, "\n", 1);
}

int		ft_step_rez(int chis, int step)
{
	int rez;
	int i;

	rez = 1;
	i = 0;
	if (step == 0)
		return (1);
	while (i < step)
	{
		rez = rez * chis;
		i++;
	}
	return (rez);
}

int		ft_creat_number(char *chis, int por)
{
	int rez;
	int i;

	rez = 0;
	i = 0;
	while (por > 0)
	{
		rez = rez - (chis[por - 1] - '0') * ft_step_rez(10, (i));
		por--;
		i++;
	}
	return (-rez);
}

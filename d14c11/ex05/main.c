/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:40:41 by vleida            #+#    #+#             */
/*   Updated: 2021/03/17 16:25:29 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "my_ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else if (nb < 0)
	{
		ft_putchar(45);
		ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_print(int per1, int per2, int a)
{
	if (a == 1)
		ft_putnbr(per1 + per2);
	else if (a == 2)
		ft_putnbr(per1 - per2);
	else if (a == 3)
		ft_putnbr(per1 * per2);
	else if (a == 4)
	{
		if (per2 == 0)
			write(1, "Stop : division by zero", 24);
		else
			ft_putnbr(per1 / per2);
	}
	else if (a == 5)
	{
		if (per2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(per1 % per2);
	}
	else
		write(1, "0", 1);
}

int		main(int argc, char **argv)
{
	int per1;
	int per2;
	int (*f[5])(char);
	int oper;
	int i;

	f[0] = &plus;
	f[1] = &minus;
	f[2] = &umnog;
	f[3] = &divis;
	f[4] = &modul;
	if (argc != 4)
		return (0);
	per1 = ft_atoi(argv[1]);
	per2 = ft_atoi(argv[3]);
	oper = 0;
	i = -1;
	while (i++ < 4)
	{
		if (f[i](argv[2][0]) != 0)
			oper = f[i](argv[2][0]);
	}
	ft_print(per1, per2, oper);
	write(1, "\n", 1);
	return (0);
}

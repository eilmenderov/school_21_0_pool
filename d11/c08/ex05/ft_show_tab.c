/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:59:22 by avchar            #+#    #+#             */
/*   Updated: 2021/05/29 01:11:18 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	u_nb;

	if (nb < 0)
	{
		ft_putchar('-');
		u_nb = (unsigned int)(nb * (-1));
	}
	else
		u_nb = (unsigned int)nb;
	if ((u_nb / 10) != 0)
		ft_putnbr(u_nb / 10);
	ft_putchar((u_nb % 10) + '0');
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

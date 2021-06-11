/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaureen <tlaureen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:45:04 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/21 19:33:21 by tlaureen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	ft_rev_str(char *str)
{
	char	*p;
	char	t;

	p = str;
	while (*p != 0)
		p++;
	p--;
	while (str < p)
	{
		t = *str;
		*str = *p;
		*p = t;
		str++;
		p--;
	}
}

void	ft_putnbr(int nb)
{
	long long int	n;
	char			c[30];
	int				i;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = 0;
	while (n >= 0)
	{
		c[i++] = n % 10 + '0';
		n = n / 10;
		if (n == 0)
		{
			c[i] = 0;
			break ;
		}
	}
	ft_rev_str(c);
	ft_putstr(c);
}

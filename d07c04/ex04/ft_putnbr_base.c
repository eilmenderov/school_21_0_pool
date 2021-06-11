/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:04:08 by vleida            #+#    #+#             */
/*   Updated: 2021/03/09 19:13:28 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char *base)
{
	int i;
	int j;

	j = 0;
	while (base[j] && base[j] != 45 && base[j] != 43
			&& base[j] > 32 && base[j] < 127)
	{
		i = j;
		while (base[i])
		{
			if (base[j] == base[i + 1])
				return (0);
			i++;
		}
		j++;
	}
	if (j > 1)
		return (j);
	else
		return (0);
}

void	ft_print(int nb, int sis, char *base)
{
	if (nb == -2147483648)
	{
		ft_print(nb / sis, sis, base);
		ft_putchar(base[-(nb % sis)]);
	}
	else if (nb < 0)
	{
		ft_putchar(45);
		ft_print(-nb, sis, base);
	}
	else
	{
		if (nb / sis)
			ft_print(nb / sis, sis, base);
		ft_putchar(base[nb % sis]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int sis;

	sis = ft_check(base);
	if (sis != 0)
		ft_print(nbr, sis, base);
}

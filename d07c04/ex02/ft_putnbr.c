/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:50:15 by vleida            #+#    #+#             */
/*   Updated: 2021/03/10 09:47:15 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

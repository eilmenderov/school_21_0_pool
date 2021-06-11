/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:04:08 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/07 15:07:51 by tlaureen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char b);

void	rush(int x, int y)
{
	int i;
	int j;

	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			if ((i == x && j == y && j != 1 && i != 1) || (i == 1 && j == 1))
				ft_putchar('/');
			else if ((i == x && j == 1) || (i == 1 && j == y))
				ft_putchar('\\');
			else if (i == 1 || j == 1 || i == x || j == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

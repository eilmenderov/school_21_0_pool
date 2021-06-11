/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaureen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:07:41 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/07 16:42:41 by tlaureen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char b);

char	ft_usl(int x, int y, int j, int i)
{
	char s;

	s = ' ';
	if (i == 1 || i == x || j == 1 || j == y)
		s = 'B';
	if (i == x && j == y)
		s = 'A';
	if (j == 1 && i == x)
		s = 'C';
	if (i == 1 && j == y)
		s = 'C';
	if (i == 1 && j == 1)
		s = 'A';
	return (s);
}

void	rush(int x, int y)
{
	char	s;
	int		i;
	int		j;

	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			s = ft_usl(x, y, j, i);
			ft_putchar(s);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

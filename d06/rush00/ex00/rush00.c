/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:04:08 by tlaureen          #+#    #+#             */
/*   Updated: 2021/05/29 00:57:56 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char b);

char	ft_usl(int x, int y, int j, int i)
{
	char s;

	s = ' ';
	if (i == 1 || i == x)
		s = '|';
	if (j == 1 || j == y)
		s = '-';
	if ((i == x && j == y) || (i == 1 && j == 1))
		s = 'o';
	if ((j == 1 && i == x) || (j == y && i == 1))
		s = 'o';
	return (s);
}

void	rush(int x, int y)
{
	char	s;
	int		i;
	int		j;

	if (x <= 0 || y <= 0)
		return ;
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

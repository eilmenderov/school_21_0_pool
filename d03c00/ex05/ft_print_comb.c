/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:08:42 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 00:49:19 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	num[3];

	num[0] = '0';
	num[1] = '1';
	num[2] = '2';
	while (num[0] < num[1])
	{
		while (num[1] <= '9' && num[1] > num[0])
		{
			while (num[2] != ':' && num[2] > num[1])
			{
				write(1, &num, 3);
				if (num[0] >= '7')
					break ;
				write(1, ", ", 2);
				num[2]++;
			}
			num[2] = num[0] + 3;
			num[1]++;
		}
		num[1] = num[0] + 2;
		num[0]++;
	}
}
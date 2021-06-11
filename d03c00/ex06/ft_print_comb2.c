/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:30:52 by vleida            #+#    #+#             */
/*   Updated: 2021/03/04 13:19:41 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_print_comb2(void)
{
	int mas_1[100];
	int mas_2[100];
	int i;
	int j;

	i = 0;
	while (i <= 99)
	{
		mas_1[i] = i;
		i++;
	}
	i = 0;
	while (i <= 99)
	{
		mas_2[i] = i;
		i++;
	}
	i = 0;
	while (mas_1[i] <= 99)
	{
		j = i + 1;
		while (mas_1[j] <= 99)
		{
			if (mas_1[i] == 99 && mas_2[j] == 99)
				break ;
			if (mas_1[i] < mas_2[j])
				printf("%d %d,", mas_1[i], mas_2[j]);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	ft_print_comb2();
	return(0);
}
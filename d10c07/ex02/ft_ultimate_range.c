/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:29:28 by vleida            #+#    #+#             */
/*   Updated: 2021/03/12 20:14:01 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int razn;
	int i;
	int *mas_int;

	if (min >= max)
	{
		range = (void*)0;
		return (0);
	}
	if ((unsigned int)(max - min) > 2147483647)
		return (-1);
	razn = max - min;
	mas_int = (int*)malloc(sizeof(int) * razn);
	i = 0;
	while (i < razn)
	{
		mas_int[i] = min + i;
		i++;
	}
	*range = mas_int;
	return (razn);
}

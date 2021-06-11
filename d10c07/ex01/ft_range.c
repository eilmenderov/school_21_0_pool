/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:29:13 by vleida            #+#    #+#             */
/*   Updated: 2021/03/12 10:23:59 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int razn;
	int *mas_int;
	int i;

	if (min >= max)
		return (NULL);
	razn = max - min;
	mas_int = (int*)malloc(sizeof(int) * razn);
	i = 0;
	while (i < razn)
	{
		mas_int[i] = min + i;
		i++;
	}
	return (mas_int);
}

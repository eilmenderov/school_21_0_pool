/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:14:06 by vleida            #+#    #+#             */
/*   Updated: 2021/03/16 20:57:43 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int	i;
	int *rezult;

	rezult = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		rezult[i] = f(tab[i]);
		i++;
	}
	return (rezult);
}

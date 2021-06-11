/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:16:30 by vleida            #+#    #+#             */
/*   Updated: 2021/03/17 10:35:24 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int	k;

	k = 0;
	i = 0;
	while (tab[i] && i < length)
	{
		if (f(tab[i]))
			k++;
		i++;
	}
	return (k);
}

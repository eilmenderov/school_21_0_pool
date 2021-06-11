/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:55:03 by vleida            #+#    #+#             */
/*   Updated: 2021/03/10 16:38:46 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int del;

	if (nb < 2)
		return (0);
	del = 2;
	while (del != nb && (nb / del) + 1 > del)
	{
		if (nb % del == 0)
			return (0);
		del++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int a;

	if (nb < 2)
		nb = 2;
	a = ft_is_prime(nb);
	while (a != 1)
	{
		nb++;
		a = ft_is_prime(nb);
	}
	return (nb);
}

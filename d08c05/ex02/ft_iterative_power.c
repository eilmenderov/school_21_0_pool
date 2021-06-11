/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:52:52 by vleida            #+#    #+#             */
/*   Updated: 2021/03/10 15:27:49 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int rez;
	int i;

	rez = 1;
	i = 0;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (i < power)
	{
		rez = rez * nb;
		i++;
	}
	return (rez);
}

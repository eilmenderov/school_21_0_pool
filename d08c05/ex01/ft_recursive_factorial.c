/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:23:09 by vleida            #+#    #+#             */
/*   Updated: 2021/03/10 16:11:36 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int rez;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	rez = 1;
	if (nb)
		rez = nb * ft_recursive_factorial(nb - 1);
	return (rez);
}

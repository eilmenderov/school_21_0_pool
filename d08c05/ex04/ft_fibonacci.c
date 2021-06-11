/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:13:42 by vleida            #+#    #+#             */
/*   Updated: 2021/03/10 16:40:58 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int g_temp[100] = {0};

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	else
	{
		if (g_temp[index] == 0)
			g_temp[index] = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (g_temp[index]);
	}
}

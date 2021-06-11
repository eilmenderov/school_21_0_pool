/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_par1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:37:15 by vleida            #+#    #+#             */
/*   Updated: 2021/03/21 22:39:58 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ft.h"

void	ft_rek1(int *i, int *nul)
{
	*nul = 1;
	*i = *i + 1;
}

void	ft_rek2(int *a, int *b)
{
	*a = *a + 1;
	*b = *b - 1;
}

void	ft_zanull(int *num1, int *num2, int *num3)
{
	*num1 = 0;
	*num2 = 0;
	*num3 = 0;
}

char	*ft_atoi(char *str)
{
	int	i;
	int k;
	int nul;
	int numb;

	ft_zanull(&numb, &i, &nul);
	while (str[i] && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		ft_rek1(&i, &nul);
	k = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		ft_rek1(&i, &numb);
	str[i] = '\0';
	str = &str[k];
	if (nul == 1 && numb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		str = &str[0];
	}
	return (str);
}

int		ft_check_for_number(char *num)
{
	int i;

	i = 0;
	while (*num && (*num == ' ' || (*num > 8 && *num < 14)))
		num++;
	if (*num != '+' && (*num > '9' || *num < '0'))
		return (0);
	if (*num == '+')
		num++;
	if (*num > '9' || *num < '0')
		return (0);
	while (*num && *num <= '9' && *num >= '0')
	{
		if (i == 0 && *num <= '9' && *num >= '0')
			i = 1;
		num++;
	}
	while (*num)
	{
		if (i > 0 && *num != 9 && *num != 10 && *num != 11
				&& *num != 12 && *num != 13 && *num != 32)
			return (0);
		num++;
	}
	return (1);
}

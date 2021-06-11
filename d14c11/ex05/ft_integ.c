/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:24:16 by vleida            #+#    #+#             */
/*   Updated: 2021/03/17 16:46:07 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ft.h"

int		ft_step_rez(int chis, int step)
{
	int rez;
	int i;

	rez = 1;
	i = 0;
	if (step == 0)
		return (1);
	while (i < step)
	{
		rez = rez * chis;
		i++;
	}
	return (rez);
}

int		ft_creator(char *chis, int por, int znak)
{
	int rez;
	int i;

	rez = 0;
	i = 0;
	while (por > 0)
	{
		rez = rez - (chis[por - 1] - '0') * ft_step_rez(10, (i));
		por--;
		i++;
	}
	if (znak % 2 == 0)
		return (-rez);
	else
		return (rez);
}

int		ft_atoi(char *str)
{
	int		i;
	int		j;
	char	chis_s[11];
	int		num;

	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
	|| *str == '\f' || *str == '\r'))
		str++;
	i = 0;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			i++;
		str++;
	}
	j = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		chis_s[j] = *str;
		str++;
		j++;
	}
	num = ft_creator(chis_s, j, i);
	return (num);
}

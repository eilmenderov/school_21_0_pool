/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:13:53 by vleida            #+#    #+#             */
/*   Updated: 2021/03/17 15:01:28 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include <stdlib.h>
#include "my_ft.h"

int		ft_atoi(char *str)
{
	int		i;
	int		j;
	char	chis_s[11];
	int		num;

	i = 0;
	j = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		chis_s[j] = *str;
		str++;
		j++;
	}
	num = ft_creat_number(chis_s, j);
	return (num);
}

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

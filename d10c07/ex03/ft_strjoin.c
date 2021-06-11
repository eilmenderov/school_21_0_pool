/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:29:43 by vleida            #+#    #+#             */
/*   Updated: 2021/03/12 23:26:15 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		dlin(char **strs)
{
	int i;
	int j;
	int sum;

	sum = 0;
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			j++;
		sum = sum + j;
		i++;
	}
	return (sum);
}

int		mnoj(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int		strl(char *strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*rez;
	int		i;
	int		k;

	k = 0;
	if (size <= 0)
		return ((void*)0);
	rez = malloc(sizeof(char) * (strl(sep) * size + dlin(strs)) + 1);
	i = 0;
	while (i < mnoj(strs))
	{
		rez = ft_strcat(rez, strs[i]);
		if (i == size - 1 || strs[i][0] == '\0')
			break ;
		rez = ft_strcat(rez, sep);
		i++;
	}
	return (rez);
}

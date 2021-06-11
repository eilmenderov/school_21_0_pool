/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaureen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:45:09 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/14 18:01:12 by tlaureen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_find_ch(char c, char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if (c == *str)
			return (i);
		str++;
		i++;
	}
	return (-1);
}

int		ft_strlen(char *str, char *charset)
{
	int n;

	n = 0;
	while (*str != '\0' && (ft_find_ch(*str, charset) < 0))
	{
		str++;
		n++;
	}
	return (n);
}

char	*ft_strcpy(char *dest, char *src, char *charset)
{
	char *res;

	res = dest;
	while (1)
	{
		*dest = *src;
		if (*src == '\0' || (ft_find_ch(*src, charset) >= 0))
		{
			*dest = '\0';
			return (res);
		}
		src++;
		dest++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	char	*c[1000];
	int		i;
	int		j;

	i = 0;
	while (*str != 0)
	{
		if (ft_find_ch(*str, charset) < 0)
		{
			c[i] = malloc((ft_strlen(str, charset) + 1) * sizeof(char));
			ft_strcpy(c[i++], str, charset);
			str = str + ft_strlen(str, charset);
		}
		str++;
	}
	j = 0;
	res = malloc((i + 1) * sizeof(char *));
	while (j < i)
	{
		res[j] = c[j];
		j++;
	}
	res[j] = 0;
	return (res);
}

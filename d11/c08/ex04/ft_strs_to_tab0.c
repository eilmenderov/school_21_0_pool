/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:12:54 by glavende          #+#    #+#             */
/*   Updated: 2021/03/14 12:44:41 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	if ((dst = malloc(ft_strlen(src) + 1)) == NULL)
		return (NULL);
	while (*src)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = 0;
	return (dst);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*res;

	if ((res = malloc(sizeof(struct s_stock_str) * (ac + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].str = av[i];
		res[i].size = ft_strlen(av[i]);
		res[i].copy = ft_strdup(av[i]);
		i++;
	}
	res[i].str = NULL;
	return (res);
}

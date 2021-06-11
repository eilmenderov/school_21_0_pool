/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:16:02 by vlefford          #+#    #+#             */
/*   Updated: 2021/05/29 01:06:25 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

char					*ft_strcpy(char *dest, char *src)
{
	char *adress;

	adress = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (adress);
}

char					*ft_strdup(char *src)
{
	char *cpsrc;

	cpsrc = malloc(ft_strlen(src));
	if (cpsrc == NULL)
	{
		return (NULL);
	}
	return (ft_strcpy(cpsrc, src));
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int				iac;
	int				iav;
	t_stock_str		*strct;

	if (!(strct = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
	{
		return ((void *)0);
	}
	iac = 0;
	while (iac < ac)
	{
		iav = 0;
		while (av[iac][iav] != '\0')
			iav++;
		strct->size = iav;
		strct->str = av[iac];
		strct->copy = ft_strdup(av[iac]);
		strct++;
		iac++;
	}
	strct->str = 0;
	return (strct);
}

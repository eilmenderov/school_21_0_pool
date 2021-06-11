/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:33:03 by vleida            #+#    #+#             */
/*   Updated: 2021/03/18 17:33:32 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin;
	t_list	*buff;

	if (size <= 0)
		return (0);
	i = size - 1;
	while (i > -1)
	{
		buff = ft_create_elem(strs[i]);
		buff->next = begin;
		begin = buff;
		i--;
	}
	return (begin);
}

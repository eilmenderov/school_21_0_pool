/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:33:29 by vleida            #+#    #+#             */
/*   Updated: 2021/03/18 16:06:11 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;

	last = *begin_list;
	if (last)
	{
		while (last->next)
			last = last->next;
		last = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

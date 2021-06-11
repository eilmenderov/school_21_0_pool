/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:36:22 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:27:23 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist)
	{
		newlist->data = data;
		newlist->next = NULL;
	}
	return (newlist);
}

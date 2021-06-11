/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:36:22 by vleida            #+#    #+#             */
/*   Updated: 2021/03/18 14:33:56 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begining_list, void *data)
{
	t_list	*beg;

	beg = ft_create_elem(data);
	beg->next = *begining_list;
	*begining_list = beg;
}

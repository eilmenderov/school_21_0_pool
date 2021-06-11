/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:53:17 by vleida            #+#    #+#             */
/*   Updated: 2021/03/19 09:58:06 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *new;

	new = malloc(t_btree);
	if (new)
	{
		new->item = item;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
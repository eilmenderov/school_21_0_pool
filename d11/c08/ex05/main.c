/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:28:31 by avchar            #+#    #+#             */
/*   Updated: 2021/05/29 01:12:31 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	main(int argc, char **argv)
{
	(void)argc;
	ft_show_tab(ft_strs_to_tab(argc, argv));
	return (0);
}

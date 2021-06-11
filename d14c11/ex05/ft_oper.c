/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:22:41 by vleida            #+#    #+#             */
/*   Updated: 2021/03/17 16:27:20 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ft.h"

int	plus(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	minus(char c)
{
	if (c == '-')
		return (2);
	return (0);
}

int	umnog(char c)
{
	if (c == '*')
		return (3);
	return (0);
}

int	divis(char c)
{
	if (c == '/')
		return (4);
	return (0);
}

int	modul(char c)
{
	if (c == '%')
		return (5);
	return (0);
}

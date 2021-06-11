/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:51:16 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:06:20 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H
# include <stdlib.h>

typedef struct s_stock_str
{
int     size;
char    *str;
char    *copy;
}       t_stock_str;

#endif
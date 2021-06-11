/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:10:41 by vleida            #+#    #+#             */
/*   Updated: 2021/03/17 16:45:42 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FT_H
# define MY_FT_H

int		ft_chek_oper(char ar);
int		ft_step_rez(int chis, int step);
int		ft_creator(char *chis, int por, int znak);
int		ft_atoi(char *str);
int		plus(char c);
int		minus(char c);
int		umnog(char c);
int		divis(char c);
int		modul(char c);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_print(int per1, int per2, int a);
#endif

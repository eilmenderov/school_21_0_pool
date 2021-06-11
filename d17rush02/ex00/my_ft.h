/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:47:04 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:30:38 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FT_H
# define MY_FT_H

# include <unistd.h>
# include <fcntl.h>

void	ft_rek1(int *i, int *nul);
void	ft_rek2(int *a, int *b);
void	ft_zanull(int *num1, int *num2, int *num3);
char	*ft_atoi(char *str);
int		ft_check_for_number(char *num);
int		ft_strlen_num(char *str);
char	*ft_first_zero(char *buf, int text);
int		ft_unik_help(int text, int len, char *buf, char num);
int		ft_unik_help1(int text, int len, char *buf, char num);
void	ft_unik_all(int text, int len, char num);
char	uslowid(int n, char argv, char *dict);
void	ft_ifif(int *n, int *i, char argv, char *dict);
void	openfun(char *argv, int n, char *dict);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:10:41 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:26:03 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FT_H
# define MY_FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>
# include <libgen.h>
# include <stdlib.h>

# define SIZ 1

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_check_num(char *ar);
int		ft_step_rez(int chis, int step);
int		ft_creat_number(char *chis, int por);
void	ft_red_loop(int kol_but);
void	ft_rezult(char *arr, int kol_but, char *ar1);
void	ft_rezult_plus(char *arr, int kol_but, char *ar1);
void	pech(char *arr, int kol_but, char *last);
void	ft_check_op(int e, char *ar, char *ar1);
#endif

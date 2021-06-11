/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:54:04 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 20:42:57 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RUSH_H
# define __RUSH_H

# include <unistd.h>
# define N 4

typedef struct	s_task
{
	int all[N * N];
	int up[N];
	int down[N];
	int left[N];
	int right[N];
}				t_task;

int				check_task(int argc, char **argv);
void			make_task(t_task *task, char *str);
void			print_board(int arr[N][N]);
void			ft_putchar(char c);
void			make_arr(int arr[N][N]);
void			find_next(int arr[N][N], int i, int j);
int				check_x(int arr[N][N], int i, int j);
int				check_arr(int arr[N][N], t_task task);
int				check_arr_up(int arr[N][N], int res, int col);
int				check_arr_down(int arr[N][N], int res, int col);
int				check_arr_left(int arr[N][N], int res, int row);
int				check_arr_right(int arr[N][N], int res, int row);
int				check_space(char c);

#endif

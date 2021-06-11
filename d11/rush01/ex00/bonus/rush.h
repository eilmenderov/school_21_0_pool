/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:54:04 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 21:18:14 by cdarrell         ###   ########.fr       */
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

typedef struct	s_sky
{
	int find;
	int final;
	int v[N];
}				t_sky;

int				check_task(int argc, char **argv);
void			make_task(t_task *task, char *str);
void			print_board(t_sky arr[N][N]);
void			ft_putchar(char c);
void			make_arr_zero(t_sky arr[N][N]);
void			make_arr_first(t_sky arr[N][N]);
void			find_next(t_sky arr[N][N], int i, int j);
void			find_next_help(t_sky arr[N][N], int i, int j);
int				check_x(t_sky arr[N][N], int i, int j);
int				check_arr(t_sky arr[N][N], t_task task);
int				check_arr_up(t_sky arr[N][N], int res, int col);
int				check_arr_down(t_sky arr[N][N], int res, int col);
int				check_arr_left(t_sky arr[N][N], int res, int row);
int				check_arr_right(t_sky arr[N][N], int res, int row);
void			arr_no_all(t_sky arr[N][N], t_task task);
void			arr_check_one(t_sky arr[N][N], t_task task);
void			arr_check_gran(t_sky arr[N][N], t_task task);
void			make_arr_iskl_row_col(t_sky arr[N][N], int i, int j, int num);
void			arr_check_iskl_col(t_sky arr[N][N], int number);
void			arr_check_iskl_row(t_sky arr[N][N], int number);
void			make_arr_final(t_sky arr[N][N], int i, int j, int num);
int				check_space(char c);

#endif

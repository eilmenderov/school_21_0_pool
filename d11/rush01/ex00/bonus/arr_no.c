/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_no.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:56:14 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 19:21:02 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	arr_no_all(t_sky arr[N][N], t_task task)
{
	int number;
	int i;

	arr_check_one(arr, task);
	arr_check_gran(arr, task);
	i = -1;
	while (++i < N * 2)
	{
		number = 0;
		while (++number <= N)
		{
			arr_check_iskl_row(arr, number);
			arr_check_iskl_col(arr, number);
		}
	}
}

void	arr_check_one(t_sky arr[N][N], t_task task)
{
	int i;

	i = -1;
	while (++i < N)
	{
		if (task.up[i] == 1)
			make_arr_iskl_row_col(arr, 0, i, N);
		if (task.down[i] == 1)
			make_arr_iskl_row_col(arr, N - 1, i, N);
		if (task.left[i] == 1)
			make_arr_iskl_row_col(arr, i, 0, N);
		if (task.right[i] == 1)
			make_arr_iskl_row_col(arr, i, N - 1, N);
	}
}

void	arr_check_gran(t_sky arr[N][N], t_task task)
{
	int i;
	int number;
	int j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			number = 1;
			while (++number <= N)
			{
				if (task.up[i] + number > N + 1 + j)
					arr[j][i].v[number - 1] = 0;
				if (task.down[i] + number > N + 1 + j)
					arr[N - 1 - j][i].v[number - 1] = 0;
				if (task.left[i] + number > N + 1 + j)
					arr[i][j].v[number - 1] = 0;
				if (task.right[i] + number > N + 1 + j)
					arr[i][N - 1 - j].v[number - 1] = 0;
			}
		}
	}
}

void	make_arr_final(t_sky arr[N][N], int i, int j, int num)
{
	int z;

	arr[i][j].find = num;
	arr[i][j].final = num;
	z = -1;
	while (++z < N)
		arr[i][j].v[z] = 0;
}

void	make_arr_iskl_row_col(t_sky arr[N][N], int i, int j, int num)
{
	int i2;
	int j2;

	make_arr_final(arr, i, j, num);
	i2 = i;
	while (++i2 < N)
		arr[i2][j].v[num - 1] = 0;
	i2 = i;
	while (--i2 >= 0)
		arr[i2][j].v[num - 1] = 0;
	j2 = j;
	while (++j2 < N)
		arr[i][j2].v[num - 1] = 0;
	j2 = j;
	while (--j2 >= 0)
		arr[i][j2].v[num - 1] = 0;
}

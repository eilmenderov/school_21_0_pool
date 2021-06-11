/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:02:07 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 19:35:18 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	make_arr_zero(t_sky arr[N][N])
{
	int i;
	int j;
	int z;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			arr[i][j].find = 0;
			arr[i][j].final = 0;
			z = -1;
			while (++z < N)
				arr[i][j].v[z] = z + 1;
		}
	}
}

void	make_arr_first(t_sky arr[N][N])
{
	int i;
	int j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			if (arr[i][j].find == 0)
				find_next(arr, i, j);
	}
}

void	find_next_help(t_sky arr[N][N], int i, int j)
{
	if (j == 0)
		find_next(arr, i - 1, N - 1);
	else
		find_next(arr, i, j - 1);
}

void	find_next(t_sky arr[N][N], int i, int j)
{
	if (i == 0 && j == 0)
	{
		if (arr[i][j].final == 0)
			arr[i][j].find += 1;
		else
			arr[i][j].find = N + 1;
	}
	else
	{
		if (arr[i][j].final == 0)
		{
			if (arr[i][j].find == N)
			{
				arr[i][j].find = 0;
				find_next_help(arr, i, j);
				find_next(arr, i, j);
			}
			else
				arr[i][j].find += 1;
			if (!(check_x(arr, i, j)))
				find_next(arr, i, j);
		}
		else
			find_next_help(arr, i, j);
	}
}

int		check_x(t_sky arr[N][N], int i, int j)
{
	int i2;
	int j2;

	i2 = i;
	while (--i2 >= 0)
	{
		if (arr[i][j].find == arr[i2][j].find)
			return (0);
	}
	j2 = j;
	while (--j2 >= 0)
	{
		if (arr[i][j].find == arr[i][j2].find)
			return (0);
	}
	return (1);
}

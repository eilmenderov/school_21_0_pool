/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:02:07 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 00:46:43 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	make_arr(int arr[N][N])
{
	int i;
	int j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			arr[i][j] = 0;
	}
	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			find_next(arr, i, j);
	}
}

void	find_next(int arr[N][N], int i, int j)
{
	if (i == 0 && j == 0)
		arr[i][j] += 1;
	else
	{
		if (arr[i][j] == N)
		{
			arr[i][j] = 0;
			if (j == 0)
				find_next(arr, i - 1, N - 1);
			else
				find_next(arr, i, j - 1);
			find_next(arr, i, j);
		}
		else
			arr[i][j] += 1;
		if (!(check_x(arr, i, j)))
			find_next(arr, i, j);
	}
}

int		check_x(int arr[N][N], int i, int j)
{
	int i2;
	int j2;

	i2 = i;
	while (--i2 >= 0)
	{
		if (arr[i][j] == arr[i2][j])
			return (0);
	}
	j2 = j;
	while (--j2 >= 0)
	{
		if (arr[i][j] == arr[i][j2])
			return (0);
	}
	return (1);
}

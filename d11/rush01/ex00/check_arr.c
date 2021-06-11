/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:52:32 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 00:28:22 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_arr(int arr[N][N], t_task task)
{
	int i;

	i = -1;
	while (++i < N)
	{
		if (!check_arr_up(arr, task.up[i], i))
			return (0);
		if (!check_arr_down(arr, task.down[i], i))
			return (0);
		if (!check_arr_left(arr, task.left[i], i))
			return (0);
		if (!check_arr_right(arr, task.right[i], i))
			return (0);
	}
	return (1);
}

int	check_arr_up(int arr[N][N], int res, int col)
{
	int i;
	int k;
	int max;

	max = 0;
	k = 0;
	i = -1;
	while (++i < N)
	{
		if (max < arr[i][col])
		{
			max = arr[i][col];
			k++;
		}
	}
	if (res == k)
		return (1);
	else
		return (0);
}

int	check_arr_down(int arr[N][N], int res, int col)
{
	int i;
	int k;
	int max;

	max = 0;
	k = 0;
	i = N;
	while (--i >= 0)
	{
		if (max < arr[i][col])
		{
			max = arr[i][col];
			k++;
		}
	}
	if (res == k)
		return (1);
	else
		return (0);
}

int	check_arr_left(int arr[N][N], int res, int row)
{
	int j;
	int k;
	int max;

	max = 0;
	k = 0;
	j = -1;
	while (++j < N)
	{
		if (max < arr[row][j])
		{
			max = arr[row][j];
			k++;
		}
	}
	if (res == k)
		return (1);
	else
		return (0);
}

int	check_arr_right(int arr[N][N], int res, int row)
{
	int j;
	int k;
	int max;

	max = 0;
	k = 0;
	j = N;
	while (--j >= 0)
	{
		if (max < arr[row][j])
		{
			max = arr[row][j];
			k++;
		}
	}
	if (res == k)
		return (1);
	else
		return (0);
}

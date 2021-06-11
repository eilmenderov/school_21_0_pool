/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_no_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:11:32 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 19:15:41 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	arr_check_iskl_col(t_sky arr[N][N], int number)
{
	int i;
	int j;
	int k;
	int i2;

	j = -1;
	while (++j < N)
	{
		k = 0;
		i = -1;
		while (++i < N)
		{
			if (arr[i][j].v[number - 1] == number)
			{
				i2 = i;
				k++;
			}
		}
		if (k == 1)
			make_arr_iskl_row_col(arr, i2, j, number);
	}
}

void	arr_check_iskl_row(t_sky arr[N][N], int number)
{
	int i;
	int j;
	int k;
	int j2;

	i = -1;
	while (++i < N)
	{
		k = 0;
		j = -1;
		while (++j < N)
		{
			if (arr[i][j].v[number - 1] == number)
			{
				j2 = j;
				k++;
			}
		}
		if (k == 1)
			make_arr_iskl_row_col(arr, i, j2, number);
	}
}

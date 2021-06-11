/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:52:51 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 21:18:07 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		main(int argc, char **argv)
{
	t_sky	arr[N][N];
	t_task	task;

	if (check_task(argc, argv))
	{
		make_task(&task, argv[1]);
		make_arr_zero(arr);
		arr_no_all(arr, task);
		make_arr_first(arr);
		while (arr[0][0].find <= N)
		{
			if (check_arr(arr, task))
			{
				print_board(arr);
				return (0);
			}
			else
				find_next(arr, N - 1, N - 1);
		}
		write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}

void	print_board(t_sky arr[N][N])
{
	int i;
	int j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			ft_putchar(arr[i][j].find + '0');
			if (j < N - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:56:37 by cdarrell          #+#    #+#             */
/*   Updated: 2021/03/14 21:19:29 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_space(char c)
{
	if (c != '\0')
	{
		if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

int		check_task(int argc, char **str)
{
	int i;
	int k;

	if (argc != 2)
		return (0);
	else
	{
		k = 0;
		i = -1;
		while (str[1][++i])
		{
			if (!(check_space(str[1][i])))
			{
				if ((str[1][i] >= '1' && str[1][i] <= N + '0') &&
				(str[1][i + 1] == '\0' || check_space(str[1][i + 1])))
					k++;
				else
					return (0);
			}
		}
	}
	if (N * 4 == k)
		return (k);
	else
		return (0);
}

void	make_task(t_task *task, char *str)
{
	int i;
	int kk;

	i = 0;
	kk = 0;
	while (*(str + i))
	{
		if (!(str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		{
			if (kk < N)
				task->up[kk] = *(str + i) - '0';
			else if (kk < 2 * N)
				task->down[kk - N] = *(str + i) - '0';
			else if (kk < 3 * N)
				task->left[kk - 2 * N] = *(str + i) - '0';
			else if (kk < 4 * N)
				task->right[kk - 3 * N] = *(str + i) - '0';
			task->all[kk] = *(str + i) - '0';
			kk++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:34:39 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:32:20 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ft.h"

char	uslowid(int n, char argv, char *dict)
{
	int text;

	text = open(dict, O_RDONLY);
	ft_unik_all(text, n, argv);
	close(text);
	write(1, " ", 1);
	argv = '1';
	return (argv);
}

void	ft_ifif(int *n, int *i, char argv, char *dict)
{
	if ((*n > 2 && (*n - 1) % 3 == 0) || (*n % 3 == 0))
		argv = uslowid(1, argv, dict);
	if ((*n > 2 && (*n - 1) % 3 != 0) && (*n % 3 != 0))
		argv = uslowid(2, argv, dict);
	if (*n > 3 && *n % 3 == 0)
		uslowid(3, argv, dict);
	if (((*n - 1) % 3 == 0) || *n <= 4)
		uslowid(*n, argv, dict);
	ft_rek2(i, n);
}

void	openfun(char *argv, int n, char *dict)
{
	int i;

	i = 0;
	while (n != 0)
	{
		if (argv[i] == '0' && i != 0)
		{
			if (argv[i] == '0' && (argv[i - 1] != '0' || argv[i - 2] !=
						'0') && (n - 1) % 3 == 0 && n != 1)
				argv[i] = uslowid(n, '1', dict);
			ft_rek2(&i, &n);
			continue;
		}
		if (argv[i] == '1' && (n == 2 || (n - 2) % 3 == 0))
		{
			i++;
			uslowid((-1), argv[i], dict);
			ft_rek2(&i, &n);
			if (n != 1)
				uslowid(n, '1', dict);
			n--;
			continue;
		}
		ft_ifif(&n, &i, argv[i], dict);
	}
}

int		main(int argc, char **argv)
{
	char	*st_dict;
	char	*number;
	int		len;

	if (argc == 1 || (argc == 2 && ft_check_for_number(argv[1]) == 0) ||
		(argc >= 3 && ft_check_for_number(argv[2]) == 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		st_dict = "numbers.dict";
	if (argc >= 3)
		st_dict = argv[1];
	number = ft_atoi(argv[1]);
	len = ft_strlen_num(number);
	openfun(number, len, st_dict);
	write(1, "\n", 1);
	return (0);
}

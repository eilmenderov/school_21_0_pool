/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:24:31 by vleida            #+#    #+#             */
/*   Updated: 2021/03/16 18:41:26 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define SIZ 1

int	main(int argc, char *argv[])
{
	int		fchek;
	char	buffer;

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fchek = open(argv[1], O_RDONLY);
	if (fchek == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (read(fchek, &buffer, SIZ) != 0)
		write(1, &buffer, SIZ);
	return (close(fchek));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:26:39 by vleida            #+#    #+#             */
/*   Updated: 2021/03/07 20:11:24 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	m;

	n = ft_strlen(src);
	m = ft_strlen(dest);
	if (size == 0)
		return (n + m);
	i = 0;
	while (*dest)
	{
		dest++;
		i++;
	}
	while (i < (size - 1) && *src)
	{
		*dest = *src;
		i++;
		src++;
		dest++;
	}
	dest[i] = '\0';
	return (n + m);
}

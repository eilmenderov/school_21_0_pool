/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:08:12 by vleida            #+#    #+#             */
/*   Updated: 2021/03/09 17:30:48 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;

	i = 0;
	while (*dest)
		dest++;
	while (i < nb && *src)
	{
		*dest = *src;
		i++;
		src++;
		dest++;
	}
	dest = dest[0];
	return (dest);
}

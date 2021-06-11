/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avchar <avchar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:19:48 by vleida            #+#    #+#             */
/*   Updated: 2021/05/29 01:27:04 by avchar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp) (char *, char *))
{
	int		i;
	char	*temp;
	int		j;

	i = 1;
	while (tab[i])
	{
		j = i;
		while (j > 0 && cmp(tab[j - 1], tab[j]) > 0)
		{
			temp = tab[j - 1];
			tab[j - 1] = tab[j];
			tab[j] = temp;
			j--;
		}
		i++;
	}
}

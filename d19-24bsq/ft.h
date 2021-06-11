/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:24:24 by tlaureen          #+#    #+#             */
/*   Updated: 2021/03/25 11:24:54 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//# define malloc(x) NULL
# define MALSIZ 300000

typedef struct	s_data
{
	long long int	found_x;
	long long int	found_y;
	long long int	found_size;
	long long int	width;
	long long int	heght;
	char			empty;
	char			obstacle;
	char			full;
	char			*filename;
}				t_data;

typedef struct	s_coord
{
	long long int	x;
	long long int	y;
	long long int	size;
}				t_coord;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
void			ft_putnbr(int nb);

int				ft_number(char *stri, t_data *data);
int				ft_frfstr(char *fstr);
void			ft_pull_data(t_data *data, char *fstr, int i);
int				ft_chek_sumb(t_data *data);
int				ft_check_arrfl(t_data *data, int pot, int *i, char *newline);
int				ft_read_map(char ***map, t_data *data);
void			ft_print_map(char **map, t_data *data);
void			ft_check_sqare(char **map, t_data *data, unsigned int x,
								unsigned int y, unsigned int size);
void			ft_solve_map(char **map, t_data *data);

#endif

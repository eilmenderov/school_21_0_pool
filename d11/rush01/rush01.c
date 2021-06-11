#include <unistd.h>
#include <stdio.h>
#define st_kv 7 //6
#define perim 20 //16

void	ft_obnul(int mas[st_kv][st_kv], int mas_1[perim])
{
	int i;
	int j;

	i = 0;
	while (i < st_kv)
	{
		j = 0;
		while(j < st_kv)
		{
			mas[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 1;
	j = 0;
	while (i < (st_kv - 1) && j < (perim / 4))
	{
		mas[0][i] = mas_1[j];
		i++;
		j++;
	}
}

void	ft_podgot(int mas_2[st_kv][st_kv], int mas_1[perim])
{
	int i;
	int k;

	i = 1;
	k = perim / 4;
	while (i < (st_kv - 1) && k < perim)
	{
		mas_2[st_kv - 1][i] = mas_1[k];
		i++;
		k++;
	}
	i = 1;
	while (i < (st_kv - 1) && k < perim)
	{
		mas_2[i][0] = mas_1[k];
		i++;
		k++;
	}
	i = 1;
	while (i < (st_kv - 1) && k < perim)
	{
		mas_2[i][st_kv - 1] = mas_1[k];
		i++;
		k++;
	}
}

void	ft_zap_1_n_ud(int mas[st_kv][st_kv])
{
	int i;

	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[0][i] == 1)
			mas[1][i] = st_kv - 2;
		i++;
	}
	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[st_kv - 1][i] == 1)
			mas[st_kv - 2][i] = st_kv - 2;
		i++;
	}
}

void	ft_zap_1_n_lr(int mas[st_kv][st_kv])
{
	int i;

	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[i][0] == 1)
			mas[i][1] = st_kv - 2;
		i++;
	}
	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[i][st_kv - 1] == 1)
			mas[i][st_kv - 2] = st_kv - 2;
		i++;
	}
}

void	ft_zap_n_ud(int mas[st_kv][st_kv])
{
	int i;
	int j;

	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[0][i] == st_kv - 2)
		{
			j = 0;
			while (j++ < st_kv - 2)
				mas[j][i] = j;
		}
		i++;
	}
	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[st_kv - 1][i] == st_kv - 2)
		{
			j = st_kv - 1;
			while (j-- > 0)
				mas[j][i] = (st_kv - 1) - j;
		}
		i++;
	}
}

void	ft_zap_n_lr(int mas[st_kv][st_kv])
{
	int i;
	int j;

	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[i][0] == st_kv - 2)
		{
			j = 0;
			while (j++ < st_kv - 2)
				mas[i][j] = j;
		}
		i++;
	}
	i = 1;
	while (i < st_kv - 1)
	{
		if (mas[i][st_kv - 1] == st_kv - 2)
		{
			j = st_kv - 2;
			while (j-- > 0)
				mas[i][j] = (st_kv - 1) - j;
		}
		i++;
	}
}

void	ft_vuv_zag(int mas_vuv[st_kv - 2][st_kv - 2], int mas2[st_kv][st_kv])
{
	int i;
	int j;

	i = 0;
	while (i++ < st_kv - 1)
	{
		j = 0;
		while (j++ < st_kv -1)
			mas_vuv[i - 1][j - 1] = mas2[i][j];
	}
}

int		main(void)
{
	int mas2[st_kv][st_kv];
	int mas1[perim] = {3, 1, 3, 2, 3, 1, 2, 3, 4, 2, 2, 3, 2, 4, 1, 3, 2, 3, 1, 3};
	int mas_vuv[st_kv - 2][st_kv - 2];
	int mas1_1[perim] = {2, 3, 1, 3, 2, 1, 4, 2, 2, 1, 3, 2, 2, 3, 1, 2};
	int i;
	int j;

	ft_obnul(mas2, mas1);
	ft_podgot(mas2, mas1);
	ft_zap_n_ud(mas2);
	ft_zap_n_lr(mas2);
	ft_zap_1_n_ud(mas2);
	ft_zap_1_n_lr(mas2);
	ft_vuv_zag(mas_vuv, mas2);
	i = 0;
	while (i < st_kv)
	{
		j = 0;
		while(j < st_kv)
		{
			if (j == st_kv - 1)
				printf("|");
			printf(" %d ", mas2[i][j]);
			if (j == 0)
				printf("|");
			j++;
		}
		if (i == 0)
			printf("\n- - - - - - - - - -");
		printf("\n");
		if (i == st_kv - 2)
			printf("- - - - - - - - - -\n");
		i++;
	}
	
	i = -1;
	while (++i < st_kv - 2)
	{
		j = -1;
		while (++j < st_kv - 2)
		{
			printf(" %d", mas_vuv[i][j]);
		}
		printf("\n");
	}

	return (0);
}

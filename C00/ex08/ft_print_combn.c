/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:19:26 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_comb(char comb[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
}

void	ft_edit(char comb[], int n)
{
	int	i;
	int	j;

	i = n - 1;
	j = 0;
	while (i)
	{
		if (comb[i] == 10 - j)
		{
			comb[i] = 0;
			comb[i - 1]++;
		}
		i--;
		j++;
	}
	while (i < j)
	{
		if (comb[i] >= comb[i + 1])
			comb[i + 1] = comb[i] + 1;
		i++;
	}
}

void	ft_print(char comb[], int n)
{
	int	i;
	int	nb;

	i = 0;
	while (i < n)
	{
		nb = comb[i] + '0';
		write(1, &nb, 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n < 10 && n > 0)
	{
		ft_first_comb(comb, n);
		while (comb[0] < 10 - n)
		{
			if (comb[n - 1] == 10)
				ft_edit(comb, n);
			ft_print(comb, n);
			if (comb[0] != 10 - n)
			{
				write(1, ", ", 2);
				if (comb[0] == 8 && n == 1)
					write(1, "9", 1);
			}
			comb[n - 1]++;
		}
	}
}

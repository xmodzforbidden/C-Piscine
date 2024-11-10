/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:30:28 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	char	number[32];
	int		n_base;
	int		i;

	i = 0;
	n = nbr;
	n_base = ft_check(base);
	if (n_base >= 2)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		if (n == 0)
			write(1, &base[0], 1);
		while (n)
		{
			number[i++] = base[n % n_base];
			n /= n_base;
		}
		while (i)
			write(1, &number[--i], 1);
	}
}
/*
#include <stdlib.h>
int main (int ac , char *av[])
{
	ft_putnbr_base(atoi(av[1]),av[2]);
} */

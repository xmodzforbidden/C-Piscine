/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:17:01 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
		if (base[i] == '-' || base[i] == ' ' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

int	ft_str_in_base(char c, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (j);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	sign;
	int	n_base;

	n = 0;
	sign = 1;
	n_base = ft_check(base);
	if (n_base > 1)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (ft_str_in_base(*str, base) != -1)
		{
			n = n * n_base + ft_str_in_base(*str, base);
			str++;
		}
	}
	return (n * sign);
}
/*
int main (int ac ,char *av[])
{
	int n;

	n = -1;
	if (ac == 3)
		n = ft_atoi_base(av[1],av[2]);
	printf("%d \n", n);
}*/

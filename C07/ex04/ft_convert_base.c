/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:57:00 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbr_check(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if ((base[i] >= 9 && base[i] < 13) || base[i] == 32 || \
			base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

char	*ft_putnbr_base(int nbr, char *base, int n_base, char *nb)
{
	int		i;
	int		j;
	char	number[34];
	long	n;

	i = 0;
	j = 0;
	n = nbr;
	if (n < 0)
	{
		n = -n;
		nb[j++] = '-';
	}
	if (n == 0)
		nb[j++] = base[0];
	while (n)
	{
		number[i++] = base[n % n_base];
		n /= n_base;
	}
	while (i)
		nb[j++] = number[--i];
	nb[j] = '\0';
	return (nb);
}

int	ft_atoi_base(char *nbr, char *base, int n_base)
{
	long	n;
	long	sign;

	sign = 1;
	n = 0;
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (ft_nbr_check(*nbr, base) != -1)
	{
		n = n * n_base + ft_nbr_check(*nbr, base);
		nbr++;
	}
	n *= sign;
	return ((int)n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		fn_base;
	int		tn_base;
	char	*nb;
	int		number;

	fn_base = ft_check(base_from);
	tn_base = ft_check(base_to);
	if (fn_base < 2 || tn_base < 2)
		return (NULL);
	nb = malloc(34);
	if (nb == NULL)
		return (NULL);
	number = ft_atoi_base(nbr, base_from, fn_base);
	nb = ft_putnbr_base(number, base_to, tn_base, nb);
	return (nb);
}
/*
#include <stdio.h>

int main (int ac, char *av[])
{
	char *p;
	//p = malloc(34);
	p = ft_convert_base(av[1], av[2], av[3]);
	printf("%s \n", p);
	//printf("%s", ft_putnbr_base(atoi(av[1]), av[2], atoi(av[3]), p));
}*/

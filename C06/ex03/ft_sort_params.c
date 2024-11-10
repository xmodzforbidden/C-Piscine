/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:44:51 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_str(char *av[], int ac)
{
	int		i;
	char	*p;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i + 1], av[i]) < 0)
		{
			p = av[i];
			av[i] = av[i + 1];
			av[i + 1] = p;
			i = 1;
		}
		else
			i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		ft_sort_str(av, ac);
		while (i < ac)
		{
			ft_putstr(av[i++]);
			write(1, "\n", 1);
		}
	}
}

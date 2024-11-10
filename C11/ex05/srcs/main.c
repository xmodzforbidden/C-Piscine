/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:12:08 by azaki             #+#    #+#             */
/*   Updated: 2024/07/24 16:12:29 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	main(int ac, char *av[])
{
	int	(*p[5])(int, int);
	int	op;

	p[0] = &ft_add;
	p[1] = &ft_sub;
	p[2] = &ft_mult;
	p[3] = &ft_div;
	p[4] = &ft_mod;
	if (ac == 4)
	{
		op = ft_selecte_op(av[2]);
		if (op == -1)
		{
			write(1, "0\n", 2);
			return (0);
		}
		ft_do_op(ft_atoi(av[1]), op, p[op], ft_atoi(av[3]));
	}
}

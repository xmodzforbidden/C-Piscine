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

void	ft_do_op(int n1, int op, int (*p)(int, int), int n2)
{
	int	res;

	if (op == 3 && n2 == 0)
		write(1, "Stop : division by zero", 23);
	else if (op == 4 && n2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
	{
		res = p(n1, n2);
		ft_putnbr(res);
	}
	write(1, "\n", 1);
}

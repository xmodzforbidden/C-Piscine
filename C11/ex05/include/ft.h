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

#ifndef FT_H
# define FT_H
# include <unistd.h>

int		ft_selecte_op(char *str);
void	ft_putnbr(int nb);
void	ft_do_op(int n1, int op, int (*p)(int, int), int n2);
int		ft_atoi(char *str);
int		ft_mod(int x, int y);
int		ft_mult(int x, int y);
int		ft_sub(int x, int y);
int		ft_div(int x, int y);
int		ft_add(int x, int y);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:11:00 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_array(int *bord)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = bord[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_safe(int *bord, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (bord[i] == row)
			return (0);
		else if (bord[i] + (col - i) == row)
			return (0);
		else if (bord[i] - (col - i) == row)
			return (0);
		i++;
	}
	return (1);
}

void	ft_slov(int *solutions, int *bord, int col)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		ft_print_array(bord);
		(*solutions)++;
		return ;
	}
	while (row < 10)
	{
		if (ft_safe(bord, row, col))
		{
			bord[col] = row;
			ft_slov(solutions, bord, col + 1);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solutions;
	int	bord[10];

	solutions = 0;
	ft_slov(&solutions, bord, 0);
	return (solutions);
}
/*
int main ()
{
	ft_ten_queens_puzzle();
}
*/

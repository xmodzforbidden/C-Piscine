/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:19:39 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*array;
	int	i;

	size = max - min;
	i = 0;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	array = malloc(4 * size);
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
		array[i++] = min++;
	*range = array;
	return (size);
}
/*
#include <stdio.h>

int main(int ac, char *av[])
{
	int	*range;
	int n1;
	int n2;

	n1 = atoi(av[1]);
	n2 = atoi(av[2]);
	ft_ultimate_range(&range, n1, n2);
	for (int i = 0; i < n2 - n1; i++)
		printf("| %d |",range[i]);
}*/

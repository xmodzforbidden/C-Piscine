/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:51:03 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	i;

	size = max - min ;
	i = 0;
	if (size <= 0)
		return (NULL);
	range = malloc(4 * size);
	if (range == NULL)
		return (NULL);
	while (min < max)
		range[i++] = min++;
	return (range);
}
/*
#include <stdio.h>

int main(int ac, char *av[])
{
	int *list;
	int n1;
	int n2;

	n1 = atoi(av[1]);
	n2 = atoi(av[2]);
	list = ft_range(n1, n2);
	for (int i = 0; i < n2 - n1; i++)
		printf("| %d |",list[i]);
}*/

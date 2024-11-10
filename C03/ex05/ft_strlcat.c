/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:30:02 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ij;

	ij = 0;
	j = 0;
	i = 0;
	while (src[i])
		i++;
	while (dest[j] && j < size)
		j++;
	if (size == j)
		return (i + j);
	if (j < size - 1)
	{
		while (src[ij] && (j + ij) < size - 1)
		{
			dest[j + ij] = src[ij];
			ij++;
		}
	}
	dest[j + ij] = 0;
	return (i + j);
}

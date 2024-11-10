/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:07:48 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_counter(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (ft_check_charset(str[i], charset))
			i++;
		if (str[i])
			counter++;
		while (!ft_check_charset(str[i], charset) && str[i])
			i++;
	}
	return (counter);
}

char	*ft_strdup(char *str, char *charset)
{
	int		len;
	int		i;
	char	*s;

	len = 0;
	i = 0;
	while (!ft_check_charset(str[len], charset) && str[len])
		len++;
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		w_counter;
	int		i;
	int		j;

	w_counter = ft_word_counter(str, charset);
	i = 0;
	j = 0;
	array = (char **)malloc(8 * w_counter + 8);
	if (array == NULL)
		return (NULL);
	while (str[j])
	{
		while (ft_check_charset(str[j], charset))
			j++;
		if (str[j])
			array[i++] = ft_strdup(str + j, charset);
		while (!ft_check_charset(str[j], charset) && str[j])
			j++;
	}
	array[i] = NULL;
	return (array);
}
/*
#include <stdio.h>

int main(int ac, char *av[])
{
	int n;
	char **p;
	int i;
	i = 0;
	n = ft_word_counter(av[1], av[2]);
	printf("%d \n", n);
	p = ft_split(av[1], av[2]);
	while (p[i] != NULL)
	{
		printf("%s \n", p[i]);
		i++;
	}
}*/

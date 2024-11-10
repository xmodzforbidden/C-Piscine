/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:44:47 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex_memory(void *addr)
{
	char			hex[16];
	unsigned long	add;
	int				i;

	i = 0;
	add = (unsigned long)addr;
	while (i < 16)
	{
		hex[i] = "0123456789abcdef"[add % 16];
		add /= 16;
		i++;
	}
	while (i--)
		write(1, &hex[i], 1);
	write(1, ": ", 2);
}

void	ft_print_str(char *str, void *addr, unsigned int size)
{
	unsigned int	des;
	unsigned int	i;
	unsigned char	c;

	des = (unsigned int)((void *)str - addr);
	i = 0;
	while (i < 16 && des + i < size)
	{
		c = (unsigned char)str[i];
		if (c >= ' ' && c < 127)
		{
			write(1, &c, 1);
		}
		else
			write(1, ".", 1);
		i++;
	}
}

void	ft_print_line(char *str, void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	des;

	i = 0;
	des = (unsigned int)((void *)str - addr);
	ft_print_hex_memory((void *)str);
	while (i < 16)
	{
		if (des + i < size)
		{
			write(1, &"0123456789abcdef"[str[i] / 16], 1);
			write(1, &"0123456789abcdef"[str[i] % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	ft_print_str(str, addr, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*str;

	str = (char *)addr;
	if (size > 0)
	{
		while ((unsigned long)str <= (unsigned long)(addr) + \
		(unsigned long)size)
		{
			ft_print_line(str, addr, size);
			write(1, "\n", 1);
			str += 16;
		}
	}
	return (addr);
}

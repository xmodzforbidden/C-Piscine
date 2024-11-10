/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:51:43 by azaki             #+#    #+#             */
/*   Updated: 2024/11/10 10:55:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	ft_to_uppercase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	return (*c);
}

int	ft_check(char *c1)
{
	if (*c1 >= 'a' && *c1 <= 'z')
		return (1);
	else if (*c1 >= 'A' && *c1 <= 'Z')
		return (1);
	else if (*c1 >= '0' && *c1 <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	ft_strlowercase(str);
	ft_to_uppercase(str);
	while (str[i])
	{
		if (!ft_check(str + i - 1) && ft_check(str + i))
			ft_to_uppercase(str + i);
		i++;
	}
	return (str);
}

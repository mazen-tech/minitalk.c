/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:43:41 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/14 13:43:44 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	l;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	l = ft_strlen(str);
	write(1, str, l);
	return (l);
}

int	ft_putnumb(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	len = ft_putstr(str);
	free (str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:46:55 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:57 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len ++;
	}
	return (len);
}

void	ft_printhex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_printhex(n / 16, format);
		ft_printhex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((n - 10 + 'a'));
			if (format == 'X')
				ft_putchar((n - 10 + 'A'));
		}
	}
}

int	ft_puthexadecimal(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhex(num, type);
	return (ft_hexlen(num));
}

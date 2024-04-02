/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/14 09:20:47 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		c = c - ('A' - 'a');
		return (c);
	}
	else
	{
		return (c);
	}
}
/*int	main()
{
	ft_putchar_fd(ft_tolower('C'), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(ft_tolower('A'), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(ft_tolower('z'), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(ft_tolower('4'), 1);
	ft_putchar_fd('\n', 1);
}*/

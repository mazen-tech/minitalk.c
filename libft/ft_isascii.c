/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 12:03:14 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int a)
{
	return (a >= 0 && a <= 127);
}
/*int	main()
{
	ft_putnbr_fd(ft_isascii(50), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isascii(100), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isascii(190), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isascii(200), 1);
	ft_putchar_fd('\n', 1);
}*/

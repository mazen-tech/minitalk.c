/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 12:04:54 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int p)
{
	return (p >= 32 && p <= 126);
}
/*int	main()
{
	ft_putnbr_fd(ft_isprint(45), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isprint(19), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isprint(127), 1);
	ft_putchar_fd('\n', 1);
}*/

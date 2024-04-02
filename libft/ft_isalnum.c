/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 12:00:07 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int n)
{
	return ((ft_isalpha(n) || ft_isdigit(n)));
}

/*int main()
{
	ft_putnbr_fd(ft_isalnum('1'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('A'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('F'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('1'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('5'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('x'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('\n'), 1);
	ft_putchar_fd('\n', 1);
}*/

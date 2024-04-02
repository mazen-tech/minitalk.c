/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 12:32:22 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dprt;
	const unsigned char	*sptr;

	dprt = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	if (!src && ! dest)
	{
		return (dest);
	}
	if (dest < src)
	{
		return (ft_memcpy(dest, src, n));
	}
	while (n--)
	{
		dprt[n] = sptr[n];
	}
	return (dest);
}
/*int main()
{
	char	str[] = "mazen tarek is student";
	char	dest[1];
	ft_putstr_fd(ft_memmove(dest, str, 10), 1);
	ft_putchar_fd('\n', 1);
}*/

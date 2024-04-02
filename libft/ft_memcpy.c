/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 12:26:53 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	if (!src && !dest)
	{
		return (dest);
	}
	while (n > 0)
	{
		*dptr++ = *sptr++;
		n--;
	}
	return (dest);
}
/*int main()
{
	char	str[] = "Mazen tarek";
	char	dest[18];
	ft_putstr_fd(ft_memcpy(dest, str, 11), 1);
	ft_putchar_fd('\n', 1);
}*/

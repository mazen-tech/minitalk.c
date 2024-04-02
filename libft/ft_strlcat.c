/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 14:03:12 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s;
	size_t	dlen;
	size_t	di;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dest && size == 0)
		return (slen);
	dlen = ft_strlen(dest);
	di = dlen;
	if (size <= di)
		return (size + slen);
	s = 0;
	while (src[s] && dlen + 1 < size)
	{
		dest[dlen] = src[s];
		s++;
		dlen++;
	}
	dest[dlen] = 0;
	return (di + slen);
}
/*int	main()
{
	char	dest[40] = "You won't even see me!";
	char	src[] = "Not even me, but you'll know our size!";
	ft_putnbr_fd(ft_strlcat(dest, src, 15), 1);
	ft_putchar_fd('\n', 1);
	printf("%s", dest);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 12:20:45 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t depth)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)arr;
	c = (unsigned char) c;
	while (*ptr != c && depth)
	{
		ptr++;
		depth--;
	}
	if (depth)
	{
		return ((void *)ptr);
	}
	else
	{
		return (NULL);
	}
}
/*int	main()
{
	char str[] = "mazen studying @42warsaw";
	char c = '@';
	ft_putstr_fd(ft_memchr(str, c, ft_strlen(str)), 1);
	ft_putchar_fd('\n', 1);
}*/

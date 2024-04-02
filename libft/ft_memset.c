/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/08 10:12:39 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memset( void *s1, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s1;
	i = 0;
	if (!ptr)
		return (NULL);
	while (n > i)
	{
		ptr[i] = c;
		i++;
	}
	return (s1);
}
/*int main()
{
	char	str[] = "mazen";
	char	c = 'u';
	ft_putstr_fd(ft_memset(str + 2, c, 2), 1);
	ft_putchar_fd('\n', 1);
}*/

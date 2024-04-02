/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/08 10:07:54 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (*big && n <= len)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
		{
			return ((char *)big);
		}
		++big;
		--len;
	}
	return (NULL);
}
/*int	main()
{
	char	str[] = ""I'm going";
	char	str1[] = "going";
	ft_putendl_fd(ft_strnstr(str, str1, ft_strlen(str)), 1);
}*/

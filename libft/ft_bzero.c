/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:52 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/07 11:56:35 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sptr;

	sptr = s;
	while (n)
	{
		*sptr++ = 0;
		n--;
	}
}

/*
int main(){

    char *ptr = NULL;
    ft_bzero(ptr, 10);

    // Test Size zero
    char test0[] = "Test";
    ft_bzero(test0, 0);
    return 0;
}

*/

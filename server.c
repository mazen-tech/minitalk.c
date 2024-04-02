/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:28:35 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/29 13:28:40 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*g_str;

void	handler(int signal)
{
	static int	bit;
	static int	e;
	char		*c;

	if (signal == SIGUSR1)
		e |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c = (char *)malloc(sizeof(char) * 2);
		if (!c)
			return ;
		c[0] = (char)e;
		c[1] = '\0';
		g_str = ft_strjoin(g_str, c);
		if (c[0] == '\n')
		{
			ft_putstr_fd(g_str, 1);
			free(g_str);
			g_str = NULL;
		}
		bit = 0;
		e = 0;
		free(c);
	}
}

int	main(void)
{
	fprintf(stdout, "PID [%d]\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

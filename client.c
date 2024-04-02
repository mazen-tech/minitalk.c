/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:37:27 by maabdela          #+#    #+#             */
/*   Updated: 2024/04/01 19:37:29 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	binary_reader(int pid, char target_char)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((target_char & (0x01 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	signal_reciever(int pid, char *str)
{
	while (*str)
	{
		binary_reader(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 3)
	{
		fprintf(stdout, "INVALID NUMBER OF ARGUMENT \n");
		fprintf(stdout, "format: [./clinte <SEVER ID(PID)> <STRING>]");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			fprintf(stdout, "PID invalied \n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	signal_reciever(ft_atoi(argv[1]), argv[2]);
	signal_reciever(ft_atoi(argv[1]), "\n");
	if (argv[1][i] == '\0')
		fprintf(stdout, "MESSAGE SENT SUCCESFULLY \n");
	return (0);
}

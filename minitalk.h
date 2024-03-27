/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:38:33 by maabdela          #+#    #+#             */
/*   Updated: 2023/08/17 19:38:35 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr(unsigned int pid);

int     ft_atoi(const char *str);

#endif

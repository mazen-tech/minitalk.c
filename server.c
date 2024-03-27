/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:38:33 by maabdela          #+#    #+#             */
/*   Updated: 2023/08/17 19:38:35 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

//SIGUSR1 --> Inter-process communication (IPC) for signaling events, synchronization, 
//or custom messaging between user-defined processes in Unix-like systems.

// g_str is used to accumulate characters received from signals over time to form complete string (message)
// bit will keeps track of current bit position
// i will accumelat the bits to form a char
// temp_storage we will use this pointer to a char to temp store a char recieved from a signal

//the number of the (left shifting) will be user to track the bits 
//one we complete 8 bits we now created a one full byte(8 bits)

char    *gen_str;

void    signal_handler(int signal)
{
    static int  bit = 0;
    static int  i = 0;
    char        *temp_storage;

    if (signal == SIGUSR1)
        i =| (0x01 << bit);
    bit++;    
    
    if (bit == 8)
    {
        temp_storage = (char *)malloc(sizeof(char) * 2);
        if (!temp_storage)
            return NULL;

        temp_storage[0] = (char)i;
        temp_storage[1] = '\0';

        gen_str = ft_strjoin(gen_str, temp_storage);

        if(temp_storage[0] == '\n')
        {
            ft_putstr_fd(gen_str,1);
            free(gen_str);
            gen_str = NULL;
        }

        bit = 0;
        i = 0;
        free(temp_storage);
    }
}

int main(void)
{
    printf("PID: [%d]", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1)
        pause();
    
    return (0);
}
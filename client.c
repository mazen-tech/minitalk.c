/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:38:33 by maabdela          #+#    #+#             */
/*   Updated: 2023/08/17 19:38:35 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


//The function signal_reciever sends signals to a process based
//on the binary representation of characters in a given string.

void binary_reader(int pid, char target_char)
{
    int bit = 0;

    while(bit < 8)
    {
        if(target_char && (0x01 << bit) != 0)
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        bit++;
        usleep(100);      
    }
}


void signal_reciever(int pid, char *str)
{
    while (*str)
    {
        binary_reader(pid, *str);
        str++;
    }
    
}


int main(int argc, char **argv)
{
    int i = 0;

    if(argc != 3){
        printf("INVALID NUMBER OF ARGUMENT \n");
        printf("format: [./clinte <SEVER ID(PID)> <STRING>]");
        exit(EXIT_FAILURE);
    }

    while(argv[i][1] != '\0')
    {
       if(argv[1][i] < 0 || srgv[1][i] > 9)
            printf("PID invalied \n");
            exit(EXIT_FAILURE);
    }

    if(argv[1][i] == '\0')
        printf("MESSAGE SENT SUCCESFULLY \n");
    return 0;
}
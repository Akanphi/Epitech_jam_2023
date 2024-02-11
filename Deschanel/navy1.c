/*
** EPITECH PROJECT, 2024
** navy1.c
** File description:
** iueytdsrtfgh
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_putnbr(int nb)
{
    if (nb >= 0 && nb < 10)
        my_putchar(48 + nb);
    else if (nb < 0){
        my_putchar('-');
        my_putnbr(nb * (-1));
    } else {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
}

int all_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 84;
    }
    return 0;
}

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player");
    my_putstr(" pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the");
    my_putstr(" positions of the ships.\n");
}

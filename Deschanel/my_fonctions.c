/*
** EPITECH PROJECT, 2024
** fonctions
** File description:
** fonctions
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

int my_convert(char c)
{
    int y;

    if (c == 'A')
        y = 2;
    if (c == 'B')
        y = 4;
    if (c == 'C')
        y = 6;
    if (c == 'D')
        y = 8;
    if (c == 'E')
        y = 10;
    if (c == 'F')
        y = 12;
    if (c == 'G')
        y = 14;
    if (c == 'H')
        y = 16;
    return y;
}

int my_check(char c1, char c2)
{
    if (c1 == c2)
        return 1;
    else
        return 2;
}

int my_filling2(pos_t *pos, int j, int *rem, char **map)
{
    int b;

    for (b = pos->x[j]; b <= rem[j]; b++) {
        if (map[pos->y[j]][b] == '.')
            map[pos->y[j]][b] = (pos->size[j] + 48);
    }
}

int my_filling1(pos_t *pos, int j, int *rem, char **map)
{
    int k;

    for (k = pos->y[j]; k <= pos->y_fin[j] + 1; k++)
        map[k][pos->x[j]] = (pos->size[j] + 48);
}

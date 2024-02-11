/*
** EPITECH PROJECT, 2024
** my str to word array
** File description:
** my str to word array
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

int my_for1(char **map, int nb_line, int nb_cols)
{
    int k;
    int i = 0;
    int w;

    for (k = 0; k < nb_line; k++) {
        map[k] = malloc(nb_cols * sizeof(char));
    }
    return 0;
}

char **my_str_to_word_array(char *str)
{
    int i;
    int a = 0;
    int k = 0;
    int g = 0;
    char *t = my_read_file(str);
    int nb_line = my_count_char(t, '\n');
    char **map = malloc((nb_line + 1) * sizeof(char *));

    my_for1(map, nb_line, 10);
    for (k = 0; k < nb_line; k++) {
        for (a = 0; t[g] != '\n'; a++) {
            map[k][a] = t[g];
            g++;
        }
        g = g + 1;
        map[k][a] = '\0';
    }
    map[k] = NULL;
    return map;
}

char **my_str_to_word_array2(char *str)
{
    int a = 0;
    int k = 0;
    int g = 0;
    char *t = my_read_file(str);
    int n1 = my_count_char(t, '\n');
    int nb_line = n1 + my_count_char(t, ':');
    char **map = malloc((nb_line + 1) * sizeof(char *));

    my_for1(map, nb_line, 10);
    for (k = 0; k < nb_line; k++) {
        for (a = 0; t[g] != ':' && t[g] != '\n'; a++) {
            map[k][a] = t[g];
            g++;
        }
        g = g + 1;
        map[k][a] = '\0';
    }
    map[k] = NULL;
    return map;
}

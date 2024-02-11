/*
** EPITECH PROJECT, 2024
** parsing1
** File description:
** parsing1
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

int my_filling(pos_t *pos, int x, int *rem, info_t *infos)
{
    int j;

    for (j = 0; j < x; j++) {
        if (infos->check[j] == 1) {
            my_filling1(pos, j, rem, infos->map);
    } else
            my_filling2(pos, j, rem, infos->map);
    }
}

void my_declarations(pos_t *pos, info_t *infos,
    char **av, int nb_line)
{
    infos->check = malloc(nb_line *sizeof(int));
    pos->x = malloc(10 * sizeof(int));
    pos->y = malloc(10 * sizeof(int));
    pos->x_fin = malloc(10 * sizeof(int));
    pos->y_fin = malloc(10 * sizeof(int));
    pos->size = malloc(10 * sizeof(int));
    infos->map = my_str_to_word_array("txt");
    infos->rem = malloc(10 * sizeof(int));
}

int my_update_position(pos_t *pos, info_t *infos, int x, int a)
{
    int y;
    int y1 = case_of_errors1(pos, infos, x, a);
    int y2 = case_of_errors2(pos, infos, x, a);
    int y3;

    if (y1 == 84 || y2 == 84)
        return 84;
    pos->size[x] = my_getnbr(infos->position[a]);
    y = my_convert(infos->position[a + 1][0]);
    infos->rem[x] = my_convert(infos->position[a + 2][0]);
    infos->check[x] = my_check(infos->position[a + 1][0],
        infos->position[a + 2][0]);
    pos->x[x] = y;
    pos->y[x] = (infos->position[a + 1][1] - 48) + 1;
    pos->x_fin[x] = my_convert(infos->position[a + 2][0]);
    pos->y_fin[x] = (infos->position[a + 2][1] - 48);
    y3 = case_of_errors3(pos, infos, x, a);
    if (y3 == 84)
        return 84;
}

char *help_parsing(char *i_pos, info_t *infos, char **av, int ac)
{
    if (ac == 2) {
        infos->position = my_str_to_word_array2(av[1]);
        i_pos = my_read_file(av[1]);
    }
    if (ac == 3) {
        infos->position = my_str_to_word_array2(av[2]);
        i_pos = my_read_file(av[2]);
    }
}

char **parsing(char **av, int ac)
{
    int x = 0;
    int y;
    info_t *infos = malloc(sizeof(info_t));
    char *i_pos;
    pos_t *pos = malloc(sizeof(pos_t));
    int nb_line;
    int n;
    int n1;

    i_pos = help_parsing(i_pos, infos, av, ac);
    n = my_count_char(i_pos, ':');
    n1 = my_count_char(i_pos, '\n');
    if (i_pos == NULL || n != 8 || n1 != 4)
        return NULL;
    nb_line = my_count_char(i_pos, '\n');
    my_declarations(pos, infos, av, nb_line);
    for (int a = 0; infos->position[a] != NULL; a++) {
        if (my_strlen(infos->position[a]) == 1 &&
            my_getnbr(infos->position[a]) >= 2
            && my_getnbr(infos->position[a]) <= 5) {
            y = my_update_position(pos, infos, x, a);
            x++;
        }
        if (y == 84)
            return NULL;
    }
    if (x != 4)
        return NULL;
    if (pos->size[0] != 2 || pos->size[1] != 3 || pos->size[2] != 4
        || pos->size[3] != 5)
        return NULL;
    my_filling(pos, x, infos->rem, infos);
    return infos->map;
}

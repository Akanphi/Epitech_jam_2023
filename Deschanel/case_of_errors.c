/*
** EPITECH PROJECT, 2024
** case of errors
** File description:
** case of errors
*/
#include "my.h"
int case_of_errors1(pos_t *pos, info_t *infos, int x, int a)
{
    int y;

    if (infos->position[a + 1] == NULL || infos->position[a + 2] == NULL)
        return 84;
    if (my_strlen(infos->position[a]) != 1 ||
        my_strlen(infos->position[a + 1]) != 2
        || my_strlen(infos->position[a + 2]) != 2)
        return 84;
    if (infos->position[a][0] >= '2' && infos->position[a][0] <= '8')
        y = 0;
        else
            return 84;
    if (infos->position[a + 1][1] >= '1' && infos->position[a + 1][1] <= '8')
        y = 0;
        else
            return 84;
    if (infos->position[a + 2][1] >= '1' && infos->position[a + 2][1] <= '8')
        y = 0;
        else
            return 84;
}

int case_of_errors2(pos_t *pos, info_t *infos, int x, int a)
{
    int y;

    if (infos->position[a + 2][0] >= 'A' &&
        infos->position[a + 2][0] <= 'H')
        y = 0;
        else
            return 84;
    if (infos->position[a + 1][0] >= 'A' &&
        infos->position[a + 1][0] <= 'H')
        y = 0;
        else
            return 84;
}

int case_of_errors3(pos_t *pos, info_t *infos, int x, int a)
{
    if (pos->x_fin[x] == pos->x[x]) {
        if (pos->y_fin[x] <= (pos->y[x] - 1))
            return 84;
        if ((pos->y_fin[x] - pos->y[x] + 1) != pos->size[x] - 1)
            return 84;
    }
    if (pos->y_fin[x] == (pos->y[x] - 1)) {
        if (pos->x_fin[x] <= (pos->x[x]))
            return 84;
        if (((infos->position[a + 2][0] - infos->position[a + 1][0])) != pos->size[x] - 1)
            return 84;
    }
}

int case_of_errors(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2) {
        int fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return 84;
    }
    if (ac == 3) {
        int fd = open(av[2], O_RDONLY);
        if (fd == -1)
            return 84;
    }
}

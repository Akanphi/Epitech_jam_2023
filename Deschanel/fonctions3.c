/*
** EPITECH PROJECT, 2024
** fonctions3
** File description:
** fonctions3
*/
#include "my.h"
void my_read_attack()
{
    size_t n = 0;
    char *str = NULL;
    ssize_t fd = getline(&str, &n, stdin);
    int sd = open("attack.txt", O_RDWR);

    write(sd, str, 2);
}

char *my_get_line(int fd)
{
    int i = 0;
    char *str = malloc(10 * sizeof(char));

    for (int i = 0; read(fd, &str[i], 1) != 0; i++)
        if (str[i] == '\n')
            break;
    return str;
}

int my_get_attack(char *att, char **map)
{
    int x = my_convert(att[0]);
    int y = att[1] - 48;
    int fd;

    fd = open("atk.txt", O_RDWR);
    if (map[y + 1][x] <= '8' && map[y + 1][x] >= '2') {
        write(fd, "1", 2);
        my_putstr("\nresult: ");
        my_putstr(att);
        my_putstr(":hit\n\n");
    } else {
        write(fd, "2", 2);
        my_putstr("\nresult: ");
        my_putstr(att);
        my_putstr(":missed\n\n");
    }
    return 0;
}

int my_get_player_attack(char *att, char **map)
{
    int x = my_convert(att[0]);
    int y = att[1] - 48;
    int fd;

    fd = open("atk.txt", O_RDWR);
    if (map[y + 1][x] <= '8' && map[y + 1][x] >= '2') {
        write(fd, "0", 2);
        my_putstr("\nresult: ");
        my_putstr(att);
        my_putstr(":hit\n");
    } else {
        write(fd, "2", 2);
        my_putstr("\nresult: ");
        my_putstr(att);
        my_putstr(":missed\n");
    }
    return 0;
}

int my_get_attack2(char *att2, char **map)
{
    char *att = my_read_file("attack.txt");
    int x = my_convert(att[0]);
    int y = att[1] - 48;

    if (att2[0] == '0') {
        my_putstr("\nresult: ");
        my_putstr(att);
        my_putstr(":hit\n");
        map[y + 1][x] = 'x';
    } else {
        my_putstr("\nresult : ");
        my_putstr(att);
        my_putstr(":missed\n");
        map[y + 1][x] = 'o';
    }
    return 0;
}

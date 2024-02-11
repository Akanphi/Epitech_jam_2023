/*
** EPITECH PROJECT, 2024
** getline
** File description:
** getline
*/
#include <stdio.h>
#include "my.h"
#include <string.h>
int my_display2(void)
{
    my_putstr("my_pid: ");
    my_putnbr(getpid());
    my_putstr("\n");
    my_putstr("\n");
    my_putstr("waiting for enemy ...\n");
}

void sig_declarations(my_sigaction_t *my_sigactions)
{
    my_sigactions->sig.sa_sigaction = &my_sig;
    my_sigactions->sig.sa_flags = SA_SIGINFO;
    my_sigactions->sig2.sa_sigaction = &my_sig2;
    my_sigactions->sig2.sa_flags = SA_SIGINFO;
    my_sigactions->sig3.sa_sigaction = &my_player_atk;
    my_sigactions->sig3.sa_flags = SA_SIGINFO;
    my_sigactions->sig4.sa_sigaction = &my_ennemi_atk;
    my_sigactions->sig4.sa_flags = SA_SIGINFO;
    my_sigactions->sig5.sa_sigaction = &my_remplace_att;
    my_sigactions->sig5.sa_flags = SA_SIGINFO;
    my_sigactions->sig6.sa_sigaction = &my_remplace_att2;
    my_sigactions->sig6.sa_flags = SA_SIGINFO;
    my_sigactions->attaqq.sa_sigaction = &my_attaq;
    my_sigactions->attaqq.sa_flags = SA_SIGINFO;
    my_sigactions->atk_ennemy.sa_sigaction = &atk_ennemy;
    my_sigactions->atk_ennemy.sa_flags = SA_SIGINFO;
    my_sigactions->ennemy.sa_sigaction = &ennemy;
    my_sigactions->ennemy.sa_flags = SA_SIGINFO;
    my_sigactions->sig8.sa_sigaction = &player_win;
    my_sigactions->sig8.sa_flags = SA_SIGINFO;
}

int my_get_player_attack2(char *att2, char **map, char **map_player1, char **map_ennemi2)
{
    char *att = my_read_file("attack.txt");
    int x = my_convert(att[0]);
    int y = att[1] - 48;
    char *boat = my_read_file("boat2.txt");
    int b = my_getnbr(boat);
    int x2;
    int fd;

    if (att2[0] == '1') {
        my_putstr("result: ");
        my_putstr(att);
        my_putstr(":hit\n");
        map[y + 1][x] = 'x';
    } else {
        my_putstr("result: ");
        my_putstr(att);
        my_putstr(":missed\n");
        map[y + 1][x] = 'o';
    }
    fd = open("attack.txt", O_RDWR);
    x2 = my_count_x(map);
    /*if (x2 == 14) {
        write(fd, "OK", 2);
        my_display3(map_player1, map_ennemi2);
        my_putstr("I won\n");
        return 1;
    }*/
    return 0;
}


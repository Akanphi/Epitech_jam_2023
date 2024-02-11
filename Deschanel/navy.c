/*
** EPITECH PROJECT, 2024
** navy.c
** File description:
** yesdt
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

int main2(int ac, char **av, my_sigaction_t *my_sigactions)
{
    char *cond;
    if (ac == 3){
    usr1 = my_getnbr(av[1]);
    map_ennemi1 = parsing(av, 3);
    int y = kill(usr1, SIGUSR1);
    if (map_ennemi1 == NULL || y == -1)
        return 84;
    sigaction(SIGUSR1, &my_sigactions->sig2, NULL);
    pause();
    while (1) {
        sigaction(SIGUSR2, &my_sigactions->sig6, NULL);
        pause();
        sigaction(SIGUSR2, &my_sigactions->sig4, NULL);
        pause();
        sigaction(SIGUSR1, &my_sigactions->ennemy, NULL);
        pause();
    }
    }
}

void my_player_atk(int a, siginfo_t *b, void *c)
{
    kill(b->si_pid, SIGUSR1);
    my_display3(map_player1, map_ennemi2);
    attack(b);
}

void my_sig(int a, siginfo_t *b, void *c)
{
    kill(b->si_pid, SIGUSR1);
    my_putstr("\nenemy connected\n");
    my_display3(map_player1, map_ennemi2);
}

void my_sig2(int a, siginfo_t *b, void *c)
{
    my_putstr("\n\nsuccessfully connected\n");
    my_display1(map_ennemi1, map_player2);
    kill(usr1, SIGUSR2);
}

void atk_ennemy(int a, siginfo_t *b, void *c)
{
    char *att = my_read_file("attack.txt");

    my_get_player_attack(att, map_player1);
    my_display3(map_player1, map_ennemi2);
    kill(b->si_pid, SIGUSR1);
}

void player_win(int a, siginfo_t *b, void *c)
{
    my_display1(map_ennemi1, map_player2);
    my_putstr("Ennemy won\n");
}

void my_remplace_att(int a, siginfo_t *b, void *c)
{
    char *att2 = my_read_file("atk.txt");
    char *att = my_read_file("attack.txt");
    int y = my_get_player_attack2(att2, map_ennemi2, map_player1, map_ennemi2);

        my_putstr("\nwaiting for enemy's  attack...\n");
        kill(b->si_pid, SIGUSR2);
}

void my_remplace_att2(int a, siginfo_t *b, void *c)
{
    char *att = my_read_file("attack.txt");

    my_get_attack(att, map_ennemi1);
    kill(usr1, SIGUSR1);
}

void ennemy(int a, siginfo_t *b, void *c)
{
    char *att2 = my_read_file("atk.txt");

    my_get_attack2(att2, map_player2);
    my_display1(map_ennemi1, map_player2);
    kill(usr1, SIGUSR2);
}

void my_ennemi_atk(int a, siginfo_t *b, void *c)
{
    int x = 0;
    char *att;

    my_putstr("attack: ");
    my_read_attack();
    att = my_read_file("attack.txt");
    while (x == 0) {
    if (att[0] >= 'A' && att[0] <= 'H' && att[1] >= '1'
        && att[1] <= '8' && my_strlen(att) == 2) {
        x = 1;
    } else {
        my_putstr("\nWrong position\n");
        my_putstr("\nattack: ");
        my_read_attack();
        att = my_read_file("attack.txt");
    }
    }
    kill(usr1, SIGUSR2);
}

int main1(int ac, char **av, my_sigaction_t *my_sigactions)
{
    int x2;
    
    if (ac == 2) {
        map_player1 = parsing(av, 2);
        if (map_player1 == NULL)
            return 84;
        my_display2();
        sigaction(SIGUSR1, &my_sigactions->sig, NULL);
        pause();
        while (1){
        sigaction(SIGUSR2, &my_sigactions->attaqq, NULL);
        pause();
        sigaction(SIGUSR1, &my_sigactions->sig5, NULL);
        pause();
        x2 = my_count_x(map_ennemi2);
        sigaction(SIGUSR2, &my_sigactions->atk_ennemy, NULL);
        pause();
        }
    }
}

int attack(siginfo_t *b)
{
    int x = 0;
    char *att;

    my_putstr("\nattack: ");
    my_read_attack();
    att = my_read_file("attack.txt");
    while (x == 0) {
    if (att[0] >= 'A' && att[0] <= 'H' && att[1] >= '1'
        && att[1] <= '8' && my_strlen(att) == 2) {
        return 0;
    } else {
        my_putstr("\nWrong position\n");
        my_putstr("\nattack: ");
        my_read_attack();
        att = my_read_file("attack.txt");
    }
    }
    kill(b->si_pid, SIGUSR1);
    my_putstr("\n");
}

void my_attaq(int a, siginfo_t *b, void *c)
{
    int x = 0;
    char *att;

    my_putstr("attack: ");
    my_read_attack();
    att = my_read_file("attack.txt");
    while (x == 0) {
    if (att[0] >= 'A' && att[0] <= 'H' && att[1] >= '1'
        && att[1] <= '8' && my_strlen(att) == 2) {
        x = 1;
    } else {
        my_putstr("\nWrong position\n");
        x = 0;
        my_putstr("\nattack: ");
        my_read_attack();
        att = my_read_file("attack.txt");
    }
    }
    kill(b->si_pid, SIGUSR2);
    my_putstr("\n");
}

int main(int ac, char **av)
{
    my_sigaction_t *my_sigactions = malloc(sizeof(my_sigaction_t));
    int y1;
    int y2;

    y1 = case_of_errors(ac, av);
    if (y1 == 84)
        return 84;
    map_player2 = my_str_to_word_array("txt");
    map_ennemi2 = my_str_to_word_array("txt");
    sig_declarations(my_sigactions);
    y1 = main1(ac, av, my_sigactions);
    if (y1 == 84)
        return 84;
    y2 = main2(ac, av, my_sigactions);
    if (y2 == 84)
        return 84;
}

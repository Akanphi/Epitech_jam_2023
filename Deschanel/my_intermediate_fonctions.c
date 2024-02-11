/*
** EPITECH PROJECT, 2024
** fonctions
** File description:
** fonctions
*/
#include "my.h"
void my_display3(char **map_player1, char **map_ennemi2)
{
    my_putstr("\nmy navy:\n");
    for (int i = 0; map_player1[i] != NULL; i++) {
        my_putstr(map_player1[i]);
        my_putstr("\n");
    }
    my_putstr("\n");
    my_putstr("\nennemy navy:\n");
    for (int i = 0; map_ennemi2[i] != NULL; i++) {
        my_putstr(map_ennemi2[i]);
        my_putstr("\n");
    }
    my_putstr("\n");
}

int my_display1(char **map_ennemi1, char **map_player2)
{
    my_putstr("\nmy navy:\n");
    for (int i = 0; map_ennemi1[i] != NULL; i++) {
    my_putstr(map_ennemi1[i]);
    my_putstr("\n");
    }
    my_putstr("\n");
    my_putstr("\nennemy navy:\n");
    for (int i = 0; map_player2[i] != NULL; i++) {
    my_putstr(map_player2[i]);
    my_putstr("\n");
    }
    my_putstr("\nwaiting for enemy's  attack...\n");
}

int my_count_boat(char **map)
{
    int n = 0;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] >= '2' && map[i][j] <= '5')
                n++;
        }
    }
    return (n - 4);
}

int my_count_x(char **map)
{
    int n = 0;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'x')
                n++;
        }
    }
    return n;
}
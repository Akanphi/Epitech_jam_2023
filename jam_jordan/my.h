/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** epi_jam
*/
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef MY_H
    #define MY_H
typedef struct meteor
{
    sfRenderWindow *window;
    sfText *score;
    sfFont *record;
    sfText *scores;
    sfFont *records;
    char *str;
    sfVideoMode video_mode;
    sfEvent event;
    sfTexture *txt_fire;
    sfTexture *txt_fire1;
    sfTexture *txt_fire2;
    sfSprite *spt_fire;
    sfSprite *spt_fire1;
    sfSprite *spt_fire2;
    sfVector2f pos_fire;
    sfClock *clock;
    sfTime times;
    float seconds;
    sfVector2f pos_fire1;
    sfVector2f pos_fire2;
    sfVector2f pos_scr;
    sfVector2f size;
    sfIntRect rect;
    sfIntRect rect1;
    sfIntRect rect2;
    int goal;
    double a;
    double b;
    double c;
    double nbr;
} meteor_t;
void speed(meteor_t *win);
void even(meteor_t *evt);
void destroy(meteor_t *win);
void display(meteor_t *win);
void call( meteor_t *win);
int méteor(int argc, char **argv);
void mv_fire1(meteor_t *win);
void mv_fire(meteor_t *win);
int clock1(meteor_t *win);
char *main1(int nb);
#endif

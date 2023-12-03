/*
** EPITECH PROJECT, 2023
** epi_jam
** File description:
** fire
*/
#include "my.h"

char *main1(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 10000000);
    char *src = malloc(sizeof(char) * 10000000);
    int a;
    int j = 0;

    for (a = 0; nb != 0; a++) {
        i = nb % 10;
        nb = nb / 10;
        str[a] = '0' + i;
    }
    for (a -= 1; a >= 0; a--) {
        src[j] = str[a];
        j++;
    }
    return src;
    free(str);
    free(src);
}

void mv_fire1(meteor_t *win)
{
    if (win->pos_fire1.y < 600)
        win->pos_fire1.y += 20;
    else {
        win->goal++;
        win->pos_fire1.y = -78;
        win->pos_fire1.x = (rand() % (800 - 5 + 1)) + 5;
    }
    sfSprite_setPosition(win->spt_fire1, win->pos_fire1);
}

void mv_fire(meteor_t *win)
{
    if (win->pos_fire.y < 600)
        win->pos_fire.y += 20;
    else {
        win->goal++;
        win->pos_fire.y = -78;
        win->pos_fire.x = (rand() % (800 - 5 + 1)) + 5;
    }
    sfSprite_setPosition(win->spt_fire, win->pos_fire);
    if (win->pos_fire2.y < 600)
        win->pos_fire2.y += 20;
    else {
        win->goal++;
        win->pos_fire2.y = -78;
        win->pos_fire2.x = (rand() % (800 - 5 + 1)) + 5;
    }
    sfSprite_setPosition(win->spt_fire2, win->pos_fire2);
}

int clock1(meteor_t *win)
{
    win->times = sfClock_getElapsedTime(win->clock);
    win->seconds = win->times.microseconds / 100000.0;
    if (win->goal == 9)
        win->nbr = win->nbr / 2;
    else {
        if (win->seconds > win->nbr) {
            mv_fire(win);
            mv_fire1(win);
            sfClock_restart(win->clock);
        }
    }
}

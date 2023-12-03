/*
** EPITECH PROJECT, 2023
** menu.c
** File description:
** udesyud
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
void declare(game_t *play)
{
    play->window;
    play->mode.width = 800;
    play->mode.height = 600;
    play->mode.bitsPerPixel = 32;
    play->event;
    play->texture = sfTexture_createFromFile("./espace.jpg", NULL);
    play->texte = sfTexture_createFromFile("./quit.jpg", NULL);
    play->text = sfTexture_createFromFile("./quit.jpg", NULL);
    play->sprite = sfSprite_create();
    play->sprit = sfSprite_create();
    play->spri = sfSprite_create();
    play->scale.x = 2;
    play->scale.y = 2;
    play->carre.left = 0;
    play->carre.top = 0;
    play->carre.width = 159;
    play->carre.height = 40;
    play->care.left = 159;
    play->care.top = 120;
    play->care.width = 159;
    play->care.height = 40;
    play->pos.x = 321;
    play->pos.y = 280;
    play->posi.x = 321;
    play->posi.y = 220;
    play->posa = sfSprite_getPosition(play->spri);
    play->pose;
}
int main()
{
    game_t *play = malloc(sizeof(game_t));

    declare(play);
    sfSprite_setScale(play->sprite, play->scale);
    sfSprite_setTexture(play->sprite, play->texture, sfTrue);
    sfSprite_setTexture(play->sprit, play->texte, sfTrue);
    sfSprite_setTexture(play->spri, play->text, sfTrue);
    play->window = sfRenderWindow_create(play->mode, "rakib window", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(play->window)){
        while (sfRenderWindow_pollEvent(play->window, &play->event)){
            if (play->event.type == sfEvtClosed){
                sfRenderWindow_close(play->window);
            }
            play->pose = sfMouse_getPositionRenderWindow(play->window);
            if ((play->pose.x >= 323 && play->pose.x <= 480) && (play->pose.y >= 282 && play->pose.y <= 318)){
                if (sfMouse_isButtonPressed(sfMouseLeft))
                    sfRenderWindow_close(play->window);
            }
        }
        sfSprite_setTextureRect(play->sprit, play->carre);
        sfSprite_setTextureRect(play->spri, play->care);
        sfSprite_setPosition(play->sprit, play->pos);
        sfSprite_setPosition(play->spri, play->posi);
        sfRenderWindow_clear(play->window, sfWhite);
        sfRenderWindow_drawSprite(play->window, play->sprite, NULL);
        sfRenderWindow_drawSprite(play->window, play->sprit, NULL);
        sfRenderWindow_drawSprite(play->window, play->spri, NULL);
        sfRenderWindow_display(play->window);
    }
    sfSprite_destroy(play->sprite);
    sfTexture_destroy(play->texture);
    sfSprite_destroy(play->sprit);
    sfTexture_destroy(play->texte);
    sfSprite_destroy(play->spri);
    sfTexture_destroy(play->text);
    sfRenderWindow_destroy(play->window);
}

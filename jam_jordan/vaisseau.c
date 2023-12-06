/*
** EPITECH PROJECT, 2023
** vaisseau.c
** File description:
** function for vaisseau
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <stdio.h>
#include <SFML/System/Clock.h>
#include <time.h>
#include <stdbool.h>
#include <SFML/Audio.h>
#include "my.h"

int main(int argc, char **argv)
{
    meteor_t *win = malloc(sizeof(meteor_t));
    sfVector2f scale = {1.3, 1.3};
    sfVector2f scale1 = {2, 2};
    sfVector2f scale24 = {3, 3};
    sfVector2f scale23 = {3, 2};
    sfEvent event;
    sfVector2f mouse1;
    sfVector2f pos_g = {540, 200};
    sfTime time;
    float seconds;
    sfClock *clock;
    sfMusic *mario = sfMusic_createFromFile("son.ogg");
    sfMusic_play(mario);
    sfVector2f ground = {800, 730};
    sfTexture *vaisseau = sfTexture_createFromFile("img/vaisseau1.png", NULL);
    sfTexture *text_over = sfTexture_createFromFile("game_over.png", NULL);
    sfTexture *text_boom = sfTexture_createFromFile("boom.png", NULL);
    sfTexture *text_over1 = sfTexture_createFromFile("game_over_back.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite *spt_over = sfSprite_create();
    sfSprite *spt_over1 = sfSprite_create();
    sfSprite *spt_boom = sfSprite_create();
    sfSprite_setTexture(sprite, vaisseau, sfTrue);
    sfSprite_setTexture(spt_boom, text_boom, sfTrue);
    sfSprite_setTexture(spt_over, text_over, sfTrue);
    sfSprite_setTexture(spt_over1, text_over1, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfFont *font = sfFont_createFromFile("COMICATE.TTF");
    sfFont *font1 = sfFont_createFromFile("COMICATE.TTF");
    sfText *texte = sfText_create();
    sfText *texte1 = sfText_create();
    sfText_setFont(texte, font);
    sfText_setFont(texte1, font1);
    sfText_setCharacterSize(texte, 120);
    sfText_setCharacterSize(texte1, 120);
    sfText_setColor(texte, sfWhite);
    sfText_setColor(texte1, sfWhite);
    sfText_setPosition(texte1, pos_g);
    sfTexture *fond = sfTexture_createFromFile("img/fond.jpg", NULL);
    sfIntRect rect_fus = {0, 0, 225, 225};
    sfSprite_setTextureRect(sprite, rect_fus);
    sfSprite *f_sprite = sfSprite_create();
    sfSprite_setTexture(f_sprite, fond, sfTrue);
    sfSprite_setScale(f_sprite, scale1);
    sfSprite_setScale(spt_over1, scale23);
    sfSprite_setScale(spt_over, scale24);
    sfSprite_setPosition(spt_over, pos_g);
    // sfIntRect rect_over = {0, 0, 1080, 1920};
    // sfSprite_setTextureRect(spt_over1, rect_over);
    /* win->rect->left = 0; */
    /* win->rect->top = 0; */
    /* win->rect->width = 70; */
    /* win->rect->height = 118; */
    /* win->rect1->left = 0; */
    /* win->rect1->top = 0; */
    /* win->rect1->width = 70; */
    /* win->rect1->height = 118; */
    /* win->rect2->left = 0; */
    /* win->rect2->top = 0; */
    /* win->rect2->width = 70; */
    /* win->rect2->height = 118; */
    /* sfSprite_setTextureRect(win->spt_fire, *win->rect); */
    /* sfSprite_setTextureRect(win->spt_fire1, *win->rect1); */
    /* sfSprite_setTextureRect(win->spt_fire2, *win->rect2); */

    win->window = sfRenderWindow_create(win->video_mode, "Spatial", sfResize | sfClose, NULL);
    sfSprite_setPosition(sprite, ground);
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
    sfRenderWindow_display(win->window);
    sfSleep(sfSeconds(1.0f));
    sfRenderWindow_clear(win->window, sfBlack);
    for (int i = 3; i > 0; i--) {
        char nombres[3];
        sprintf(nombres, "%d", i);
        sfText_setString(texte, nombres);
        sfVector2f text_position = {870, 750};
        sfText_setPosition(texte, text_position);
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawText(win->window, texte, NULL);
        sfRenderWindow_display(win->window);
        sfSleep(sfSeconds(1.0f));
    }
    sfText_setString(texte, "Go!");
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawText(win->window, texte, NULL);
    sfRenderWindow_display(win->window);
    sfSleep(sfSeconds(0.5f));
    call(win);
    // sfSprite_getGlobalBounds(win->spt_fire);
    // sfSprite_getGlobalBounds(sprite);
    win->rect.left = 0;
    win->rect.top = 0;
    win->rect.width = 70;
    win->rect.height = 118;
    win->rect1.left = 0;
    win->rect1.top = 0;
    win->rect1.width = 70;
    win->rect1.height = 118;
    win->rect2.left = 0;
    win->rect2.top = 0;
    win->rect2.width = 70;
    win->rect2.height = 118;
    sfSprite_setTextureRect(win->spt_fire, win->rect);
    sfSprite_setTextureRect(win->spt_fire1, win->rect1);
    sfSprite_setTextureRect(win->spt_fire2, win->rect2);
    // if (sfIntRect_intersects(&win->rect, &rect_fus, NULL) != sfFalse) {
    //     return 0;
    // }

    while (sfRenderWindow_isOpen(win->window)) {
        while (sfRenderWindow_pollEvent(win->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(win->window);
            }
            if (sfMouse_isButtonPressed(sfMouseRight)) {
                sfSleep(sfSeconds(1.0f));
                sfRenderWindow_close(win->window);
            }
        }
        sfMusic_setLoop(mario, sfTrue);
        sfRenderWindow_drawSprite(win->window, f_sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
        sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
        mouse1.x = (int)(mouse).x - (300 / 2);
        mouse1.y = (int)(mouse).y - (300 / 2);
        sfVector2f position = {mouse1.x, mouse1.y};
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(win->window, sprite, NULL);
        display(win);
        if (mouse.x >= win->pos_fire.x && mouse.x <= win->pos_fire.x + 118 && mouse.y - 60 >= win->pos_fire.y && mouse.y - 60 <= win->pos_fire.y + 70) {
            sfSprite_setPosition(spt_boom, position);
            sfRenderWindow_drawSprite(win->window, spt_boom, NULL);
            sfRenderWindow_display(win->window);
            sfSleep(sfSeconds(1.0f));
            while (sfRenderWindow_isOpen(win->window)) {
                while (sfRenderWindow_pollEvent(win->window, &event)) {
                    if (event.type == sfEvtClosed) {
                        sfRenderWindow_close(win->window);
                    }
                    if (sfMouse_isButtonPressed(sfMouseRight)) {
                        sfSleep(sfSeconds(1.0f));
                        sfRenderWindow_close(win->window);
                    }
                }
                sfRenderWindow_clear(win->window, sfBlack);
                sfRenderWindow_drawSprite(win->window, spt_over1, NULL);
                sfRenderWindow_drawSprite(win->window, spt_over, NULL);
                sfRenderWindow_display(win->window);
            }
            sfRenderWindow_close(win->window);
        }
        if (mouse.x >= win->pos_fire1.x && mouse.x <= win->pos_fire1.x + 118 && mouse.y - 60 >= win->pos_fire1.y && mouse.y - 60 <= win->pos_fire1.y + 70) {
            sfSprite_setPosition(spt_boom, position);
            sfRenderWindow_drawSprite(win->window, spt_boom, NULL);
            sfRenderWindow_display(win->window);
            sfSleep(sfSeconds(1.0f));
            while (sfRenderWindow_isOpen(win->window)) {
                while (sfRenderWindow_pollEvent(win->window, &event)) {
                    if (event.type == sfEvtClosed) {
                        sfRenderWindow_close(win->window);
                    }
                    if (sfMouse_isButtonPressed(sfMouseRight)) {
                        sfSleep(sfSeconds(1.0f));
                        sfRenderWindow_close(win->window);
                    }
                }
                sfRenderWindow_clear(win->window, sfBlack);
                sfRenderWindow_drawSprite(win->window, spt_over1, NULL);
                sfRenderWindow_drawSprite(win->window, spt_over, NULL);
                sfRenderWindow_display(win->window);
            }
            sfRenderWindow_close(win->window);
        }
        if (mouse.x >= win->pos_fire2.x && mouse.x <= win->pos_fire2.x + 118 && mouse.y - 60 >= win->pos_fire2.y && mouse.y - 60 <= win->pos_fire2.y + 70) {
            sfSprite_setPosition(spt_boom, position);
            sfRenderWindow_drawSprite(win->window, spt_boom, NULL);
            sfRenderWindow_display(win->window);
            sfSleep(sfSeconds(1.0f));
            while (sfRenderWindow_isOpen(win->window)) {
                while (sfRenderWindow_pollEvent(win->window, &event)) {
                    if (event.type == sfEvtClosed) {
                        sfRenderWindow_close(win->window);
                    }
                    if (sfMouse_isButtonPressed(sfMouseRight)) {
                        sfSleep(sfSeconds(1.0f));
                        sfRenderWindow_close(win->window);
                    }
                }
                sfRenderWindow_clear(win->window, sfBlack);
                sfRenderWindow_drawSprite(win->window, spt_over1, NULL);
                sfRenderWindow_drawSprite(win->window, spt_over, NULL);
                sfRenderWindow_display(win->window);
            }
            sfRenderWindow_close(win->window);
        }
        sfRenderWindow_display(win->window);
    }
    destroy(win);
    sfFont_destroy(font);
    sfText_destroy(texte);
    sfTexture_destroy(vaisseau);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(win->window);
}

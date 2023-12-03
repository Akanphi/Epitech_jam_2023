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

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfVector2f scale = {1.3, 1.3};
    sfVector2f scale1 = {2, 2};
    sfEvent event;
    sfVector2f mouse1;
    sfTime time;
    float seconds;
    sfClock *clock;
    sfVector2f ground = {800, 730};
    sfTexture *vaisseau = sfTexture_createFromFile("img/vaisseau1.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, vaisseau, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfFont *font = sfFont_createFromFile("COMICATE.TTF");
    sfText *texte = sfText_create();
    sfText_setFont(texte, font);
    sfText_setCharacterSize(texte, 120);
    sfText_setColor(texte, sfWhite);
    sfTexture *fond = sfTexture_createFromFile("img/fond.jpg", NULL);
    sfSprite *f_sprite = sfSprite_create();
    sfSprite_setTexture(f_sprite, fond, sfTrue);
    sfSprite_setScale(f_sprite, scale1);

    window = sfRenderWindow_create(mode, "Spatial", sfResize | sfClose, NULL);
    sfSprite_setPosition(sprite, ground);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    sfSleep(sfSeconds(1.0f));
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 3; i > 0; i--) {
        char nombres[3];
        sprintf(nombres, "%d", i);
        sfText_setString(texte, nombres);
        sfVector2f text_position = {870, 750};
        sfText_setPosition(texte, text_position);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, texte, NULL);
        sfRenderWindow_display(window);
        sfSleep(sfSeconds(1.0f));
    }
    sfText_setString(texte, "Go!");
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, texte, NULL);
    sfRenderWindow_display(window);
    sfSleep(sfSeconds(0.5f));

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_drawSprite(window, f_sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        mouse1.x = (int)(mouse).x - (300 / 2);
        mouse1.y = (int)(mouse).y - (300 / 2);
        sfVector2f position = {mouse1.x, mouse1.y};
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfFont_destroy(font);
    sfText_destroy(texte);
    sfTexture_destroy(vaisseau);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
}

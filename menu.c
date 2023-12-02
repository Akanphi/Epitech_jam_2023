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
int main()
{
    sfRenderWindow* window;
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("./espace.jpg", NULL);
    sfTexture *texte = sfTexture_createFromFile("./quit.jpg", NULL);
    sfTexture *text = sfTexture_createFromFile("./quit.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite *sprit = sfSprite_create();
    sfSprite *spri = sfSprite_create();
    sfVector2f scale = {2, 2};
    sfIntRect carre = {0, 0, 159, 40};
    sfIntRect care = {159, 120, 159, 40};
    sfVector2f pos = {321, 280};
    sfVector2f posi = {321, 220};
    sfVector2f posa = sfSprite_getPosition(spri);
    sfVector2i pose;

    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprit, texte, sfTrue);
    sfSprite_setTexture(spri, text, sfTrue);
    window = sfRenderWindow_create(mode, "rakib window", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
            pose = sfMouse_getPositionRenderWindow(window);
            //printf("xs = %f, ys = %f\n", posa.x, posa.y);
            //printf("xm = %d, ym = %d\n", pose.x, pose.y);
            if ((pose.x >= 323 && pose.x <= 480) && (pose.y >= 282 && pose.y <= 318)){
                if (sfMouse_isButtonPressed(sfMouseLeft))
                    sfRenderWindow_close(window);
            }
        }
        sfSprite_setTextureRect(sprit, carre);
        sfSprite_setTextureRect(spri, care);
        sfSprite_setPosition(sprit, pos);
        sfSprite_setPosition(spri, posi);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprit, NULL);
        sfRenderWindow_drawSprite(window, spri, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprit);
    sfTexture_destroy(texte);
    sfSprite_destroy(spri);
    sfTexture_destroy(text);
    sfRenderWindow_destroy(window);
}

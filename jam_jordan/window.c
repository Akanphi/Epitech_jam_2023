/*
** EPITECH PROJECT, 2023
** my_window
** File description:
** météore
*/
#include "my.h"

void even(meteor_t *evt)
{
    while (sfRenderWindow_pollEvent(evt->window, &(evt->event))) {
        if (evt->event.type == sfEvtClosed) {
            sfRenderWindow_close(evt->window);
        }
    }
}

void destroy(meteor_t *win)
{
    sfRenderWindow_destroy(win->window);
    // sfSprite_destroy(win->spt_bird1);
    // sfMusic_destroy(win->mario);
    // sfSound_destroy(win->jump);
    // sfSoundBuffer_destroy(win->jomp);
    sfTexture_destroy(win->txt_fire);
    sfTexture_destroy(win->txt_fire1);
    sfTexture_destroy(win->txt_fire2);
    // sfTexture_destroy(win->txt_cursor);
    // sfTexture_destroy(win->txt_kill);
    // sfTexture_destroy(win->txt_start);
    sfSprite_destroy(win->spt_fire);
    sfSprite_destroy(win->spt_fire1);
    sfSprite_destroy(win->spt_fire2);
    sfText_destroy(win->score);
    sfFont_destroy(win->record);
    sfText_destroy(win->scores);
    sfFont_destroy(win->records);
    // sfSprite_destroy(win->spt_kill);
    sfClock_destroy(win->clock);
}

void display(meteor_t *win)
{
    // sfText_setFont(win->score, win->record);
    // win->str = main1(win->goal);
    // sfText_setString(win->score, win->str);
    // sfMusic_setLoop(win->mario, sfTrue);
    // sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    // win->pos_mouse = sfMouse_getPositionRenderWindow(win->window);
    // win->pos_cursor.x = win->pos_mouse.x;
    // win->pos_cursor.y = win->pos_mouse.y;
    // sfSprite_setPosition(win->spt_cursor, win->pos_cursor);
    sfText_setFont(win->score, win->record);
    sfText_setFont(win->scores, win->records);
    win->str = main1(win->goal);
    sfText_setString(win->score, win->str);
    sfText_setString(win->scores, "scs:");
    sfText_setPosition(win->score, win->pos_scr);
    clock1(win);
    sfRenderWindow_clear(win->window, sfBlue);
    sfRenderWindow_drawSprite(win->window, win->spt_fire, NULL);
    sfRenderWindow_drawSprite(win->window, win->spt_fire1, NULL);
    sfRenderWindow_drawSprite(win->window, win->spt_fire2, NULL);
    sfRenderWindow_drawText(win->window, win->score, NULL);
    sfRenderWindow_drawText(win->window, win->scores, NULL);
    // sfRenderWindow_drawSprite(win->window, win->spt_bird1, NULL);
    // sfRenderWindow_drawSprite(win->window, win->spt_kill, NULL);
    // sfRenderWindow_drawText(win->window, win->score, NULL);
    sfRenderWindow_display(win->window);
}

void call( meteor_t *win)
{
    //call2(win);
    win->pos_scr.x = 80;
    win->pos_scr.y = 0;
    win->nbr = 1.0;
    win->clock = sfClock_create();
    win->spt_fire = sfSprite_create();
    win->spt_fire1 = sfSprite_create();
    win->spt_fire2 = sfSprite_create();
    win->goal = 0;
    win->str = malloc(1000 * sizeof(char));
    win->score = sfText_create();
    win->scores = sfText_create();
    win->record = sfFont_createFromFile("font.TTF");
    win->records = sfFont_createFromFile("font.TTF");
    win->txt_fire = sfTexture_createFromFile("météo.png", NULL);
    win->txt_fire1 = sfTexture_createFromFile("météo1.png", NULL);
    win->txt_fire2 = sfTexture_createFromFile("météo2.png", NULL);
    sfSprite_setTexture(win->spt_fire, win->txt_fire, sfTrue);
    sfSprite_setTexture(win->spt_fire1, win->txt_fire1, sfTrue);
    sfSprite_setTexture(win->spt_fire2, win->txt_fire2, sfTrue);
    // sfSprite_setTextureRect(win->spt_ground, win->rect_grd);
    // sfSprite_setTextureRect(win->spt_bird, win->rect_bird);
    // sfSprite_setTextureRect(win->spt_bird1, win->rect_bird1);
    win->pos_fire.x = 110;
    win->pos_fire.y = 0;
    sfSprite_setPosition(win->spt_fire, win->pos_fire);
    win->pos_fire1.x = 350;
    win->pos_fire1.y = 0;
    sfSprite_setPosition(win->spt_fire1, win->pos_fire1);
    win->pos_fire2.x = 500;
    win->pos_fire2.y = 0;
    sfSprite_setPosition(win->spt_fire2, win->pos_fire2);
    win->video_mode.width = 800;
    win->video_mode.height = 600;
    win->video_mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->video_mode, "Window",
    sfClose | sfResize, NULL);
}

int méteor(int argc, char **argv)
{
     meteor_t *win = malloc(sizeof( meteor_t));

    call(win);
    while (sfRenderWindow_isOpen(win->window)) {
        even(win);
        display(win);
    }
    destroy(win);
}
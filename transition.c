/*
** EPITECH PROJECT, 2024
** transition
** File description:
** handle the battle transition
*/

#include "include/include.h"

void transition2(global_t *gl)
{
    sfVector2f size1 = sfRectangleShape_getPosition(gl->combat->trans[0]);
    sfVector2f size2 = sfRectangleShape_getPosition(gl->combat->trans[1]);

    gl->combat->clock = sfClock_create();
    while (size1.x < 2000) {
        gl->combat->time = sfClock_getElapsedTime(gl->combat->clock);
        sfRenderWindow_clear(gl->window, sfWhite);
        if (gl->combat->time.microseconds >= 100) {
            size1.x += 100;
            size2.x -= 100;
            sfClock_restart(gl->combat->clock);
            sfRectangleShape_setPosition(gl->combat->trans[0], size1);
            sfRectangleShape_setPosition(gl->combat->trans[1], size2);
        }
        for (int i = 0; gl->combat->trans[i]; i++)
            sfRenderWindow_drawRectangleShape(gl->window,
                gl->combat->trans[i], NULL);
        sfRenderWindow_display(gl->window);
    }
    sfClock_destroy(gl->combat->clock);
}

void transition(global_t *gl)
{
    sfVector2f size1 = sfRectangleShape_getSize(gl->combat->trans[0]);
    sfVector2f size2 = sfRectangleShape_getSize(gl->combat->trans[1]);

    gl->combat->clock = sfClock_create();
    while (size1.x < 4000) {
        gl->combat->time = sfClock_getElapsedTime(gl->combat->clock);
        sfRenderWindow_clear(gl->window, sfWhite);
        if (gl->combat->time.microseconds >= 100) {
            size1.x += 100;
            size2.x -= 100;
            sfClock_restart(gl->combat->clock);
            sfRectangleShape_setSize(gl->combat->trans[0], size1);
            sfRectangleShape_setSize(gl->combat->trans[1], size2);
        }
        for (int i = 0; gl->combat->trans[i]; i++)
            sfRenderWindow_drawRectangleShape(gl->window,
                gl->combat->trans[i], NULL);
        sfRenderWindow_display(gl->window);
    }
    sfClock_destroy(gl->combat->clock);
}

/*
** EPITECH PROJECT, 2024
** key
** File description:
** bind
*/

#include "../include/include.h"

void bind_confirm(global_t *global)
{
    sfEvent event;
    int finish = 0;
    int key_in_use = 0;

    while (!finish) {
        sfRenderWindow_clear(global->window, sfWhite);
        show_sprite(global->window, "rs/Save_Menu_bg.png", (sfVector2f){0, 0},
        (sfVector2f){1.5, 1.5});
        sfRenderWindow_waitEvent(global->window, &event);
        disp_controls_icon(global, key_in_use);
        sfRenderWindow_display(global->window);
        if (event.type != sfEvtKeyPressed)
            continue;
        key_in_use = key_binder(global, 6);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

void bind_minimap(global_t *global)
{
    sfEvent event;
    int finish = 0;
    int key_in_use = 0;

    while (!finish) {
        sfRenderWindow_clear(global->window, sfWhite);
        show_sprite(global->window, "rs/Save_Menu_bg.png", (sfVector2f){0, 0},
        (sfVector2f){1.5, 1.5});
        sfRenderWindow_waitEvent(global->window, &event);
        disp_controls_icon(global, key_in_use);
        sfRenderWindow_display(global->window);
        if (event.type != sfEvtKeyPressed)
            continue;
        key_in_use = key_binder(global, 7);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

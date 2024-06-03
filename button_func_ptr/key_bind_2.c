/*
** EPITECH PROJECT, 2024
** binding
** File description:
** biding
*/

#include "../include/include.h"

void go_to_control_settings(global_t *global)
{
    global->settings->settings_index = 3;
}

void bind_select(global_t *global)
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
        key_in_use = key_binder(global, 4);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

void bind_interact(global_t *global)
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
        key_in_use = key_binder(global, 5);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

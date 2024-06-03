/*
** EPITECH PROJECT, 2024
** controls
** File description:
** controls
*/

#include "../include/include.h"

void bind_up(global_t *global)
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
        key_in_use = key_binder(global, 0);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

void bind_left(global_t *global)
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
        key_in_use = key_binder(global, 1);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

void bind_right(global_t *global)
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
        key_in_use = key_binder(global, 3);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

void bind_down(global_t *global)
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
        key_in_use = key_binder(global, 2);
        finish = key_in_use == 1 ? 0 : 1;
    }
}

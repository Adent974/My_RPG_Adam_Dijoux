/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"

void manage_select_obj_bis(global_t *global, int index, int glow)
{
    if (global->inventory_state == index + 1) {
        sfRectangleShape_setFillColor(global->select_tab[index]->shape,
        sfColor_fromRGBA(50, 50, 50, 180));
        glow = 1;
    }
    sfRenderWindow_drawRectangleShape(global->window,
    global->select_tab[index]->shape, NULL);
    if (glow)
        display_glow(global, (sfVector2f){250, 170},
        global->select_tab[index]->pos);
}

void manage_select_obj(global_t *global, int index)
{
    int glow = 0;

    sfRectangleShape_setFillColor(global->select_tab[index]->shape,
    sfColor_fromRGBA(0, 0, 0, 180));
    if (mouse_in_rect(global, global->select_tab[index]->shape)) {
        glow = 1;
        if (global->settings->mouse_pressed) {
            global->select_tab[index]->func(global);
            sfRectangleShape_setFillColor(global->select_tab[index]->shape,
            sfColor_fromRGB(180, 180, 180));
        }
    }
    manage_select_obj_bis(global, index, glow);
}

/*
** EPITECH PROJECT, 2024
** view
** File description:
** view
*/

#include "include/include.h"

void manage_view(global_t *global)
{
    sfVector2f view_val = global->pl->pos;

    if (view_val.x < 960)
        view_val.x = 960;
    if (view_val.x > 11040)
        view_val.x = 11040;
    if (view_val.y < 540)
        view_val.y = 540;
    if (view_val.y > 8450)
        view_val.y = 8450;
    if (global->pl->pos.x < 10)
        global->pl->pos.x = 10;
    if (global->pl->pos.y < 10)
        global->pl->pos.y = 10;
    if (global->pl->pos.x > 11990)
        global->pl->pos.x = 11990;
    if (global->pl->pos.y > 8950)
        global->pl->pos.y = 8950;
    sfView_setCenter(global->view, view_val);
    sfRenderWindow_setView(global->window, global->view);
}

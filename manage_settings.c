/*
** EPITECH PROJECT, 2024
** manage
** File description:
** manage
*/

#include "include/include.h"

void manage_window_size(global_t *global)
{
    if (global->settings->is_fullscreen)
        return;
    if (global->settings->window_size_type == 0)
        sfRenderWindow_setSize(global->window, (sfVector2u){1920, 1080});
    if (global->settings->window_size_type == 1)
        sfRenderWindow_setSize(global->window, (sfVector2u){1600, 900});
    if (global->settings->window_size_type == 2)
        sfRenderWindow_setSize(global->window, (sfVector2u){1280, 720});
}

void manage_highlight(global_t *global, button_t *actual_button)
{
    sfVector2f pos = {actual_button->pos.x - 10, actual_button->pos.y - 10};
    sfColor color[2] = {sfColor_fromRGBA(0, 0, 255, 25), sfBlue};
    sfVector3f size = {actual_button->size.x + 20,
    actual_button->size.y + 20, 2};

    show_rect(global->window, pos, color, size);
}

void manage_settings(global_t *global)
{
    sfView_setCenter(global->view, (sfVector2f){1920 / 2, 1080 / 2});
    sfRenderWindow_setView(global->window, global->view);
    sfRenderWindow_clear(global->window, sfBlack);
    show_sprite(global->window, "rs/settings_bg.png",
    (sfVector2f){160, 50}, (sfVector2f){12.5, 245.0 / 32.0});
    show_settings_button(global, global->settings->settings_buttons);
    manage_settings_buttons(global, global->settings->settings_buttons);
    if (global->settings->settings_index == 0)
        select_settings_page(global);
    if (global->settings->settings_index == 1)
        settings_video(global);
    if (global->settings->settings_index == 2)
        settings_game(global);
    if (global->settings->settings_index == 3)
        settings_controls(global);
}

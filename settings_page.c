/*
** EPITECH PROJECT, 2024
** page
** File description:
** page
*/

#include "include/include.h"

void settings_video(global_t *global)
{
    int index = global->settings->selected_button_index;

    if (index < 0) {
        global->settings->selected_button_index = 0;
        index = 0;
    }
    if (index > 3) {
        global->settings->selected_button_index = 0;
        index %= 4;
    }
    show_actual_res(global);
    manage_highlight(global, global->settings->settings_buttons[index]);
    show_video_icons(global);
}

void settings_controls(global_t *global)
{
    show_settings_button(global, global->settings->settings_buttons);
    show_controls_icons(global);
}

void settings_game(global_t *global)
{
    show_game_icons(global);
    show_volume(global);
}

void select_settings_page(global_t *global)
{
    int index = global->settings->selected_button_index;

    show_text(global->window, "VIDEO SETTINGS",
    (sfVector3f){730, 165, 70}, "rs/adam.ttf");
    show_text(global->window, "GAME SETTINGS",
    (sfVector3f){725, 365, 70}, "rs/adam.ttf");
    show_text(global->window, "EXIT SETTINGS",
    (sfVector3f){750, 575, 70}, "rs/adam.ttf");
    show_text(global->window, "GO TO MAIN MENU",
    (sfVector3f){710, 770, 70}, "rs/adam.ttf");
    if (index < 4) {
        global->settings->selected_button_index = 6;
        index = 6;
    }
    if (index > 6) {
        global->settings->selected_button_index = 4;
        index = 4;
    }
    manage_highlight(global, global->settings->settings_buttons[index]);
}

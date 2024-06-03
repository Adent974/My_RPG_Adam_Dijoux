/*
** EPITECH PROJECT, 2024
** settings
** File description:
** settings
*/

#include "../include/include.h"

void go_to_main_settings(global_t *global)
{
    global->settings->settings_index = 0;
}

void go_to_video_settings(global_t *global)
{
    global->settings->settings_index = 1;
}

void go_to_game_settings(global_t *global)
{
    global->settings->settings_index = 2;
}

void go_to_main_menu(global_t *global)
{
    global->state_game = sfFalse;
}

void save_settings(global_t *global)
{
    global->settings->settings_index = 0;
    global->settings->settings_active = 0;
    if (global->state_menu)
        global->state_game = sfFalse;
}

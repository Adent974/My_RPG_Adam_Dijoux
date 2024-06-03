/*
** EPITECH PROJECT, 2024
** fnc
** File description:
** func
*/

#include "../include/include.h"

void fullscreen_func(global_t *global)
{
    global->settings->is_fullscreen += 1;
    global->settings->is_fullscreen %= 2;
    if (global->settings->is_fullscreen){
        global->exit_program = 1;
        sfRenderWindow_destroy(global->window);
        global->window = window_create_fullscreen(1920, 1080, 32, 60);
    } else {
        global->exit_program = 1;
        sfRenderWindow_destroy(global->window);
        global->window = window_create(1920, 1080, 32, 60);
    }
    return;
}

void change_resolution_right(global_t *global)
{
    global->settings->window_size_type -= 1;
    if (global->settings->window_size_type < 0)
        global->settings->window_size_type = 2;
    return;
}

void change_resolution_left(global_t *global)
{
    global->settings->window_size_type += 1;
    global->settings->window_size_type %= 3;
    return;
}

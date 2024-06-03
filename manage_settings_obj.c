/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"


void manage_graphics(global_t *global)
{
    for (int i = 0; global->graphics_tab[i]; i++) {
        sfRenderWindow_drawRectangleShape(global->window,
        global->graphics_tab[i]->shape, NULL);
        if (mouse_in_rect(global, global->graphics_tab[i]->shape) &&
        global->settings->mouse_pressed)
            global->graphics_tab[i]->func(global);
    }
}

void manage_audio(global_t *global)
{
    for (int i = 0; global->audio_tab[i]; i++) {
        if (i != 7 && i != 8)
            sfRenderWindow_drawRectangleShape(global->window,
            global->audio_tab[i]->shape, NULL);
        if (mouse_in_rect(global, global->audio_tab[i]->shape) &&
        global->settings->mouse_pressed)
            global->audio_tab[i]->func(global);
        show_volume(global);
    }
}

void manage_controls(global_t *global)
{
    for (int i = 0; global->controls_tab[i]; i++) {
        sfRenderWindow_drawRectangleShape(global->window,
        global->controls_tab[i]->shape, NULL);
        if (mouse_in_rect(global, global->controls_tab[i]->shape) &&
        global->settings->mouse_pressed)
            global->controls_tab[i]->func(global);
    }
}

void manage_settings_menu_tab(global_t *global)
{
    for (int i = 0; global->settings_menu_tab[i]; i++) {
        sfRenderWindow_drawRectangleShape(global->window,
        global->settings_menu_tab[i]->shape, NULL);
        if (mouse_in_rect(global, global->settings_menu_tab[i]->shape) &&
        global->settings->mouse_pressed)
            global->settings_menu_tab[i]->func(global);
    }
}

void manage_settings_obj(global_t *global)
{
    if (global->settings_state == 1)
        manage_graphics(global);
    if (global->settings_state == 2)
        manage_audio(global);
    if (global->settings_state == 3)
        manage_controls(global);
    if (global->settings_state == 0)
        manage_settings_menu_tab(global);
}

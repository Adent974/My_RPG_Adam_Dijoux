/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "../include/include.h"

void tmp(global_t *global)
{
    global = global;
}

void state_6(global_t *global)
{
    global->save_ui_state = 0;
}

void graphics_state(global_t *global)
{
    global->settings_state = 1;
}

void audio_state(global_t *global)
{
    global->settings_state = 2;
}

void control_state(global_t *global)
{
    global->settings_state = 3;
}

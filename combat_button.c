/*
** EPITECH PROJECT, 2024
** display and handle all the buttons for the combat interface
** File description:
** combat_buttons
*/

#include "include/include.h"

void display_attack(global_t *gl)
{
    if (gl->selecting == 0){
        gl->combat->active_attack += 1;
        gl->combat->active_attack %= 2;
        gl->settings->mouse_pressed = 0;
        gl->settings->mouse_released = 0;
        gl->selecting = 1;
    }
}

void display_inventory(global_t *gl)
{
    if (gl->selecting == 0){
        gl->combat->active_inventory += 1;
        gl->combat->active_inventory %= 2;
        gl->settings->mouse_pressed = 0;
        gl->settings->mouse_released = 0;
        gl->selecting = 1;
    }
}

void display_spells(global_t *gl)
{
    if (gl->selecting == 0){
        gl->combat->active_spells += 1;
        gl->combat->active_spells %= 2;
        gl->settings->mouse_pressed = 0;
        gl->settings->mouse_released = 0;
        gl->selecting = 1;
    }
}

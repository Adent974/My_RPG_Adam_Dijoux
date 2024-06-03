/*
** EPITECH PROJECT, 2024
** ui bt
** File description:
** ui bt
*/

#include "../include/include.h"

void button_load(global_t *global)
{
    global->save_ui_state = 1;
}

void button_save(global_t *global)
{
    global->save_ui_state = 2;
}

void quit_save_ui(global_t *global)
{
    global->save_ui_state = -1;
    global->inventory_state = 3;
}

void main_ui(global_t *global)
{
    global->save_ui_state = 0;
}

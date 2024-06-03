/*
** EPITECH PROJECT, 2024
** save ui
** File description:
** save ui
*/

#include "../include/include.h"

void save_slot_1(global_t *global)
{
    create_save(global, 0);
    global->save_ui_state = 0;
}

void save_slot_2(global_t *global)
{
    create_save(global, 1);
    global->save_ui_state = 0;
}

void save_slot_3(global_t *global)
{
    create_save(global, 2);
    global->save_ui_state = 0;
}

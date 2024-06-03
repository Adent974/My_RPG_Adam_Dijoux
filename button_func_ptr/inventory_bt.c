/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "../include/include.h"

void state_1(global_t *global)
{
    global->state_game = sfFalse;
}

void state_2(global_t *global)
{
    global->inventory_state = 2;
    global->settings_state = 0;
}

void state_3(global_t *global)
{
    global->inventory_state = 3;
}

void state_4(global_t *global)
{
    global->inventory_state = 4;
}

void state_5(global_t *global)
{
    global->inventory_state = 5;
}

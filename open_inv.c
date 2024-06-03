/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/
#include "include/include.h"


void use_all_eq(global_t *global)
{
    for (int i = 0; global->pl->inv->gears[i]; i++){
        if (global->pl->inv->gears[i]->name != NULL){
            use(global, NULL, global->pl->inv->gears[i]);
        }
    }
}

void open_inv(global_t *global)
{
    for (int i = 0; global->pl->inv->items[i]; i++){
        if (global->pl->inv->items[i]->name != NULL){
            use(global, global->pl->inv->items[i], NULL);
        }
    }
}

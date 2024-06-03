/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "include/include.h"

void add_item(inventory_t *inv, item_t *new, int nbr)
{
    for (int i = 0; inv->items[i]; i++) {
        if (inv->items[i]->name == NULL){
            inv->items[i] = new;
            inv->items[i]->quantity += nbr;
            return;
        }
        if (strcmp(inv->items[i]->name, new->name) == 0){
            inv->items[i]->quantity += nbr;
            return;
        }
    }
}

void add_gear(inventory_t *inv, gear_t *new)
{
    for (int i = 0; inv->gears[i]; i++){
        if (inv->gears[i]->name == NULL){
            inv->gears[i] = new;
            return;
        }
    }
}

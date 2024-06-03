/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

int get_random_id(int a, int b)
{
    int id = 0;

    id = rand() % b + a;
    return id;
}

item_t *get_random_item(int a, int b)
{
    return get_item(all_items[get_random_id(a, b)].name);
}

item_t *un_item(item_t *items)
{
    items->name = NULL;
    items->type = NULL;
    items->desc = NULL;
    items->dmg = 0;
    items->crit = 0;
    items->quantity = 0;
    items->mode = 0;
    items->img = NULL;
    items->func = NULL;
    return items;
}

gear_t *un_gear(gear_t *gear)
{
    gear->name = NULL;
    gear->type = NULL;
    gear->dmg = 0;
    gear->crit = 0;
    gear->def = 0;
    gear->force = 0;
    gear->duration = 0;
    gear->mode = 1;
    gear->used = 0;
    gear->img = NULL;
    gear->func = NULL;
    gear->desc = NULL;
    return gear;
}

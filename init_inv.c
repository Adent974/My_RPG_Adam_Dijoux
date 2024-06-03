/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/
#include "include/include.h"

gear_t *init_armor_test(gear_t *gear, char *name)
{
    gear_t *gear_copy = get_gear(name);

    gear = gear;
    return gear_copy;
}

item_t *init_item_test(item_t *item, char *name)
{
    item_t *item_copy = get_item(name);

    item = item;
    return item_copy;
}

item_t *reset_item(item_t *items)
{
    items = my_malloc(sizeof(gear_t) + 1);
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

static void init_gear(gear_t **gears, int gear_nbr)
{
    int i = 0;

    for (; i < gear_nbr; i++) {
        gears[i] = my_malloc(sizeof(gear_t) + 1);
        gears[i]->name = NULL;
        gears[i]->dmg = 0;
        gears[i]->def = 0;
        gears[i]->crit = 0;
        gears[i]->duration = 0;
        gears[i]->force = 0;
        gears[i]->mode = 1;
        gears[i]->used = 0;
        gears[i]->img = NULL;
    }
    gears[i] = NULL;
}

static void init_items(item_t **items, int item_nbr)
{
    int i = 0;

    for (; i < item_nbr; i++) {
        items[i] = reset_item(items[i]);
    }
    items[i] = NULL;
}

inventory_t *init_inventory(player_t *player)
{
    inventory_t *tmp = my_malloc(sizeof(inventory_t) + 1);

    player = player;
    tmp->stunner = NULL;
    tmp->slasher = NULL;
    tmp->ranger = NULL;
    tmp->spells[0] = NULL;
    tmp->spells[1] = NULL;
    tmp->spells[2] = NULL;
    tmp->spells[3] = NULL;
    tmp->armor = NULL;
    tmp->weapon = 0;
    tmp->gears = my_malloc(sizeof(gear_t *) * (8 + 1));
    init_gear(tmp->gears, 8);
    tmp->items = my_malloc(sizeof(item_t *) * (8 + 1));
    init_items(tmp->items, 8);
    return tmp;
}

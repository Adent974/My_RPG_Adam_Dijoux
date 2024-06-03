/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

void init_obj(object_t *obj, gear_t *gear)
{
    obj = my_malloc(sizeof(gear_t *) + 1);
    obj = gear->img;
    obj = obj;
}

void replace_gear(inventory_t *inv, gear_t *deleted, gear_t *added)
{
    int i = delete_gear(inv, deleted);

    i = i;
    added = added;
}

int delete_gear(inventory_t *inv, gear_t *target)
{
    un_gear(target);
    inv = inv;
    return 0;
}

int delete_items(inventory_t *inv, item_t *target, int nbr)
{
    target->quantity -= nbr;
    if (target->quantity <= 0){
        un_item(target);
    }
    inv = inv;
    return 0;
}

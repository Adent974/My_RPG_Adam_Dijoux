/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/
#include "include/include.h"

gear_t *gear_from_inv(global_t *gl, char *name)
{
    for (int i = 0; i < 8; i++) {
        if (gl->pl->inv->gears[i]->name == NULL){
            continue;
        }
        if (strcmp(gl->pl->inv->gears[i]->name, name) == 0){
            return gl->pl->inv->gears[i];
        }
    }
    return NULL;
}

item_t *item_from_inv(global_t *gl, char *name)
{
    for (int i = 0; gl->pl->inv->items[i]; i++) {
        if (gl->pl->inv->items[i] == NULL)
            continue;
        if (my_strcmp(gl->pl->inv->items[i]->name, name) == 0){
            return gl->pl->inv->items[i];
        }
    }
    return NULL;
}

item_t *get_item(char *name)
{
    int j = 0;
    item_t *item = my_malloc(sizeof(item_t));

    for (; all_items[j].name; j++){
        if (strcmp(all_items[j].name, name) == 0) {
            *item = all_items[j];
            return item;
        }
    }
    *item = all_items[j];
    return item;
}

gear_t *get_gear(char *name)
{
    int j = 0;
    gear_t *gear = my_malloc(sizeof(gear_t));

    for (; all_gears[j].name; j++){
        if (my_strcmp(all_gears[j].name, name) == 0) {
            *gear = all_gears[j];
            return gear;
        }
    }
    *gear = all_gears[j];
    return gear;
}

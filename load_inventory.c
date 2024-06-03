/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"

void load_gear(global_t *global, char *content)
{
    gear_t *gear = get_gear(content);

    add_gear(global->pl->inv, gear);
}

void load_item(global_t *global, char *content)
{
    char *tmp = strdup(content);
    char **tab = my_str_to_array(tmp, ":");
    item_t *item = get_item(tab[0]);

    add_item(global->pl->inv, item, atoi(tab[1]));
    mini_cleaner(tmp, tab);
}

void load_inventory(global_t *global, char **content)
{
    int i = 0;

    for (i = 0; global->pl->inv->gears[i]; i++)
        delete_gear(global->pl->inv, global->pl->inv->gears[i]);
    for (i = 0; global->pl->inv->items[i]; i++)
        delete_items(global->pl->inv, global->pl->inv->items[i],
        global->pl->inv->items[i]->quantity);
    for (i = 0; content[i]; i++)
        if (strcmp(content[i], "#GEAR#") == 0) {
            i++;
            break;
        }
    for (; content[i] && strcmp(content[i], "#ITEM#") != 0; i++)
        load_gear(global, content[i]);
    i++;
    for (; content[i] && strcmp(content[i], "##PNJ##") != 0; i++)
        load_item(global, content[i]);
}

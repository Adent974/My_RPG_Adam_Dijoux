/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

void equip_spell(global_t *global, gear_t *gear, gear_t **spells)
{
    global = global;
    for (int i = 0; i < 4; i++){
        if (spells[i] != NULL)
            continue;
        spells[i] = gear;
        return;
    }
}

void equip(global_t *global, gear_t *gear)
{
    if (gear == NULL)
        return;
    if (strcmp(gear->type, "Spell") == 0){
        equip_spell(global, gear, global->pl->inv->spells);
    }
    if (strcmp(gear->type, "Stun") == 0)
        global->pl->inv->stunner = gear;
    if (strcmp(gear->type, "Slash") == 0)
        global->pl->inv->slasher = gear;
    if (strcmp(gear->type, "Range") == 0)
        global->pl->inv->ranger = gear;
    if (strcmp(gear->type, "Armor") == 0)
        global->pl->inv->armor = gear;
}

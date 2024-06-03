/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

void poison(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    gl = gl;
    if (statlist->poison->force > 0){
        stats->hp -= statlist->poison->force;
        statlist->poison->force += statlist->poison->force / 100 + 1;
        statlist->poison->duration += 1;
    } else if (statlist->poison->duration > 0){
        statlist->poison->force = 0;
        statlist->poison->duration -= 1;
    }
}

void burn(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    gl = gl;
    if (statlist->burn->duration < 0){
        stats->hp -= statlist->burn->force;
        statlist->burn->duration += 1;
    } else if (statlist->burn->duration > 0){
        stats->hp += statlist->burn->force;
        statlist->burn->duration -= 1;
    }
}

void effect_of_status(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    if (statlist->poison->duration != 0)
        poison(gl, statlist, stats);
    if (statlist->burn->duration != 0)
        burn(gl, statlist, stats);
    if (statlist->para->duration != 0)
        para(gl, statlist, stats);
    if (statlist->frozen->duration != 0)
        freeze(gl, statlist, stats);
    if (statlist->atk_boost->duration != 0)
        atk_change(gl, statlist, stats);
    else
        stats->dmg = stats->dmg_save;
    if (statlist->def_boost->duration != 0)
        def_change(gl, statlist, stats);
    else
        stats->def = stats->def_save;
}

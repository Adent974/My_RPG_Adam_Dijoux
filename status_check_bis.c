/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

void freeze(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    gl = gl;
    if (statlist->para->duration < 0){
        stats->skip += 2;
        statlist->frozen->duration += 1;
    } else if (statlist->para->duration > 0){
        stats->skip -= 2;
        statlist->frozen->duration -= 1;
    }
}

void para(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    gl = gl;
    if (statlist->para->duration < 0){
        stats->skip += 0.5;
        statlist->para->duration += 1;
    } else if (statlist->para->duration > 0){
        stats->skip -= 0.5;
        statlist->para->duration -= 1;
    }
}

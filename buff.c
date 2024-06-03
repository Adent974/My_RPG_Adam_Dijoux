/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

void atk_change(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    gl = gl;
    if (statlist->atk_boost->duration < 0){
        stats->dmg = stats->dmg_save + statlist->atk_boost->force;
        statlist->atk_boost->duration += 1;
    } else if (statlist->atk_boost->duration > 0) {
        stats->dmg = stats->dmg_save - statlist->atk_boost->force;
        statlist->atk_boost->duration -= 1;
    }
}

void def_change(global_t *gl, statlist_t *statlist, stats_t *stats)
{
    gl = gl;
    if (statlist->def_boost->duration < 0){
        stats->def = stats->def_save + statlist->def_boost->force;
        statlist->def_boost->duration += 1;
    } else if (statlist->def_boost->duration > 0) {
        stats->def = stats->def_save - statlist->def_boost->force;
        statlist->def_boost->duration -= 1;
    }
}

void atk_buff(struct global_s *global, gear_t *gear, item_t *item, int mode)
{
    int val1 = 0;
    int val2 = 0;

    if (gear != NULL){
        val1 = gear->duration;
        val2 = gear->force;
    }
    if (item != NULL){
        val1 = item->crit;
        val2 = item->dmg;
    }
    if (mode == 0){
        global->pl->status_list->atk_boost->duration -= val1;
        global->pl->status_list->atk_boost->force += val2;
    }
    if (mode > 0){
        global->combat->curent_enemy->status_list->atk_boost->duration -= val1;
        global->combat->curent_enemy->status_list->atk_boost->force += val2;
    }
}

void def_buff(struct global_s *global, gear_t *gear, item_t *item, int mode)
{
    int val1 = 0;
    int val2 = 0;

    if (gear != NULL){
        val1 = gear->duration;
        val2 = gear->force;
    }
    if (item != NULL){
        val1 = item->crit;
        val2 = item->dmg;
    }
    if (mode == 0){
        global->pl->status_list->def_boost->duration -= val1;
        global->pl->status_list->def_boost->force += val2;
    }
    if (mode > 0){
        global->combat->curent_enemy->status_list->def_boost->duration -= val1;
        global->combat->curent_enemy->status_list->def_boost->force += val2;
    }
}

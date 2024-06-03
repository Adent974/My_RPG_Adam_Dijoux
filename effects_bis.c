/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

void reco_mana(struct global_s *global, gear_t *gear, item_t *item, int mode)
{
    mode = mode;
    if (item != NULL) {
        global->pl->stats->mana += item->dmg;
        if (global->pl->stats->mana > global->pl->stats->max_mana)
            global->pl->stats->mana = global->pl->stats->max_mana;
    }
    if (gear != NULL) {
        global->pl->stats->mana += gear->force;
        if (global->pl->stats->mana > global->pl->stats->max_mana)
            global->pl->stats->mana = global->pl->stats->max_mana;
    }
}

void reco_mana_percent(struct global_s *global, gear_t *gear,
    item_t *item, int mode)
{
    mode = mode;
    gear = gear;
    global->pl->stats->mana += (item->dmg * global->pl->stats->max_mana) / 100;
    if (global->pl->stats->mana > global->pl->stats->max_mana)
        global->pl->stats->mana = global->pl->stats->max_mana;
}

void heal(struct global_s *global, gear_t *gear, item_t *item, int mode)
{
    mode = mode;
    gear = gear;
    global->pl->stats->hp += item->dmg;
    if (global->pl->stats->hp > global->pl->stats->max_hp)
        global->pl->stats->hp = global->pl->stats->max_hp;
}

void heal_percent(struct global_s *global, gear_t *gear,
    item_t *item, int mode)
{
    mode = mode;
    gear = gear;
    global->pl->stats->hp += (item->dmg * global->pl->stats->max_hp) / 100;
    if (global->pl->stats->hp > global->pl->stats->max_hp)
        global->pl->stats->hp = global->pl->stats->max_hp;
}

void apply_frozen(struct global_s *global, gear_t *gear,
    item_t *item, int mode)
{
    int val1 = 0;
    int val2 = 0;

    mode = mode;
    if (gear != NULL){
        val1 = gear->duration;
        val2 = gear->force;
    }
    if (item != NULL){
        val1 = item->crit;
        val2 = item->dmg;
    }
    if (mode == 0){
        global->pl->status_list->frozen->duration -= val1;
        global->pl->status_list->frozen->force += val2;
    }
    if (mode > 0){
        global->combat->curent_enemy->status_list->frozen->duration -= val1;
        global->combat->curent_enemy->status_list->frozen->force += val2;
    }
}

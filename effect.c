/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

void apply_para(struct global_s *global, gear_t *gear, item_t *item, int mode)
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
        global->pl->status_list->para->duration -= val1;
        global->pl->status_list->para->force += val2;
    }
    if (mode > 0){
        global->combat->curent_enemy->status_list->para->duration -= val1;
        global->combat->curent_enemy->status_list->para->force += val2;
    }
}

void apply_poison(struct global_s *global, gear_t *gear,
    item_t *item, int mode)
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
        global->pl->status_list->poison->duration -= val1;
        global->pl->status_list->poison->force += val2;
    }
    if (mode > 0){
        global->combat->curent_enemy->status_list->poison->duration -= val1;
        global->combat->curent_enemy->status_list->poison->force += val2;
    }
}

void apply_burn(struct global_s *global, gear_t *gear, item_t *item, int mode)
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
        global->pl->status_list->burn->duration -= val1;
        global->pl->status_list->burn->force += val2;
    }
    if (mode > 0){
        global->combat->curent_enemy->status_list->burn->duration -= val1;
        global->combat->curent_enemy->status_list->burn->force += val2;
    }
}

void freeze_or_burn(struct global_s *global, gear_t *gear,
    item_t *item, int mode)
{
    int i = 0;

    i = rand() % 2;
    if (i > 0)
        apply_burn(global, gear, item, mode);
    else
        apply_frozen(global, gear, item, mode);
}

void use(global_t *global, item_t *item, gear_t *gear)
{
    if (item != NULL && item->func != NULL
    && item->quantity > 0){
        item->func(global, NULL, item, item->mode);
        delete_items(global->pl->inv, item, 1);
    }
    if (gear != NULL && gear->func != NULL){
        gear->func(global, gear, NULL, gear->mode);
    }
}

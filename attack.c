/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

int get_bully_crit(int bully_i)
{
    int crit = rand() % 101 + 1;

    if (crit <= bully_i)
        crit = 1;
    else
        crit = 0;
    return crit;
}

int get_bully_atk(stats_t *bully, int is_crit, global_t *global)
{
    int atk = bully->dmg;

    if (bully->mode == 0){
        if (global->pl->inv->weapon == 0 && global->pl->inv->stunner != NULL)
            atk += global->pl->inv->stunner->dmg;
        if (global->pl->inv->weapon == 1 && global->pl->inv->slasher != NULL)
            atk += global->pl->inv->slasher->dmg;
        if (global->pl->inv->weapon == 2 && global->pl->inv->ranger != NULL)
            atk += global->pl->inv->ranger->dmg;
        if (is_crit == 1 && global->pl->inv->weapon == 0)
            apply_para(global, global->pl->inv->stunner, NULL, 1);
        if (is_crit == 1 && global->pl->inv->weapon == 1)
            atk *= 2;
        if (is_crit == 1 && global->pl->inv->weapon == 2){
            printf("Super Mael\n");
        }
    }
    return atk;
}

int launch_attack(global_t *global, stats_t *bully, stats_t *target)
{
    int bully_atk = 0;
    int defense_diff = 0;

    bully_atk = get_bully_atk(bully, get_bully_crit(bully->crit), global);
    defense_diff = target->def / (bully_atk / target->def + 1) + 1;
    if (defense_diff < 0)
        defense_diff = 0;
    bully_atk = bully_atk - defense_diff;
    if (bully_atk <= 0)
        bully_atk = 1;
    target->hp -= bully_atk;
    if (bully->mode == 1 && global->pl->inv->armor != NULL){
        use(global, NULL, global->pl->inv->armor);
    }
    return 1;
}

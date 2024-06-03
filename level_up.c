/*
** EPITECH PROJECT, 2024
** lvl_up
** File description:
** my mooscles are getting bigger
*/

#include "include/include.h"

void all_stats_inc(player_t *player)
{
    player->stats->hp += player->level;
    player->stats->mana += player->level;
    player->stats->max_hp += player->level;
    player->stats->max_mana += player->level;
    player->stats->crit += player->level;
    player->stats->dmg += player->level;
    player->stats->def += player->level;
    player->stats->prec += player->level;
    player->stats->esq += player->level;
    player->nb_skill_pts += 2;
}

void xp_up(global_t *global)
{
    int xp_diff = 0;
    int xp_plus = global->combat->curent_enemy->xp_given;

    global->pl->xp += xp_plus;
    if (global->pl->xp >= global->pl->xp_limit){
        global->pl->xp = 0;
        global->pl->level += 1;
        global->pl->xp_limit += 10;
        all_stats_inc(global->pl);
    }
}

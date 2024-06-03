/*
** EPITECH PROJECT, 2024
** bat
** File description:
** handle all the function for an enemy in combat
*/
#include "include/include.h"

void enemy_disp(global_t *gl)
{
    if (gl->combat->active_inventory == 1)
        return;
    sfRectangleShape_setSize(gl->combat->curent_enemy->hp_bar[1]
        , (sfVector2f){get_ratio(gl->combat->curent_enemy->stats->hp,
        gl->combat->curent_enemy->stats->max_hp, 600), 30});
    sfRenderWindow_drawText(gl->window, gl->pl->bars->texts[4], NULL);
    for (int i = 0; gl->combat->curent_enemy->hp_bar[i]; i++)
        sfRenderWindow_drawRectangleShape(gl->window
            , gl->combat->curent_enemy->hp_bar[i], NULL);
}

void enemy_turn(global_t *gl)
{
    if (gl->combat->curent_enemy->stats->skip >= 1){
        gl->combat->curent_enemy->stats->skip -= 1;
        return;
    }
    if (gl->combat->curent_enemy->dead == 1)
        return;
    launch_attack(gl, gl->combat->curent_enemy->stats, gl->pl->stats);
    if (gl->pl->stats->hp < 0)
        gl->pl->stats->hp = 0;
    sfSprite_setScale(gl->combat->curent_enemy->obj->sprite,
        (sfVector2f){0.5, 0.5});
}

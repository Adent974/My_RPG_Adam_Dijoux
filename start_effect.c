/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

void apply_status(global_t *gl)
{
    if (gl->combat->curent_enemy != NULL)
        effect_of_status(gl, gl->combat->curent_enemy->status_list
        , gl->combat->curent_enemy->stats);
    effect_of_status(gl, gl->pl->status_list, gl->pl->stats);
}

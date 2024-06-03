/*
** EPITECH PROJECT, 2024
** sfx
** File description:
** sfx
*/

#include "../include/include.h"

void sfx_up(global_t *global)
{
    global->settings->sfx_volume += 10;
    if (global->settings->sfx_volume > 100)
        global->settings->sfx_volume = 100;
}

void sfx_down(global_t *global)
{
    global->settings->sfx_volume -= 10;
    if (global->settings->sfx_volume < 0)
        global->settings->sfx_volume = 0;
}

void mute_sfx(global_t *global)
{
    if (global->settings->sfx_mute)
        global->settings->sfx_mute = sfFalse;
    else
        global->settings->sfx_mute = sfTrue;
}

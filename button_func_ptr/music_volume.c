/*
** EPITECH PROJECT, 2024
** music
** File description:
** music
*/

#include "../include/include.h"

void music_up(global_t *global)
{
    global->settings->music_volume += 10;
    if (global->settings->music_volume > 100)
        global->settings->music_volume = 100;
    sfMusic_setVolume(global->settings->main_music,
        global->settings->music_volume);
}

void music_down(global_t *global)
{
    global->settings->music_volume -= 10;
    if (global->settings->music_volume < 0)
        global->settings->music_volume = 0;
    sfMusic_setVolume(global->settings->main_music,
        global->settings->music_volume);
}

void mute_volume(global_t *global)
{
    if (global->settings->volume_mute)
        global->settings->volume_mute = sfFalse;
    else
        global->settings->volume_mute = sfTrue;
}

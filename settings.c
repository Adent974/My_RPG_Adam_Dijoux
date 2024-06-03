/*
** EPITECH PROJECT, 2024
** setting
** File description:
** settings
*/

#include "include/include.h"

void show_actual_res(global_t *global)
{
    sfColor color[2] = {sfWhite, sfBlack};

    show_rect(global->window, (sfVector2f){815, 250},
    color, (sfVector3f){500, 125, 2});
    if (global->settings->is_fullscreen) {
        show_text(global->window, "FULLSCREEN",
        (sfVector3f){840, 255, 85}, "rs/adam.ttf");
        return;
    }
    if (global->settings->window_size_type == 0)
        show_text(global->window, "1920 x 1080",
        (sfVector3f){830, 250, 85}, "rs/adam.ttf");
    if (global->settings->window_size_type == 1)
        show_text(global->window, "1600 x 900",
        (sfVector3f){840, 250, 85}, "rs/adam.ttf");
    if (global->settings->window_size_type == 2)
        show_text(global->window, "1280 x 720",
        (sfVector3f){840, 250, 85}, "rs/adam.ttf");
}

void show_settings_button(global_t *global, button_t **buttons)
{
    if (global->settings->settings_index == 0) {
        for (int i = 4; i < 8; i++)
            sfRenderWindow_drawSprite(global->window,
            buttons[i]->sprite, NULL);
    }
    if (global->settings->settings_index == 1) {
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawSprite(global->window,
            buttons[i]->sprite, NULL);
    }
    if (global->settings->settings_index == 2) {
        for (int i = 15; i < 23; i++)
            sfRenderWindow_drawSprite(global->window,
            buttons[i]->sprite, NULL);
    }
    if (global->settings->settings_index == 3) {
        for (int i = 8; i < 15; i++)
            sfRenderWindow_drawSprite(global->window,
            buttons[i]->sprite, NULL);
    }
}

static void check_volume_sfx(global_t *global)
{
    if (global->settings->sfx_volume >= 60)
        global->settings->rect.left = 685;
    if (global->settings->sfx_volume <= 60)
        global->settings->rect.left = 465;
    if (global->settings->sfx_volume <= 30)
        global->settings->rect.left = 265;
    if (global->settings->sfx_volume == 0)
        global->settings->rect.left = 25;
    if (global->settings->sfx_mute)
        global->settings->rect.left = 25;
    sfSprite_setTextureRect(global->settings->volume_sprite2,
    global->settings->rect);
}

static void check_volume(global_t *global)
{
    if (global->settings->music_volume >= 60)
        global->settings->rect.left = 685;
    if (global->settings->music_volume <= 60)
        global->settings->rect.left = 465;
    if (global->settings->music_volume <= 30)
        global->settings->rect.left = 265;
    if (global->settings->music_volume == 0)
        global->settings->rect.left = 25;
    if (global->settings->volume_mute)
        global->settings->rect.left = 25;
    sfSprite_setTextureRect(global->settings->volume_sprite1,
    global->settings->rect);
    check_volume_sfx(global);
}

static void check_mute_bis(global_t *global)
{
    if (global->settings->sfx_mute) {
        sfSprite_setTextureRect(global->settings->volume_sprite2,
        global->settings->rect);
    } else {
        sfSprite_setTextureRect(global->settings->volume_sprite2,
        global->settings->rect);
    }
}

static void check_mute(global_t *global)
{
    if (global->settings->volume_mute)
        sfMusic_setVolume(global->settings->main_music, 0);
    else {
        sfSprite_setTextureRect(global->settings->volume_sprite1,
        global->settings->rect);
        sfMusic_setVolume(global->settings->main_music,
        global->settings->music_volume);
    }
    check_mute_bis(global);
}

void show_volume(global_t *global)
{
    sfColor color[2] = {sfColor_fromRGB(80, 80, 80), sfBlack};
    sfColor color2[2] = {sfColor_fromRGB(150, 150, 150), sfBlack};

    show_rect(global->window, (sfVector2f){675, 225},
    color, (sfVector3f){800, 100, 2});
    show_rect(global->window, (sfVector2f){675, 225},
    color2, (sfVector3f){global->settings->music_volume * 8, 100, 2});
    show_rect(global->window, (sfVector2f){675, 525},
    color, (sfVector3f){800, 100, 2});
    show_rect(global->window, (sfVector2f){675, 525},
    color2, (sfVector3f){global->settings->sfx_volume * 8, 100, 2});
    check_mute(global);
    check_volume(global);
    sfRenderWindow_drawSprite(global->window,
    global->settings->volume_sprite1, NULL);
    sfRenderWindow_drawSprite(global->window,
    global->settings->volume_sprite2, NULL);
}

/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"

void display_settings_graphics(global_t *global)
{
    int fc = global->settings->is_fullscreen;

    display_text(global, (sfVector2f){490, 250}, 65, "<<");
    if (fc)
        display_text(global, (sfVector2f){725, 275}, 75, "FULLSCREEN");
    if (global->settings->window_size_type == 0 && !fc)
        display_text(global, (sfVector2f){900, 250}, 80, "1920 X 1080");
    if (global->settings->window_size_type == 1 && !fc)
        display_text(global, (sfVector2f){900, 250}, 80, "1600 X 900");
    if (global->settings->window_size_type == 2 && !fc)
        display_text(global, (sfVector2f){900, 250}, 80, "1280 X 720");
    display_text(global, (sfVector2f){1740, 250}, 65, ">>");
    if (fc)
        display_text(global, (sfVector2f){550, 600},
        60, "SET TO WINDOWED MODE");
    else
        display_text(global, (sfVector2f){550, 600},
        55, "SET TO FULLSCREEN MODE");
    display_text(global, (sfVector2f){1700, 985}, 45, "Return");
}

static void display_keys_bis(global_t *global)
{
    display_text(global, (sfVector2f){1125, 375}, 40,
    binds[global->settings->move_keys[4]]);
    display_text(global, (sfVector2f){1275, 375}, 40, "Select");
    display_text(global, (sfVector2f){1125, 575}, 40,
    binds[global->settings->move_keys[6]]);
    display_text(global, (sfVector2f){1275, 575}, 40, "Confirm");
    display_text(global, (sfVector2f){1125, 775}, 40,
    binds[global->settings->move_keys[7]]);
    display_text(global, (sfVector2f){1275, 775}, 40, "Show Map");
    display_text(global, (sfVector2f){1700, 985}, 45, "Return");
}

void display_settings_keys(global_t *global)
{
    display_text(global, (sfVector2f){625, 425}, 40,
    binds[global->settings->move_keys[0]]);
    display_text(global, (sfVector2f){625, 575}, 40,
    binds[global->settings->move_keys[1]]);
    display_text(global, (sfVector2f){475, 575}, 40,
    binds[global->settings->move_keys[2]]);
    display_text(global, (sfVector2f){775, 575}, 40,
    binds[global->settings->move_keys[3]]);
    display_text(global, (sfVector2f){1125, 175}, 40,
    binds[global->settings->move_keys[5]]);
    display_text(global, (sfVector2f){1275, 175}, 40, "Interact");
    display_keys_bis(global);
}

void display_settings_audio(global_t *global)
{
    display_text(global, (sfVector2f){480, 225}, 65, "<<");
    display_text(global, (sfVector2f){1765, 225}, 65, ">>");
    display_text(global, (sfVector2f){480, 530}, 65, "<<");
    display_text(global, (sfVector2f){1765, 530}, 65, ">>");
    display_text(global, (sfVector2f){1700, 985}, 45, "Return");
}

void display_settings_text(global_t *global)
{
    if (global->inventory_state != 2)
        return;
    if (global->settings_state == 0) {
        sfText_setFont(global->inventory_text, global->startup_font);
        display_text(global, (sfVector2f){900, 175}, 65, "GRAPHICS");
        display_text(global, (sfVector2f){970, 450}, 65, "AUDIO");
        display_text(global, (sfVector2f){900, 800}, 65, "CONTROLS");
    }
    if (global->settings_state == 1)
        display_settings_graphics(global);
    if (global->settings_state == 2)
        display_settings_audio(global);
    if (global->settings_state == 3)
        display_settings_keys(global);
}

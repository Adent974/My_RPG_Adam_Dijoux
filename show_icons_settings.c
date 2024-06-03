/*
** EPITECH PROJECT, 2024
** icon
** File description:
** icon
*/

#include "include/include.h"

void show_binded_key(global_t *global, int key, sfVector3f dimensions)
{
    show_text(global->window, binds[key], dimensions, "rs/adam.ttf");
}

static void show_actual_keys(global_t *global)
{
    show_binded_key(global, global->settings->move_keys[0],
    (sfVector3f){725, 250, 50});
    show_binded_key(global, global->settings->move_keys[3],
    (sfVector3f){725, 425, 50});
    show_binded_key(global, global->settings->move_keys[1],
    (sfVector3f){725, 600, 50});
    show_binded_key(global, global->settings->move_keys[2],
    (sfVector3f){725, 775, 50});
    show_binded_key(global, global->settings->move_keys[4],
    (sfVector3f){1470, 250, 50});
    show_binded_key(global, global->settings->move_keys[5],
    (sfVector3f){1470, 425, 50});
}

void show_game_icons(global_t *global)
{
    show_text(global->window, "CONTROLS",
    (sfVector3f){830, 620, 25}, "rs/font2.TTF");
    show_text(global->window, "MUSIC",
    (sfVector3f){875, 200, 25}, "rs/font2.TTF");
    show_text(global->window, "SAVE",
    (sfVector3f){880, 815, 70}, "rs/adam.ttf");
    show_text(global->window, "<",
    (sfVector3f){640, 260, 70}, "rs/adam.ttf");
    show_text(global->window, ">",
    (sfVector3f){800, 260, 70}, "rs/adam.ttf");
    show_text(global->window, "<",
    (sfVector3f){640, 460, 70}, "rs/adam.ttf");
    show_text(global->window, ">",
    (sfVector3f){800, 460, 70}, "rs/adam.ttf");
    show_text(global->window, "SFX",
    (sfVector3f){900, 410, 25}, "rs/font2.TTF");
    show_text(global->window, "EDIT",
    (sfVector3f){905, 680, 70}, "rs/adam.ttf");
}

void show_controls_icons(global_t *global)
{
    show_text(global->window, "BIND UP",
    (sfVector3f){410, 240, 65}, "rs/adam.ttf");
    show_text(global->window, "BIND RIGHT",
    (sfVector3f){365, 415, 65}, "rs/adam.ttf");
    show_text(global->window, "BIND LEFT",
    (sfVector3f){370, 580, 65}, "rs/adam.ttf");
    show_text(global->window, "BIND DOWN",
    (sfVector3f){355, 765, 65}, "rs/adam.ttf");
    show_text(global->window, "BIND SELECT",
    (sfVector3f){1045, 240, 65}, "rs/adam.ttf");
    show_text(global->window, "BIND INTERACT",
    (sfVector3f){1020, 415, 65}, "rs/adam.ttf");
    show_text(global->window, "SAVE",
    (sfVector3f){1170, 695, 65}, "rs/adam.ttf");
    show_actual_keys(global);
}

void show_video_icons(global_t *global)
{
    char str[] = "CHANGE RESULOTION (WINDOWED MODE)";
    char str2[] = "SET VIDEO DISPLAY MODE";

    show_text(global->window, "<", (sfVector3f){490, 240, 100}, "rs/adam.ttf");
    show_text(global->window, ">", (sfVector3f){635, 240, 100}, "rs/adam.ttf");
    show_text(global->window, str, (sfVector3f){450, 200, 25}, "rs/font2.TTF");
    show_text(global->window, str2,
    (sfVector3f){625, 420, 25}, "rs/font2.TTF");
    if (!global->settings->is_fullscreen)
        show_text(global->window, "SET TO FULLSCREEN",
        (sfVector3f){670, 515, 70}, "rs/adam.ttf");
    else
        show_text(global->window, "SET TO WINDOWED",
        (sfVector3f){685, 515, 70}, "rs/adam.ttf");
    show_text(global->window, "SAVE",
    (sfVector3f){870, 775, 70}, "rs/adam.ttf");
}

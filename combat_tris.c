/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

void bars_bis(player_t *pl)
{
    char *str = my_strcat(strdup("PV : "), float_to_str(pl->stats->hp, 0), "");

    str = my_strcat(str, "/", "");
    sfText_setString(pl->bars->texts[0], my_strcat(strdup("STATUS : ")
        , pl->status, ""));
    sfText_setString(pl->bars->texts[1]
        , my_strcat(strdup("Level : "), my_number_to_str(pl->level), ""));
    str = my_strcat(str, float_to_str(pl->stats->max_hp, 0), "");
    sfText_setString(pl->bars->texts[2], str);
    str = my_strcat(strdup("PM : "), float_to_str(pl->stats->mana, 0), "");
    str = my_strcat(str, "/", "");
    str = my_strcat(str, float_to_str(pl->stats->max_mana, 0), "");
    sfText_setString(pl->bars->texts[3], str);
}

void animate_player(global_t *gl)
{
    gl->combat->time = sfClock_getElapsedTime(gl->combat->clock);
    if (gl->pl->obj->rect.left >= 1155)
        gl->pl->obj->rect.left = 0;
    if (gl->combat->time.microseconds > 150000) {
        gl->pl->obj->rect.left += 231;
        sfClock_restart(gl->combat->clock);
    }
    sfSprite_setTextureRect(gl->pl->obj->sprite, gl->pl->obj->rect);
}

void defense(global_t *global)
{
    int stored_def = global->pl->stats->def;

    if (global->selecting == 0){
        if (global->pl->stats->skip < 1) {
            global->pl->stats->def *= 2;
            global->pl->status = "GUARDING";
            sfRectangleShape_setFillColor(global->pl->bars->life[1]
                , sfColor_fromRGB(15, 158, 210));
        } else {
            global->pl->stats->skip -= 1;
        }
        enemy_turn(global);
        apply_status(global);
    }
    global->pl->stats->def = stored_def;
}

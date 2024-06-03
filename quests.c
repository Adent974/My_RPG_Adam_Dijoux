/*
** EPITECH PROJECT, 2024
** quests
** File description:
** fonctions
*/

#include "include/include.h"

void display_quest(global_t *global)
{
    sfVector2f pos = sfView_getCenter(global->view);

    if (sfKeyboard_isKeyPressed(global->settings->move_keys[0]) ||
        sfKeyboard_isKeyPressed(global->settings->move_keys[1]) ||
        sfKeyboard_isKeyPressed(global->settings->move_keys[2]) ||
        sfKeyboard_isKeyPressed(global->settings->move_keys[3]))
        global->quest->current_quest = 1;
    if (global->pnj[0]->dialogue->nb_talks >= 4
        && global->quest->current_quest == 1)
        global->quest->current_quest = 2;
    if (global->quest->current_pnj == 4 && global->quest->current_quest == 2)
        global->quest->current_quest = 3;
    if (global->quest->quest_text[global->quest->current_quest])
        show_text(global->window,
        global->quest->quest_text[global->quest->current_quest],
        (sfVector3f) {pos.x + 500, pos.y - 475, 30}, "rs/adam.ttf");
}

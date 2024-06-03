/*
** EPITECH PROJECT, 2024
** init
** File description:
** inti
*/

#include "include/include.h"

quest_t *init_quest(char *filepath)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (!quest)
        exit(84);
    quest->current_quest = 0;
    quest->quest_text = my_str_to_array(fileread(filepath), "$");
    quest->current_pnj = 0;
    quest->enemies_killed = 0;
    return quest;
}

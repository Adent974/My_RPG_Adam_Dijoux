/*
** EPITECH PROJECT, 2024
** load player
** File description:
** load player
*/

#include "include/include.h"

void get_player_info(global_t *global, char **content, int index)
{
    char *tmp = strdup(content[index]);
    char **tab = my_str_to_array(tmp, ":");

    if (strcmp(tab[0], "skill") == 0)
        global->pl->skills[atoi(tab[1])] = atoi(tab[2]);
    if (strcmp(tab[0], "enemy_killed") == 0)
        global->pl->enemy_killed = atoi(tab[1]);
    if (strcmp(tab[0], "hp") == 0)
        global->pl->stats->hp = atof(tab[1]);
    if (strcmp(tab[0], "pos") == 0)
        global->pl->pos = (sfVector2f){atof(tab[1]), atof(tab[2])};
    if (strcmp(tab[0], "max_hp") == 0)
        global->pl->stats->max_hp = atof(tab[1]);
    if (strcmp(tab[0], "max_mn") == 0)
        global->pl->stats->max_mana = atof(tab[1]);
    if (strcmp(tab[0], "mana") == 0)
        global->pl->stats->mana = atof(tab[1]);
    if (strcmp(tab[0], "defense") == 0)
        global->pl->stats->def = atof(tab[1]);
    mini_cleaner(tmp, tab);
}

void load_player(global_t *global, char **content)
{
    int i = 0;

    for (i = 0; content[i]; i++)
        if (strcmp(content[i], "##PLAYER##") == 0) {
            i++;
            break;
        }
    for (; content[i]; i++) {
        if (strcmp(content[i], "##INVENTORY##") == 0)
            break;
        get_player_info(global, content, i);
    }
}

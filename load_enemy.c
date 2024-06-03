/*
** EPITECH PROJECT, 2024
** enemy
** File description:
** enemy
*/

#include "include/include.h"

void get_enemy_info(global_t *global, char *content)
{
    char *tmp = strdup(content);
    char **tab = my_str_to_array(tmp, ":");

    global->enemies[atoi(tab[0])]->dead = atoi(tab[1]);
    mini_cleaner(tmp, tab);
}

void load_enemy(global_t *global, char **content)
{
    int i = 0;

    for (i = 0; content[i]; i++)
        if (strcmp(content[i], "##ENEMY##") == 0) {
            i++;
            break;
        }
    for (; content[i]; i++) {
        if (strcmp(content[i], "EOF") == 0)
            break;
        get_enemy_info(global, content[i]);
    }
}

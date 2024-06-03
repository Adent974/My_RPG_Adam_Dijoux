/*
** EPITECH PROJECT, 2024
** load pnj
** File description:
** load pnj
*/

#include "include/include.h"


void get_pnj_info(global_t *global, char **content, int index)
{
    char *tmp = strdup(content[index]);
    char **tab = my_str_to_array(tmp, ":");

    if (strcmp(tab[0], "#PNJ_INFO#") == 0) {
        mini_cleaner(tmp, tab);
        tmp = strdup(content[index + 1]);
        tab = my_str_to_array(tmp, ":");
        global->current_pnj = get_pnj_from_name(global, tab[1]);
        return;
    }
    if (strcmp(tab[0], "nb_talks") == 0) {
        global->current_pnj->dialogue->nb_talks = atoi(tab[1]);
    }
    mini_cleaner(tmp, tab);
}

void load_pnj(global_t *global, char **content)
{
    int i = 0;

    for (i = 0; content[i]; i++)
        if (strcmp(content[i], "##PNJ##") == 0) {
            i++;
            break;
        }
    for (; content[i]; i++) {
        if (strcmp(content[i], "##ENEMY##") == 0)
            break;
        get_pnj_info(global, content, i);
    }
}

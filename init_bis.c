/*
** EPITECH PROJECT, 2024
** init_bis
** File description:
** remaining function for init
*/
#include "include/include.h"

int get_ratio(int val, int max_val, int x)
{
    int res = val * 100 / max_val;

    res = res * x / 100;
    return res;
}

stats_t *set_pl_stat(stats_t *stats)
{
    stats->hp = 50;
    stats->mana = 50;
    stats->max_hp = 50;
    stats->max_mana = 50;
    stats->crit = 10;
    stats->dmg = 10;
    stats->def = 5;
    stats->speed = 10;
    stats->prec = 100;
    stats->esq = 10;
    stats->skip = 0;
    stats->mode = 0;
    return stats;
}

stats_t *set_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    stats->hp = 0;
    stats->mana = 0;
    stats->max_hp = 0;
    stats->max_mana = 0;
    stats->dmg = 0;
    stats->def = 0;
    stats->speed = 0;
    stats->prec = 0;
    stats->esq = 0;
    stats->skip = 0;
    stats->def_save = 0;
    stats->dmg_save = 0;
    stats->mode = 0;
    return stats;
}

void texts(global_t *global, sfText **t)
{
    char *str = my_strcat(strdup("HP : ")
        , float_to_str(global->pl->stats->hp, 0), "");

    str = my_strcat(str, "/", "");
    t[0] = create_text(my_strcat(strdup("STATUS : ")
        , global->pl->status, "")
        , "rs/adam.ttf", (sfVector2f){1500, 900}, sfBlack);
    t[1] = create_text(my_strcat(strdup("Level : ")
        , my_number_to_str(global->pl->level), "")
        , "rs/adam.ttf", (sfVector2f){1500, 1000}, sfBlack);
    str = my_strcat(str, float_to_str(global->pl->stats->max_hp, 0), "");
    t[2] = create_text(str, "rs/adam.ttf", (sfVector2f){1500, 675}, sfBlack);
    str = my_strcat(float_to_str(global->pl->stats->mana, 0), "/", "");
    t[3] = create_text(my_strcat(str
        , float_to_str(global->pl->stats->max_mana, 0), "")
        , "rs/adam.ttf", (sfVector2f){1500, 775}, sfBlack);
    t[4] = create_text(my_strcat(str
        , float_to_str(0, 0), "")
        , "rs/adam.ttf", (sfVector2f){450, 675}, sfBlack);
    t[5] = NULL;
}

sfText **status_bar(global_t *global)
{
    sfText **t = malloc(sizeof(sfText *) * 6);

    texts(global, t);
    return t;
}

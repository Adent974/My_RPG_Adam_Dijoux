/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/
#include "include/include.h"

status_t *reset_status(void)
{
    status_t *status = my_malloc(sizeof(status_t) + 1);

    status->duration = 0;
    status->type = 0;
    status->force = 0;
    return status;
}

statlist_t *init_status(statlist_t *status_list)
{
    status_list = my_malloc(sizeof(statlist_t) + 1);
    status_list->atk_boost = reset_status();
    status_list->def_boost = reset_status();
    status_list->speed_boost = reset_status();
    status_list->para = reset_status();
    status_list->stun = reset_status();
    status_list->crit_boost = reset_status();
    status_list->poison = reset_status();
    status_list->frozen = reset_status();
    status_list->burn = reset_status();
    return status_list;
}

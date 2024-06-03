/*
** EPITECH PROJECT, 2024
** roaming_pnj
** File description:
** handle the roaming of a pnj
*/

#include "include/include.h"

int get_offset(pnj_t *pnj, int way)
{
    int x = 0;
    int y = 0;

    x = (way == -1) ? (rand() % 300 - 150) + pnj->pos.x
        : ((rand() % 300 - 150) + pnj->pos.x) * -1;
    y = (way == -1) ? (rand() % 300 - 150) + pnj->pos.y
        : ((rand() % 300 - 150) + pnj->pos.y) * -1;
    pnj->offset = (sfVector2f){x / 700, y / 700};
    return 1;
}

void roam_enemy(global_t *global, pnj_t **pnj)
{
    int passed = 0;
    int is_moving = 0;
    int way = 0;

    for (int i = 0; pnj[i]; i++) {
        way = rand() % 2 - 1;
        is_moving = rand() % 2 - 1;
        pnj[i]->pos = sfSprite_getPosition(pnj[i]->pnj_obj->sprite);
        if (is_moving == -1) {
            continue;
        }
        if (sfClock_getElapsedTime(global->roam_clock)
            .microseconds > 2000000) {
            passed = get_offset(pnj[i], way);
        } else
            break;
    }
    if (passed == 1)
        sfClock_restart(global->roam_clock);
}

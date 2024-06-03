/*
** EPITECH PROJECT, 2024
** bat
** File description:
** handle all the function for an enemy in combat
*/

#include "include/include.h"

static int get_offset(enemy_t *pnj, int way)
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

void roam_pnj(global_t *global, enemy_t **pnj)
{
    int passed = 0;
    int is_moving = 0;
    int way = 0;

    for (int i = 0; pnj[i]; i++) {
        way = rand() % 2 - 1;
        is_moving = rand() % 2 - 1;
        pnj[i]->pos = sfSprite_getPosition(pnj[i]->obj->sprite);
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

static void display_enemies_bis(global_t *global, int index,
    sfFloatRect target, sfFloatRect mrect)
{
    target = sfRectangleShape_getGlobalBounds(global->enemies[index]->bounds);
    if (sfFloatRect_intersects(&mrect, &target, NULL) == sfTrue) {
        global->combat->curent_enemy = global->enemies[index];
        combat_hud(global);
        return;
    }
    roam_pnj(global, global->enemies);
    if (!global->enemies[index]->dead) {
        sfRenderWindow_drawRectangleShape(global->window,
        global->enemies[index]->bounds, NULL);
        sfRenderWindow_drawSprite(global->window,
        global->enemies[index]->obj->sprite, NULL);
    }
    sfSprite_move(global->enemies[index]->obj->sprite,
    global->enemies[index]->offset);
    sfRectangleShape_setPosition(global->enemies[index]->bounds,
    global->enemies[index]->pos);
}

void display_enemies(global_t *global)
{
    sfFloatRect mrect = sfRectangleShape_getGlobalBounds(global->pl->bounds);
    sfFloatRect tar =
    sfRectangleShape_getGlobalBounds(global->enemies[0]->bounds);

    for (int i = 0; global->enemies[i]; i++)
        display_enemies_bis(global, i, tar, mrect);
}

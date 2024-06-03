/*
** EPITECH PROJECT, 2024
** mouve
** File description:
** ment
*/

#include "include/include.h"

sfBool check_not_moving(global_t *gb)
{
    if (!sfKeyboard_isKeyPressed(gb->settings->move_keys[0]) &&
        !sfKeyboard_isKeyPressed(gb->settings->move_keys[1]) &&
        !sfKeyboard_isKeyPressed(gb->settings->move_keys[2]) &&
        !sfKeyboard_isKeyPressed(gb->settings->move_keys[3])) {
            sfSprite_setTexture(gb->pl->sprite, gb->pl->idle_texture, sfTrue);
            return sfTrue;
        }
    sfSprite_setTexture(gb->pl->sprite, gb->pl->texture, sfFalse);
    return sfFalse;
}

void anim_idle(global_t *gb)
{
    sfTime time = sfClock_getElapsedTime(gb->pl->pl_clock);
    float seconds = sfTime_asSeconds(time);
    sfVector2i max_v = {1040, 80};

    if (seconds >= 0.07) {
        if (gb->pl->rect.left >= max_v.x)
            gb->pl->rect.left = 0;
        gb->pl->rect.left += gb->pl->rect.width;
        time = sfClock_restart(gb->pl->pl_clock);
    }
}

static void anim_bis(global_t *gb, sfVector2i max_v)
{
    if (gb->pl->rect.left >= max_v.x)
        gb->pl->rect.left = 0;
    if (gb->pl->rect.left <= 0)
        gb->pl->rect.left = 0;
    if (gb->pl->rect.top >= max_v.y)
        gb->pl->rect.top = gb->pl->start_top_or;
    if (gb->pl->rect.top >= 0)
        gb->pl->rect.top = gb->pl->start_top_or;
    if (check_not_moving(gb))
        anim_idle(gb);
}

void anim(global_t *gb, sfVector2i max_v)
{
    sfTime time = sfClock_getElapsedTime(gb->pl->pl_clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds >= 0.065 && !check_not_moving(gb)) {
        time = sfClock_restart(gb->pl->pl_clock);
        if (sfKeyboard_isKeyPressed(gb->settings->move_keys[0])
        || sfKeyboard_isKeyPressed(gb->settings->move_keys[2]))
            gb->pl->rect.left += gb->pl->rect.width;
        if (sfKeyboard_isKeyPressed(gb->settings->move_keys[1])) {
            sfSprite_setScale(gb->pl->sprite, (sfVector2f) {-2.5, 2.5});
            gb->pl->rect.left += gb->pl->rect.width;
        }
        if (sfKeyboard_isKeyPressed(gb->settings->move_keys[3])) {
            sfSprite_setScale(gb->pl->sprite, (sfVector2f) {2.5, 2.5});
            gb->pl->rect.left += gb->pl->rect.width;
        }
    }
    anim_bis(gb, max_v);
}

static sfBool is_diagonale(global_t *gb)
{
    if (sfKeyboard_isKeyPressed(gb->settings->move_keys[0]) &&
        sfKeyboard_isKeyPressed(gb->settings->move_keys[1]))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(gb->settings->move_keys[2]) &&
        sfKeyboard_isKeyPressed(gb->settings->move_keys[3]))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(gb->settings->move_keys[0]) &&
        sfKeyboard_isKeyPressed(gb->settings->move_keys[3]))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(gb->settings->move_keys[1]) &&
        sfKeyboard_isKeyPressed(gb->settings->move_keys[2]))
        return sfTrue;
    return sfFalse;
}

void manage_movement(global_t *global)
{
    manage_move(global);
    if (is_diagonale(global)) {
        global->pl->pos.x += (global->pl->velocity.x *
            global->pl->stats->speed) * 0.75;
        global->pl->pos.y += (global->pl->velocity.y *
            global->pl->stats->speed) * 0.75;
    } else {
        global->pl->pos.x += global->pl->velocity.x * global->pl->stats->speed;
        global->pl->pos.y += global->pl->velocity.y * global->pl->stats->speed;
    }
}

void display_player(global_t *global)
{
    sfVector2i max_v = {1200, 80};
    sfVector2f pos = global->pl->pos;

    anim(global, max_v);
    sfSprite_setTextureRect(global->pl->sprite, global->pl->rect);
    sfSprite_setPosition(global->pl->sprite, pos);
    sfRenderWindow_drawSprite(global->window, global->pl->sprite, NULL);
    sfRectangleShape_setPosition(global->pl->bounds, global->pl->pos);
}

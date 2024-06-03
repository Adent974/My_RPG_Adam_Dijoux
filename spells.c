/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

static void spells_bis(global_t *gl, sfSprite *sprite,
    sfTexture *texture, sfIntRect rect)
{
    gl->combat->clock = sfClock_create();
    sfSprite_setPosition(sprite, sfSprite_getPosition(gl->pl->obj->sprite));
    gl->combat->time = sfClock_getElapsedTime(gl->combat->clock);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    gl->pl->stats->mana -= (gl->pl->stats->mana > 0) ? 10 : 0;
    gl->pl->stats->mana = (gl->pl->stats->mana < 0)
        ? 0 : gl->pl->stats->mana;
    sfSprite_setScale(sprite, (sfVector2f){4, 4});
}

static void spells_tris(global_t *gl, sfSprite *sprite,
    sfVector2f move, sfIntRect rect)
{
    while (rect.left < 3840) {
        gl->combat->time = sfClock_getElapsedTime(gl->combat->clock);
        sfRenderWindow_clear(gl->window, sfWhite);
        if (gl->combat->time.microseconds > 50000) {
            rect.left += 64;
            sfClock_restart(gl->combat->clock);
        }
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(gl->window, sprite, NULL);
        hud_aux(gl);
        sfSprite_move(sprite, move);
    }
}

void spells_1(global_t *gl)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f move = (sfVector2f){20, 0};
    sfTexture *t = sfTexture_createFromFile("rs/spells/spritesheet.png", NULL);
    sfIntRect rect = create_rect(0, 0, 60, 64);

    gl->pl->inv->spell_id = 0;
    gl->selecting = 0;
    if (gl->pl->stats->mana > 0 && gl->pl->inv->spells[gl->pl->inv->spell_id]){
        spells_bis(gl, sprite, t, rect);
        spells_tris(gl, sprite, move, rect);
        enemy_turn(gl);
        apply_status(gl);
    }
    gl->combat->active_spells = 0;
    sfSprite_destroy(sprite);
}

void spells_2(global_t *gl)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f move = (sfVector2f){20, 0};
    sfTexture *t = sfTexture_createFromFile("rs/spells/spritesheet.png", NULL);
    sfIntRect rect = create_rect(0, 0, 60, 64);

    gl->selecting = 0;
    gl->pl->inv->spell_id = 1;
    if (gl->pl->stats->mana > 0 && gl->pl->inv->spells[gl->pl->inv->spell_id]){
        spells_bis(gl, sprite, t, rect);
        spells_tris(gl, sprite, move, rect);
        enemy_turn(gl);
        apply_status(gl);
    }
    gl->combat->active_spells = 0;
    sfSprite_destroy(sprite);
}

void spells_3(global_t *gl)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f move = (sfVector2f){20, 0};
    sfTexture *t = sfTexture_createFromFile("rs/spells/spritesheet.png", NULL);
    sfIntRect rect = create_rect(0, 0, 60, 64);

    gl->selecting = 0;
    gl->pl->inv->spell_id = 2;
    if (gl->pl->stats->mana > 0 && gl->pl->inv->spells[gl->pl->inv->spell_id]){
        spells_bis(gl, sprite, t, rect);
        spells_tris(gl, sprite, move, rect);
        enemy_turn(gl);
        apply_status(gl);
    }
    gl->combat->active_spells = 0;
    sfSprite_destroy(sprite);
}

void spells_4(global_t *gl)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f move = (sfVector2f){20, 0};
    sfTexture *t = sfTexture_createFromFile("rs/spells/spritesheet.png", NULL);
    sfIntRect rect = create_rect(0, 0, 60, 64);

    gl->selecting = 0;
    gl->pl->inv->spell_id = 3;
    if (gl->pl->stats->mana > 0 && gl->pl->inv->spells[gl->pl->inv->spell_id]){
        spells_bis(gl, sprite, t, rect);
        spells_tris(gl, sprite, move, rect);
        enemy_turn(gl);
        apply_status(gl);
    }
    gl->combat->active_spells = 0;
    sfSprite_destroy(sprite);
}

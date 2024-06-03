/*
** EPITECH PROJECT, 2024
** combat
** File description:
** handle all the display and combat mechanics
*/

#include "include/include.h"

static void update_bars(player_t *pl, bar_t *bars, global_t *global)
{
    if (pl->stats->hp <= 10)
        sfRectangleShape_setFillColor(pl->bars->life[1], sfRed);
    if (pl->stats->mana <= 10)
        sfRectangleShape_setFillColor(pl->bars->mana[1], sfYellow);
    sfRectangleShape_setSize(bars->life[1],
        (sfVector2f){get_ratio(pl->stats->hp, pl->stats->max_hp, 375), 25});
    sfRectangleShape_setSize(bars->mana[1],
        (sfVector2f){get_ratio(pl->stats->mana
            , pl->stats->max_mana, 375), 25});
    sfText_setString(pl->bars->texts[4], global->combat->curent_enemy->name);
    bars_bis(pl);
}

void hud_aux(global_t *global)
{
    sfRenderWindow_drawRectangleShape(global->window
        , global->pl->bars->inter, NULL);
    for (int i = 0; global->pl->bars->life[i]; i++) {
        sfRenderWindow_drawRectangleShape(global->window
            , global->pl->bars->life[i], NULL);
        sfRenderWindow_drawRectangleShape(global->window
            , global->pl->bars->mana[i], NULL);
    }
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText(global->window
            , global->pl->bars->texts[i], NULL);
    enemy_disp(global);
    sfRenderWindow_display(global->window);
}

static void combat_loop(global_t *global)
{
    while (global->combat->curent_enemy->dead != 1 &&
        global->pl->stats->hp != 0 && sfRenderWindow_isOpen(global->window)) {
        manage_input_events(global);
        sfRenderWindow_clear(global->window, sfWhite);
        sfRenderWindow_drawSprite(global->window
            , global->combat->background->sprite, NULL);
        update_bars(global->pl, global->pl->bars, global);
        for (int i = 0; global->combat->interface[i]; i++){
            sfRenderWindow_drawRectangleShape(global->window,
                global->combat->interface[i], NULL);
        }
        manage_buttons(global, global->combat->button);
        animate_player(global);
        disp_actions(global, global->combat);
        hud_aux(global);
        global->settings->mouse_pressed = 0;
        mouse(global);
        if (global->exit_program)
            exit(0);
    }
}

void combat_hud(global_t *global)
{
    manage_view(global);
    transition(global);
    transition2(global);
    sfView_setCenter(global->view, global->combat->combat_view);
    sfRenderWindow_setView(global->window, global->view);
    global->combat->clock = sfClock_create();
    global->pl->stats->dmg_save = global->pl->stats->dmg;
    global->pl->stats->def_save = global->pl->stats->def;
    global->combat->curent_enemy->stats->dmg_save =
        global->combat->curent_enemy->stats->dmg;
    global->combat->curent_enemy->stats->def_save =
        global->combat->curent_enemy->stats->def;
    if (global->pl->inv->armor != NULL)
        global->pl->stats->def += global->pl->inv->armor->def;
    combat_loop(global);
    xp_up(global);
    global->pl->stats->dmg = global->pl->stats->dmg_save;
    global->pl->stats->def = global->pl->stats->def_save;
}

void attack_r(global_t *gl)
{
    if (gl->pl->inv->ranger != NULL)
        gl->pl->inv->weapon = 2;
    else
        return;
    gl->selecting = 0;
    if (gl->pl->stats->skip < 1){
        launch_attack(gl, gl->pl->stats, gl->combat->curent_enemy->stats);
        use_all_eq(gl);
        if (gl->combat->curent_enemy->stats->hp <= 0.0)
            gl->combat->curent_enemy->dead = 1;
    } else {
        gl->pl->stats->skip -= 1;
    }
    enemy_turn(gl);
    apply_status(gl);
    gl->combat->active_attack = 0;
}

void attack_s(global_t *gl)
{
    if (gl->pl->inv->slasher != NULL){
        gl->pl->inv->weapon = 1;
    } else
        return;
    gl->selecting = 0;
    if (gl->pl->stats->skip < 1){
        launch_attack(gl, gl->pl->stats, gl->combat->curent_enemy->stats);
        use_all_eq(gl);
        if (gl->combat->curent_enemy->stats->hp <= 0.0)
            gl->combat->curent_enemy->dead = 1;
    } else {
        gl->pl->stats->skip -= 1;
    }
    enemy_turn(gl);
    apply_status(gl);
    gl->combat->active_attack = 0;
}

void attack(global_t *gl)
{
    if (gl->pl->inv->stunner != NULL)
        gl->pl->inv->weapon = 0;
    else
        return;
    gl->selecting = 0;
    if (gl->pl->stats->skip < 1){
        launch_attack(gl, gl->pl->stats, gl->combat->curent_enemy->stats);
        use_all_eq(gl);
        if (gl->combat->curent_enemy->stats->hp <= 0.0)
            gl->combat->curent_enemy->dead = 1;
    } else {
        gl->pl->stats->skip -= 1;
    }
    enemy_turn(gl);
    apply_status(gl);
    gl->combat->active_attack = 0;
}

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

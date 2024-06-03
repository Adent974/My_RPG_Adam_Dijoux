/*
** EPITECH PROJECT, 2024
** loop
** File description:
** loop
*/

#include "include/include.h"

int dialogue_loop(global_t *global)
{
    if (global->dialogue_active == 1) {
        if (global->dialogue->nb_talks >= global->dialogue->nb_talks_max)
            global->dialogue->nb_talks = global->dialogue->nb_talks_max;
        dialogue(global, global->dialogue);
        display_dialogue(global);
        return 1;
    }
    return 0;
}

static void animation_loop(global_t *global, sfVector2f max)
{
    global->animation->cur_size.y += max.y / 10;
    if (global->animation->cur_size.x == max.x) {
        global->animation->is_active = 0;
        global->animation->cur_size = (sfVector2i){0, 0};
    }
    if (global->animation->cur_size.y == max.y) {
        global->animation->cur_size.y = max.y - (max.y / 10);
        global->animation->cur_size.x += max.x / 10;
    }
}

void manage_animation(global_t *global, sfVector2f max, sfVector2f pos)
{
    sfTime time = sfClock_getElapsedTime(global->animation->clock);
    sfVector3f size = {global->animation->cur_size.x,
    global->animation->cur_size.y, 2};

    if (time.microseconds >= 10000)
        animation_loop(global, max);
    show_rect(global->window, (sfVector2f){pos.x - (size.x / 2),
    pos.y - (size.y / 2)}, (sfColor[2]){sfWhite, sfBlack}, size);
}

void display_map_and_player(global_t *global)
{
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(global->window,
        global->map_sprites[i], NULL);
    sfRenderWindow_drawSprite(global->window, global->map_sprites[9], NULL);
    display_player(global);
    for (int i = 7; i < 9; i++)
        sfRenderWindow_drawSprite(global->window,
        global->map_sprites[i], NULL);
}

void game_loop_bis(global_t *global)
{
    sfVector2f wincenter;

    manage_view(global);
    wincenter = sfView_getCenter(global->view);
    display_map_and_player(global);
    manage_pnj(global);
    display_enemies(global);
    display_quest(global);
    if (global->animation->is_active == 1) {
        manage_animation(global, (sfVector2f){1800, 160},
        (sfVector2f){wincenter.x, wincenter.y + 275});
        return;
    }
    if (dialogue_loop(global)) {
        return;
    }
    manage_movement(global);
}

static int no_transition_gameloop(global_t *global)
{
    if (!global->state_game) {
        display_main_menu(global);
        return 1;
    }
    if (global->save_ui_state != -1) {
        save_ui(global);
        return 1;
    }
    if (global->settings->settings_active) {
        inventory_ui(global);
        return 1;
    }
    game_loop_bis(global);
    return 0;
}

void game_loop(global_t *global)
{
    manage_window_size(global);
    sfRenderWindow_clear(global->window, sfWhite);
    if (global->transition_status == -1 || !global->animation->is_active)
        manage_input_events(global);
    if (global->exit_program == 1)
        return;
    if (global->transition_status == -1 || global->transition_status == 0 ||
    global->transition_status == 3) {
        if (no_transition_gameloop(global) == 1)
            return;
    }
    start_transition(global, global->transition_clock);
}

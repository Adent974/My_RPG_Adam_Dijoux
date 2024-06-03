/*
** EPITECH PROJECT, 2024
** transition
** File description:
** transition
*/

#include "include/include.h"

void manage_transition_start(global_t *global, sfClock *clock, sfVector2f pos)
{
    if (global->transition_status % 2 == 0) {
        if (global->transition_status == 2)
            display_bg_load(global);
        sfRenderWindow_drawSprite(global->window,
        global->trans_sp[0], NULL);
        pos = sfSprite_getPosition(global->trans_sp[0]);
        pos.x -= 50;
        if (pos.x <= -650) {
            global->transition_status += 1;
            sfSprite_setPosition(global->trans_sp[1], (sfVector2f){0, 0});
            pos.x = 1920;
            sfClock_restart(clock);
        }
        sfSprite_setPosition(global->trans_sp[0], pos);
    }
}

void manage_transition_end(global_t *global, sfClock *clock, sfVector2f pos)
{
    global->save_ui_state = -1;
    global->settings->settings_active = 0;
    if (global->transition_status == 1)
        display_bg_load(global);
    sfRenderWindow_drawSprite(global->window, global->trans_sp[1], NULL);
    pos = sfSprite_getPosition(global->trans_sp[1]);
    pos.x -= 50;
    if (pos.x <= -4100 && global->transition_status == 1)
        pos.x = -4100;
    if (pos.x <= -4100 && global->transition_status == 3) {
        pos.x = -4100;
        global->transition_status = -1;
        sfSprite_setScale(global->pl->sprite, (sfVector2f){2.5, 2.5});
    }
    sfSprite_setPosition(global->trans_sp[1], pos);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 4 &&
    global->transition_status == 1) {
        global->transition_status = 2;
        sfSprite_setPosition(global->trans_sp[0], (sfVector2f){1920, 0});
    }
}

void start_transition(global_t *global, sfClock *clock)
{
    sfVector2f pos = sfSprite_getPosition(global->trans_sp[0]);

    sfView_setCenter(global->view, (sfVector2f){1920 / 2, 1080 / 2});
    sfRenderWindow_setView(global->window, global->view);
    if (global->transition_status == -1)
        return;
    if (global->transition_status % 2 == 0)
        manage_transition_start(global, clock, pos);
    if (global->transition_status % 2 == 1)
        manage_transition_end(global, clock, pos);
}

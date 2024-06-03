/*
** EPITECH PROJECT, 2024
** events
** File description:
** events
*/

#include "include/include.h"

static void manage_key_bis(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad0))
        global->save_ui_state = 0;
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[7])) {
        global->settings->settings_active = 1;
        global->inventory_state = 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNumpad9)) {
        global->node_status += 1;
        global->node_status %= 2;
    }
}

void manage_key(global_t *global)
{
    int index = global->settings->selected_button_index;

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (!global->settings->settings_active)
            global->inventory_state = 3;
        else
            sfSprite_setScale(global->pl->sprite, (sfVector2f) {2.5, 2.5});
        global->settings->settings_active += 1;
        global->settings->settings_active %= 2;
        global->settings->settings_index = 0;
        global->settings->selected_button_index = 0;
    }
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[4]))
        if (global->settings->settings_active)
            global->settings->settings_buttons[index]->func(global);
    if (sfKeyboard_isKeyPressed(sfKeyBackspace))
        open_inv(global);
    manage_key_bis(global);
}

void manage_mouse(global_t *global, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        global->settings->mouse_pressed = 1;
        global->settings->mouse_hold = 1;
    } else
        global->settings->mouse_pressed = 0;
    if (event.type == sfEvtMouseButtonReleased) {
        global->settings->mouse_released = 1;
        global->settings->mouse_hold = 0;
    } else
        global->settings->mouse_released = 0;
}

static int is_lateral_free(global_t *global, int dir, sfVector2i pos,
    sfVector2f new_pos)
{
    if (dir == 1) {
        new_pos.x -= 30;
        pos = get_matrix_index_from_pos(new_pos);
        if (global->map[pos.y][pos.x] != -1)
            return 0;
    }
    if (dir == 3) {
        new_pos.x += 30;
        pos = get_matrix_index_from_pos(new_pos);
        if (global->map[pos.y][pos.x] != -1)
            return 0;
    }
    return 1;
}

static int is_vertical_free(global_t *global, int dir, sfVector2i pos,
    sfVector2f new_pos)
{
    if (dir == 0) {
        new_pos.y -= 40;
        pos = get_matrix_index_from_pos(new_pos);
        if (global->map[pos.y][pos.x] != -1)
            return 0;
    }
    if (dir == 2) {
        new_pos.y += 50;
        pos = get_matrix_index_from_pos(new_pos);
        if (global->map[pos.y][pos.x] != -1)
            return 0;
    }
    return 1;
}

int is_free(global_t *global, int dir)
{
    sfVector2f player_pos = global->pl->pos;
    sfVector2f new_pos = player_pos;
    sfVector2i pos;

    if (!is_lateral_free(global, dir, pos, new_pos))
        return 0;
    if (!is_vertical_free(global, dir, pos, new_pos))
        return 0;
    return 1;
}

void manage_move(global_t *global)
{
    global->pl->velocity = (sfVector2f){0, 0};
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[0])) {
        if (is_free(global, 0))
            global->pl->velocity.y -= 1.0;
    }
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[1])) {
        if (is_free(global, 1))
            global->pl->velocity.x -= 1.0;
        global->settings->selected_button_index -= 1;
    }
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[2])) {
        if (is_free(global, 2))
            global->pl->velocity.y += 1.0;
    }
    if (sfKeyboard_isKeyPressed(global->settings->move_keys[3])) {
        if (is_free(global, 3))
            global->pl->velocity.x += 1.0;
        global->settings->selected_button_index += 1;
    }
}

void manage_input_events(global_t *global)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(global->window, &event)) {
        if (event.type == sfEvtClosed) {
            global->exit_program = 1;
            return;
        }
        manage_mouse(global, event);
        if (event.type == sfEvtKeyPressed)
            manage_key(global);
    }
}

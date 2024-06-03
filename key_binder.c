/*
** EPITECH PROJECT, 2024
** key bind
** File description:
** key bind
*/

#include "include/include.h"

int check_in_use(global_t *global, int new_key)
{
    for (int i = 0; i < 8; i++) {
        if (global->settings->move_keys[i] == new_key)
            return 1;
    }
    if (new_key == sfKeyNumpad0 || new_key == sfKeyEscape)
        return 1;
    return 0;
}

int key_binder(global_t *global, int index)
{
    for (int i = 0; i < 101; i++) {
        if (!sfKeyboard_isKeyPressed(i))
            continue;
        if (!check_in_use(global, i)) {
            global->settings->move_keys[index] = i;
            return 0;
        }
        return 1;
    }
    return 1;
}

void disp_controls_icon(global_t *global, int key_in_use)
{
    if (key_in_use)
        display_text(global, (sfVector2f){565, 550},
        30, "* KEY ALREADY IN USE *");
    display_text(global, (sfVector2f){485, 400}, 60, "* ENTER KEY *");
}

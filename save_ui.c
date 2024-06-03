/*
** EPITECH PROJECT, 2024
** save ui
** File description:
** save ui
*/

#include "include/include.h"

void display_glow(global_t *global, sfVector2f size, sfVector2f pos)
{
    sfVector2f scale = {size.x / 950.0f, size.y / 950.0f};
    sfVector2f fpos = {pos.x - (25 * scale.x),
    pos.y - (25 * scale.y)};

    show_sprite(global->window, "rs/Glow.png", fpos, scale);
}

void save_button_behavior(global_t *global, button_t *button)
{
    sfRectangleShape_setOutlineColor(button->rect,
    sfColor_fromRGB(150, 150, 150));
    sfRectangleShape_setFillColor(button->rect,
    sfColor_fromRGBA(0, 0, 0, 200));
    if (mouse_in_rect(global, button->rect))
        if (global->settings->mouse_pressed) {
            sfRectangleShape_setFillColor(button->rect,
            sfColor_fromRGBA(255, 255, 255, 150));
            button->func(global);
        }
}

static void manage_ui_bt_state1(global_t *global,
    button_t **buttons, int state)
{
    sfText *text = global->save_ui_text;

    for (int i = 3; i < 7 && state == 1; i++) {
        save_button_behavior(global, buttons[i]);
        sfRenderWindow_drawRectangleShape(global->window,
        buttons[i]->rect, NULL);
        if (mouse_in_rect(global, buttons[i]->rect))
            display_glow(global, (sfVector2f){buttons[i]->size.x,
            buttons[i]->size.y},
            (sfVector2f){buttons[i]->pos.x, buttons[i]->pos.y});
        display_save_ui_save(global, text);
    }
}

void manage_ui_buttons_bis(global_t *global, button_t **buttons, int state)
{
    sfText *text = global->save_ui_text;

    manage_ui_bt_state1(global, buttons, state);
    for (int i = 7; i < 14 && state == 2; i++) {
        save_button_behavior(global, buttons[i]);
        sfRenderWindow_drawRectangleShape(global->window,
        buttons[i]->rect, NULL);
        if (mouse_in_rect(global, buttons[i]->rect))
            display_glow(global, (sfVector2f){buttons[i]->size.x,
            buttons[i]->size.y},
            (sfVector2f){buttons[i]->pos.x, buttons[i]->pos.y});
        display_save_ui_load(global, text);
    }
}

void manage_ui_buttons(global_t *global, button_t **buttons, int state)
{
    sfText *text = global->save_ui_text;

    for (int i = 0; i < 3 && state == 0; i++) {
        save_button_behavior(global, buttons[i]);
        sfRenderWindow_drawRectangleShape(global->window,
        buttons[i]->rect, NULL);
        if (mouse_in_rect(global, buttons[i]->rect))
            display_glow(global, (sfVector2f){buttons[i]->size.x,
            buttons[i]->size.y},
            (sfVector2f){buttons[i]->pos.x, buttons[i]->pos.y});
        display_save_ui_menu(global, text);
    }
    manage_ui_buttons_bis(global, buttons, state);
}

void save_ui(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    show_sprite(global->window, "rs/Save_Menu_bg.png", (sfVector2f){0, 0},
    (sfVector2f){1.5, 1.5});
    manage_ui_buttons(global, global->save_ui_buttons,
    global->save_ui_state);
    start_transition(global, global->transition_clock);
}

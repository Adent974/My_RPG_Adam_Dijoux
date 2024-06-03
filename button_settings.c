/*
** EPITECH PROJECT, 2024
** buttons
** File description:
** buttons
*/

#include "include/include.h"

static void set_transparent(button_t **buttons)
{
    for (int i = 0; buttons[i]; i++)
        sfRectangleShape_setFillColor(buttons[i]->rect, sfTransparent);
}

static void draw_text(global_t *global, sfColor color
    , int index, sfFont *font)
{
    sfVector2f pos = {global->menu->menu_buttons[index]->pos.x
        , global->menu->menu_buttons[index]->pos.y + 30};

    sfText_setFont(global->button_text, font);
    sfText_setCharacterSize(global->button_text, 70);
    sfText_setPosition(global->button_text, pos);
    sfText_setColor(global->button_text, color);
    sfText_setString(global->button_text,
    global->menu->menu_buttons[index]->button_name);
    sfRenderWindow_drawText(global->window, global->button_text, NULL);
}

void settings_button_behavior(global_t *global, button_t **buttons, int index)
{
    sfSprite_setColor(buttons[index]->sprite, sfColor_fromRGB(180, 180, 100));
    if (mouse_in_rect(global, buttons[index]->rect))
        if (global->settings->mouse_pressed) {
            sfSprite_setColor(buttons[index]->sprite, sfWhite);
            buttons[index]->func(global);
            return;
        }
    if (mouse_in_rect(global, buttons[index]->rect))
        sfSprite_setColor(buttons[index]->sprite,
        sfColor_fromRGB(215, 215, 150));
}

void settings_button_behavior_bis(global_t *global
    , button_t **buttons, int index)
{
    set_transparent(buttons);
    if (mouse_in_rect(global, buttons[index]->rect)) {
        draw_text(global, sfWhite, index, global->startup_font);
        if (global->settings->mouse_pressed) {
            sfSprite_setColor(buttons[index]->sprite, sfWhite);
            buttons[index]->func(global);
            return;
        }
    } else {
        draw_text(global, sfBlack, index, global->startup_font);
    }
    if (mouse_in_rect(global, buttons[index]->rect)) {
        sfSprite_setColor(buttons[index]->sprite,
        sfColor_fromRGB(215, 215, 150));
    }
}

void manage_settings_buttons(global_t *global, button_t **buttons)
{
    if (global->settings->settings_index == 0) {
        for (int i = 4; i < 8; i++)
            settings_button_behavior(global, buttons, i);
    }
    if (global->settings->settings_index == 1) {
        for (int i = 0; i < 4; i++)
            settings_button_behavior(global, buttons, i);
        return;
    }
    if (global->settings->settings_index == 3) {
        for (int i = 8; i < 15; i++)
            settings_button_behavior(global, buttons, i);
        return;
    }
    if (global->settings->settings_index == 2) {
        for (int i = 15; i < 23; i++)
            settings_button_behavior(global, buttons, i);
        return;
    }
}

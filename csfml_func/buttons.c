/*
** EPITECH PROJECT, 2024
** buttons
** File description:
** buttons
*/

#include "../include/include.h"

button_t *create_button(sfVector2i pos, sfVector2i size,
    void(*func)(global_t *), char *name)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = pos;
    button->size = size;
    button->func = func;
    button->rect = create_rectangle((sfVector2f){pos.x, pos.y},
    (sfVector2f){size.x, size.y}, sfColor_fromRGB(100, 100, 100));
    sfRectangleShape_setOutlineColor(button->rect, sfTransparent);
    button->button_name = strdup(name);
    button->text = create_text(button->button_name, "rs/adam.ttf"
        , (sfVector2f){pos.x + size.x / 3 - 10, pos.y + size.y / 3}, sfBlack);
    return button;
}

int button_behavior(global_t *global, button_t **buttons, int index)
{
    sfRectangleShape_setFillColor(buttons[index]->rect,
    sfTransparent);
    if (mouse_in_rect(global, buttons[index]->rect))
        if (global->settings->mouse_pressed) {
            sfRectangleShape_setFillColor(buttons[index]->rect,
            sfColor_fromRGB(50, 50, 50));
            buttons[index]->func(global);
            return 1;
        }
    if (mouse_in_rect(global, buttons[index]->rect))
        sfRectangleShape_setFillColor(buttons[index]->rect,
        sfColor_fromRGB(200, 200, 200));
}

int manage_buttons(global_t *global, button_t **buttons)
{
    int action = 0;

    for (int i = 0; buttons[i]; i++) {
        action = (action != 1) ? button_behavior(global, buttons, i) : action;
        sfRenderWindow_drawRectangleShape(global->window,
        buttons[i]->rect, NULL);
        sfRenderWindow_drawText(global->window, buttons[i]->text, NULL);
    }
    return action;
}

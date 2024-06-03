/*
** EPITECH PROJECT, 2024
** init_actions
** File description:
** initialize all the actions for the combat
*/
#include "include/include.h"

static void change_description(global_t *g, int index)
{
    for (int i = 0; i != 8; i++) {
        sfText_setString(g->combat->quantity[i], strcat(strdup("x")
            , my_number_to_str(g->pl->inv->items[i]->quantity)));
    }
    if (!g->pl->inv->items[index]->name)
        sfText_setString(g->combat->description[0], strdup("EMPTY"));
    else
        sfText_setString(g->combat->description[0]
            , g->pl->inv->items[index]->name);
    if (!g->pl->inv->items[index]->desc)
        sfText_setString(g->combat->description[1], "/--------------\\");
    else
        sfText_setString(g->combat->description[1]
            , g->pl->inv->items[index]->desc);
    if (!g->pl->inv->items[index]->type)
        sfText_setString(g->combat->description[2], "N/A");
    else
        sfText_setString(g->combat->description[2], strcat(strdup
            (g->pl->inv->items[index]->type)
                , my_number_to_str(g->pl->inv->items[index]->dmg)));
}

int button_behavior_spe(global_t *global, button_t **buttons, int index)
{
    sfRectangleShape_setFillColor(buttons[index]->rect,
    sfTransparent);
    if (mouse_in_rect(global, buttons[index]->rect))
        change_description(global, index);
        if (global->settings->mouse_pressed) {
            sfRectangleShape_setFillColor(buttons[index]->rect,
            sfColor_fromRGB(50, 50, 50));
            global->combat->index = index;
            buttons[index]->func(global);
            return 1;
        }
    if (mouse_in_rect(global, buttons[index]->rect))
        sfRectangleShape_setFillColor(buttons[index]->rect,
        sfColor_fromRGB(200, 200, 200));
}

int manage_buttons_spe(global_t *global, button_t **buttons)
{
    int action = 0;

    for (int i = 0; buttons[i]; i++) {
        action = (action != 1) ?
            button_behavior_spe(global, buttons, i) : action;
        sfRenderWindow_drawRectangleShape(global->window,
        buttons[i]->rect, NULL);
        sfRenderWindow_drawText(global->window, buttons[i]->text, NULL);
    }
    return action;
}

static void disp_inventory(global_t *global)
{
    if (global->combat->active_inventory == 1) {
        for (int i = 0; global->combat->description[i]; i++)
            sfRenderWindow_drawText(global->window
                , global->combat->description[i], NULL);
        manage_buttons_spe(global, global->combat->inv_cases);
        for (int i = 0; global->combat->inv_cases[i]; i++) {
            sfRenderWindow_drawText(global->window
                , global->combat->quantity[i], NULL);
        }
    }
}

void disp_actions(global_t *gl, combat_t *combat)
{
    if (gl->combat->active_attack == 1) {
        sfRenderWindow_drawRectangleShape(gl->window, gl->combat->interface[1],
            sfFalse);
        manage_buttons(gl, combat->action->attacks);
    }
    if (combat->active_spells == 1) {
        sfRenderWindow_drawRectangleShape(gl->window, gl->combat->interface[1],
            sfFalse);
        manage_buttons(gl, combat->action->spell);
    }
    disp_inventory(gl);
}

static void action_bis(action_t *t)
{
    t->spell[2] = create_button((sfVector2i){50, 860}, (sfVector2i){300, 100}
        , &spells_3, "Sort 3");
    t->spell[3] = create_button((sfVector2i){50, 960}, (sfVector2i){300, 100}
        , &spells_4, "Sort 4");
    t->spell[4] = NULL;
}

action_t *init_action(global_t *global)
{
    action_t *t = malloc(sizeof(action_t) + 1);

    t->attacks = malloc(sizeof(action_t *) * 4);
    t->spell = malloc(sizeof(button_t *) * 5);
    t->attacks[0] = create_button((sfVector2i){50, 660}, (sfVector2i){300, 100}
        , &attack_s, "Slash");
    t->attacks[1] = create_button((sfVector2i){50, 760}, (sfVector2i){300, 100}
        , &attack, "Stun");
    t->attacks[2] = create_button((sfVector2i){50, 860}, (sfVector2i){300, 100}
        , &attack_r, "Range");
    t->attacks[3] = NULL;
    t->spell[0] = create_button((sfVector2i){50, 660}, (sfVector2i){300, 100}
        , &spells_1, "Sort 1");
    t->spell[1] = create_button((sfVector2i){50, 760}, (sfVector2i){300, 100}
        , &spells_2, "Sort 2");
    action_bis(t);
    return t;
}

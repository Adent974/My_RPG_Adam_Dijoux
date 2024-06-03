/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/
#include "include/include.h"

void init_combat_bis(global_t *global, combat_t *c)
{
    c->action = init_action(global);
    c->interface = malloc(sizeof(sfRectangleShape *) * 4);
    c->interface[0] = create_rectangle((sfVector2f){50, 660},
        (sfVector2f){300, 400}, sfWhite);
    c->interface[1] = create_rectangle((sfVector2f){50, 660},
        (sfVector2f){300, 400}, sfWhite);
    c->interface[2] = create_rectangle((sfVector2f){400, 660},
        (sfVector2f){950, 400}, sfWhite);
    c->interface[3] = NULL;
    c->active_attack = 0;
    c->active_spells = 0;
    c->curent_enemy = global->enemies[0];
    c->active_inventory = 0;
    c->trans = init_transition();
}

combat_t *init_combat(global_t *global)
{
    combat_t *c = malloc(sizeof(combat_t) + 1);

    c->button = malloc(sizeof(button_t *) * 5);
    c->button[0] = create_button((sfVector2i){50, 660}, (sfVector2i){300, 100}
        , &display_attack, "ATTACKS");
    c->button[1] = create_button((sfVector2i){50, 760}, (sfVector2i){300, 100}
        , &defense, "GUARD");
    c->button[2] = create_button((sfVector2i){50, 860}, (sfVector2i){300, 100}
        , &display_spells, "SPELLS");
    c->button[3] = create_button((sfVector2i){50, 960}, (sfVector2i){300, 100}
        , &display_inventory, "INVENTORY");
    c->button[4] = NULL;
    init_combat_bis(global, c);
    c->background = create_object("rs/background.jpg", (sfVector2f){3.5, 2}
        , (sfVector2f){-30, -120}, (sfIntRect){0, 0, 816, 624});
    init_combat_inventory(global, c);
    return c;
}

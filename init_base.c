/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

static void init_mouse(global_t *global)
{
    global->mouse_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(global->mouse_rect, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(global->mouse_rect, sfWhite);
    sfRectangleShape_setOrigin(global->mouse_rect, (sfVector2f){10, 10});
}

void init_save_ui(global_t *global)
{
    global->save_bt_sp = sfSprite_create();
    global->save_bt_tx = sfTexture_createFromFile("rs/save_ui_bt.png", NULL);
    sfTexture_setSmooth(global->save_bt_tx, sfFalse);
    sfSprite_setTexture(global->save_bt_sp, global->save_bt_tx, sfFalse);
    sfSprite_setScale(global->save_bt_sp, (sfVector2f){1, 1});
    global->transition_clock = sfClock_create();
    global->transition_status = -1;
    global->save_ui_text = create_text("LOAD", "rs/regular.ttf",
    (sfVector2f){150, 150}, sfWhite);
}

void init_rpg(global_t *global)
{
    init_global(global);
    init_mouse(global);
    global->node_status = 0;
    global->pl->nb_skill_pts = 1;
    global->node_link = sfRectangleShape_create();
    global->skill_nodes = init_nodes();
    sfRectangleShape_setFillColor(global->node_link, sfRed);
    global->button_text = sfText_create();
    init_map_bg(global);
    init_save_ui(global);
}

void init_skill_tree(global_t *global)
{
    global->skill_sp = sfSprite_create();
    global->skill_text = sfText_create();
    global->skill_tx = sfTexture_createFromFile("rs/skill_icon.png", NULL);
    sfSprite_setOrigin(global->skill_sp, (sfVector2f){256, 256});
    sfSprite_setScale(global->skill_sp, (sfVector2f){0.08, 0.08});
    sfSprite_setTexture(global->skill_sp, global->skill_tx, sfFalse);
    sfText_setCharacterSize(global->skill_text, 50);
    sfText_setFont(global->skill_text, global->regular_font);
    sfText_setPosition(global->skill_text, (sfVector2f){350, 770});
    sfText_setString(global->skill_text, "Choose a skill.");
}

void init_inventory_ui(global_t *global)
{
    global->regular_font = sfFont_createFromFile("rs/regular.ttf");
    global->startup_font = sfFont_createFromFile("rs/startup.ttf");
    global->karma_font = sfFont_createFromFile("rs/KarmaFuture.ttf");
    global->inventory_text = sfText_create();
    sfText_setCharacterSize(global->inventory_text, 50);
    sfText_setFont(global->inventory_text, global->startup_font);
    sfText_setPosition(global->inventory_text, (sfVector2f){350, 770});
    sfText_setString(global->inventory_text, "tmp");
}

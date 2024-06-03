/*
** EPITECH PROJECT, 2024
** combat inventory
** File description:
** handle the display and use of the combat inventory
*/
#include "include/include.h"

void use_item(global_t *global)
{
    use(global, global->pl->inv->items[global->combat->index], NULL);
    apply_status(global);
    enemy_turn(global);
    global->combat->active_inventory = 0;
    global->selecting = 0;
}

void init_description_inventory(global_t *global_s, combat_t *combat)
{
    combat->description = malloc(sizeof(sfText *) * 4);
    combat->description[0] = create_text("Select an item", "rs/adam.ttf"
        , (sfVector2f){1100, 700}, sfBlack);
    combat->description[1] = create_text("/--------\\", "rs/adam.ttf"
        , (sfVector2f){1100, 800}, sfBlack);
    combat->description[2] = create_text("Soin : 0", "rs/adam.ttf"
        , (sfVector2f){1100, 750}, sfBlack);
    combat->description[3] = NULL;
}

static void change_pos(int *x, int *y, int i)
{
    *x += 150;
    if (i == 3) {
        *x = 400;
        *y += 200;
    }
}

void init_combat_inventory(global_t *global, combat_t *combat)
{
    sfVector2i pos = (sfVector2i){400, 660};

    combat->inv_cases = malloc(sizeof(button_t *) * 9);
    combat->quantity = malloc(sizeof(sfText *) * 9);
    init_description_inventory(global, combat);
    for (int i = 0; i != 8; i++) {
        combat->inv_cases[i] = create_button(pos, (sfVector2i){150, 200}
            , &use_item, " ");
        sfRectangleShape_setOutlineColor(combat->inv_cases[i]->rect, sfBlack);
        combat->quantity[i] =
        create_text(my_strcat(strdup("x"),
            my_number_to_str(global->pl->inv->items[i]->quantity), "")
                , "rs/adam.ttf", (sfVector2f){pos.x + 120, pos.y + 165}
                    , sfBlack);
        change_pos(&pos.x, &pos.y, i);
    }
    combat->inv_cases[8] = NULL;
    combat->quantity[8] = NULL;
}

/*
** EPITECH PROJECT, 2024
** main
** File description:
** menu
*/

#include "include/include.h"

void set_menu_sprite(menu_t *menu, button_t **buttons)
{
    menu->obj = create_object("rs/menu.jpg", (sfVector2f){3, 3}
        , (sfVector2f){0, 0}, (sfIntRect){0, 0, 640, 400});
    menu->name = my_malloc(sizeof(object_t *) * 3);
    menu->name[0] = create_object("rs/quest.png", (sfVector2f){1.2, 1.2}
        , (sfVector2f){700, 50}, (sfIntRect){0, 0, 1024, 304});
    menu->name[1] = create_object("rs/gold.png", (sfVector2f){0.8, 0.8}
        , (sfVector2f){870, 320}, (sfIntRect){0, 0, 1024, 288});
    menu->name[2] = NULL;
    for (int i = 0; menu->menu_buttons[i]; i += 1) {
        menu->menu_buttons[i]->sprite = sfSprite_create();
        menu->menu_buttons[i]->texture =
        sfTexture_createFromFile("rs/button_settings.png", NULL);
        sfSprite_setScale(menu->menu_buttons[i]->sprite,
        (sfVector2f){buttons[i]->size.x / 128.0, buttons[i]->size.y / 72.0});
        sfSprite_setTexture(menu->menu_buttons[i]->sprite,
        menu->menu_buttons[i]->texture, sfFalse);
        sfSprite_setPosition(menu->menu_buttons[i]->sprite,
        (sfVector2f){buttons[i]->pos.x, buttons[i]->pos.y});
    }
}

static void show_menu_buttons(global_t *global)
{
    sfRenderWindow_drawSprite(global->window, global->menu->obj->sprite, NULL);
    for (int i = 0; global->menu->name[i]; i++) {
        sfRenderWindow_drawSprite(global->window,
            global->menu->name[i]->sprite, NULL);
    }
    for (int i = 0; global->menu->menu_buttons[i]; i++) {
        settings_button_behavior_bis(global, global->menu->menu_buttons, i);
    }
}

static void play_game(global_t *global)
{
    global->state_game = sfTrue;
    global->settings->settings_active = 0;
    sfSprite_setScale(global->pl->sprite, (sfVector2f){2.5, 2.5});
}

static void quit_game(global_t *global)
{
    global->exit_program = 1;
}

static void call_settings(global_t *global)
{
    global->state_game = 1;
    global->settings->settings_active = 1;
    global->settings_state = 0;
    global->inventory_state = 2;
}

button_t **init_main_menu_buttons(void)
{
    button_t **buttons = my_malloc(sizeof(button_t *) * 4);

    buttons[0] = create_button((sfVector2i){100, 500}, (sfVector2i){700, 125},
    &play_game, "PLAY");
    buttons[1] = create_button((sfVector2i){100, 700}, (sfVector2i){700, 125},
    &call_settings, "SETTINGS");
    buttons[2] = create_button((sfVector2i){100, 900}, (sfVector2i){700, 125},
    &quit_game, "QUIT GAME");
    buttons[3] = NULL;
    return buttons;
}

void display_main_menu(global_t *global)
{
    sfView_setCenter(global->view, (sfVector2f){1920 / 2, 1080 / 2});
    sfRenderWindow_setView(global->window, global->view);
    sfRenderWindow_clear(global->window, sfBlack);
    show_sprite(global->window, "rs/settings_bg.png",
    (sfVector2f){160, 50}, (sfVector2f){12.5, 245.0 / 32.0});
    if (global->menu->menu_buttons == NULL)
        printf("oiuon\n");
    show_menu_buttons(global);
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        global->state_game = sfTrue;
    }
}

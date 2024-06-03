/*
** EPITECH PROJECT, 2024
** loading
** File description:
** loading
*/

#include "include/include.h"

void display_bg_load(global_t *global)
{
    sfVector2f pos;

    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawSprite(global->window, global->load_sp[i], NULL);
    for (int i = 0; i < 10; i++) {
        pos = sfSprite_getPosition(global->load_sp[i]);
        pos.x -= (float)((i + 1) * 1.6);
        sfSprite_setPosition(global->load_sp[i], pos);
    }
    for (int i = 0; i < 10; i++) {
        pos = sfSprite_getPosition(global->load_sp[i]);
        if (pos.x <= -1856)
            sfSprite_setPosition(global->load_sp[i], (sfVector2f){0, -500});
    }
}

sfSprite *create_bg_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, (sfVector2f){0, -500});
    sfSprite_setScale(sprite, (sfVector2f){2, 2});
    return sprite;
}

void init_loading_text(global_t *global)
{
    global->load_tx[0] = sfTexture_createFromFile("rs/save_ui/0.png", NULL);
    global->load_tx[1] = sfTexture_createFromFile("rs/save_ui/1.png", NULL);
    global->load_tx[2] = sfTexture_createFromFile("rs/save_ui/2.png", NULL);
    global->load_tx[3] = sfTexture_createFromFile("rs/save_ui/3.png", NULL);
    global->load_tx[4] = sfTexture_createFromFile("rs/save_ui/4.png", NULL);
    global->load_tx[5] = sfTexture_createFromFile("rs/save_ui/5.png", NULL);
    global->load_tx[6] = sfTexture_createFromFile("rs/save_ui/6.png", NULL);
    global->load_tx[7] = sfTexture_createFromFile("rs/save_ui/7.png", NULL);
    global->load_tx[8] = sfTexture_createFromFile("rs/save_ui/8.png", NULL);
    global->load_tx[9] = sfTexture_createFromFile("rs/save_ui/9.png", NULL);
    global->trans_tx[0] =
    sfTexture_createFromFile("rs/save_ui/trans.png", NULL);
    global->trans_tx[1] =
    sfTexture_createFromFile("rs/save_ui/trans2.png", NULL);
}

void create_load_sprite(global_t *global)
{
    init_loading_text(global);
    for (int i = 0; i < 2; i++) {
        global->trans_sp[i] = sfSprite_create();
        sfSprite_setTexture(global->trans_sp[i],
        global->trans_tx[i], sfFalse);
        sfSprite_setScale(global->trans_sp[i], (sfVector2f){10, 10});
    }
    sfSprite_setPosition(global->trans_sp[0], (sfVector2f){1920, 0});
    sfSprite_setPosition(global->trans_sp[1], (sfVector2f){0, 0});
    for (int i = 0; i < 10; i++)
        global->load_sp[i] = create_bg_sprite(global->load_tx[i]);
}

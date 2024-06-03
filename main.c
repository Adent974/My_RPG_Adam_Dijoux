/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include/include.h"

void finish_loop(global_t *global)
{
    mouse(global);
    sfRenderWindow_display(global->window);
    global->settings->mouse_pressed = 0;
    global->settings->mouse_released = 0;
    if (global->exit_program == 1)
        exit(0);
}

void mouse(global_t *global)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(global->window);
    sfVector2f mpos = {pos.x, pos.y};

    if (global->settings->is_fullscreen == 0) {
        if (global->settings->window_size_type == 1) {
            mpos.x *= 1.2;
            mpos.y *= 1.2;
        }
        if (global->settings->window_size_type == 2) {
            mpos.x *= 1.5;
            mpos.y *= 1.5;
        }
    }
    sfRectangleShape_setPosition(global->mouse_rect, mpos);
}

void init_map_bg(global_t *global)
{
    global->map_tx[0] = sfTexture_createFromFile("rs/map/Layer_0.png", NULL);
    global->map_tx[1] = sfTexture_createFromFile("rs/map/Layer_1.png", NULL);
    global->map_tx[2] = sfTexture_createFromFile("rs/map/Layer_2.png", NULL);
    global->map_tx[3] = sfTexture_createFromFile("rs/map/Layer_3.png", NULL);
    global->map_tx[4] = sfTexture_createFromFile("rs/map/Layer_4.png", NULL);
    global->map_tx[5] = sfTexture_createFromFile("rs/map/Layer_5.png", NULL);
    global->map_tx[6] = sfTexture_createFromFile("rs/map/Layer_6.png", NULL);
    global->map_tx[7] = sfTexture_createFromFile("rs/map/Layer_7.png", NULL);
    global->map_tx[8] = sfTexture_createFromFile("rs/map/Layer_8.png", NULL);
    global->map_tx[9] = sfTexture_createFromFile("rs/map/houses.png", NULL);
    for (int i = 0; i < 10; i++) {
        global->map_sprites[i] = sfSprite_create();
        sfTexture_setSmooth(global->map_tx[i], sfFalse);
        sfSprite_setTexture(global->map_sprites[i],
        global->map_tx[i], sfFalse);
        sfSprite_setScale(global->map_sprites[i],
        (sfVector2f){15.0f / 8.0f, 15.0f / 8.0f});
    }
    global->map = parse_collision_csv();
    create_load_sprite(global);
}

int main(void)
{
    global_t *global = my_malloc(sizeof(global_t));

    global->exit_program = 0;
    init_rpg(global);
    init_inventory_ui(global);
    init_inventory_tab(global);
    init_skill_tree(global);
    start_up(global);
    sfMusic_play(global->settings->main_music);
    while (sfRenderWindow_isOpen(global->window)) {
        global->time = sfClock_getElapsedTime(global->clock);
        if (global->time.microseconds >= 16666) {
            sfClock_restart(global->clock);
            game_loop(global);
            finish_loop(global);
        }
    }
    return 0;
}

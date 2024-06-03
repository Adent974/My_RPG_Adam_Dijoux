/*
** EPITECH PROJECT, 2024
** manage
** File description:
** map
*/

#include "include/include.h"

map_t *init_map(void)
{
    map_t *map = my_malloc(sizeof(map_t));

    map->map_rect.left = 0;
    map->map_rect.top = 0;
    map->map_rect.height = 130;
    map->map_rect.width = 128;
    map->state_map = 0;
    map->map_clock = sfClock_create();
    map->map_sprite = sfSprite_create();
    map->map_texture = sfTexture_createFromFile("rs/map_spritesheet.png",
        NULL);
    sfSprite_setTexture(map->map_sprite, map->map_texture, sfFalse);
    sfSprite_setTextureRect(map->map_sprite, map->map_rect);
    sfSprite_setPosition(map->map_sprite, (sfVector2f) {-200, -400});
    sfSprite_setScale(map->map_sprite, (sfVector2f) {15, 15});
    return map;
}

void map_transition(global_t *global)
{
    sfTime time = sfClock_getElapsedTime(global->map_struct->map_clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds >= 0.05) {
        time = sfClock_restart(global->map_struct->map_clock);
        global->map_struct->map_rect.left += 130;
        if (global->map_struct->map_rect.left >= 1300)
            global->map_struct->map_rect.left = 1300;
        sfSprite_setTextureRect(global->map_struct->map_sprite,
            global->map_struct->map_rect);
    }
    sfRenderWindow_drawSprite(global->window, global->map_struct->map_sprite,
    NULL);
}

void manage_map(global_t *global)
{
    sfRenderWindow_clear(global->window, sfTransparent);
    map_transition(global);
    sfRenderWindow_display(global->window);
}

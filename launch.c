/*
** EPITECH PROJECT, 2024
** launch
** File description:
** handle the animation on lauch on the game
*/
#include "include/include.h"

sfText *create_text_spe(char const *name, char *filepath
    , sfVector2f pos, sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(filepath);

    sfText_setString(text, name);
    sfText_setScale(text, (sfVector2f){3.0, 3.0});
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos);
    return text;
}

launch_t *init_launch(void)
{
    launch_t *launch = my_malloc(sizeof(launch_t));

    launch->sound = sfSound_create();
    sfSound_setBuffer(launch->sound
        , sfSoundBuffer_createFromFile("rs/SFX/startup.ogg"));
    sfSound_setVolume(launch->sound, 70);
    launch->logo = create_object("rs/gold_bull.png", (sfVector2f){1, 1}
        , (sfVector2f){450, 50}, (sfIntRect){0, 0, 1024, 1024});
    launch->name = create_text_spe("MALBARPG", "rs/startup.ttf"
        , (sfVector2f){600, 950}, sfWhite);
    launch->load = create_object("rs/FX/03.png", (sfVector2f){2, 2}
        , (sfVector2f){1825, 1000}, (sfIntRect){192, 96, 48, 48});
    sfSound_play(launch->sound);
    launch->clock = sfClock_create();
    sfSprite_setOrigin(launch->load->sprite, (sfVector2f){24, 24});
    return launch;
}

int load(object_t *obj, sfClock *clock)
{
    if (sfClock_getElapsedTime(clock).microseconds > 150000) {
        obj->rect.left -= 48;
        sfClock_restart(clock);
    }
    if (obj->rect.left == -48) {
        obj->rect.left = 192;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        return 1;
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return 0;
}

void clean_startup(global_t *global, launch_t *launch)
{
    global = global;
    sfSprite_destroy(launch->load->sprite);
    sfTexture_destroy(launch->load->texture);
    sfSprite_destroy(launch->logo->sprite);
    sfTexture_destroy(launch->logo->texture);
    sfText_destroy(launch->name);
    sfClock_destroy(launch->clock);
    sfSound_destroy(launch->sound);
}

void start_up(global_t *gl)
{
    int alpha = 0;
    launch_t *launch = init_launch();
    sfColor color = sfSprite_getColor(launch->logo->sprite);
    int counter = 0;

    while (counter != 8) {
        alpha += (alpha != 255 && counter < 4) ? 1 : 0;
        alpha -= (counter >= 4 && alpha != 0) ? 1 : 0;
        sfSprite_rotate(launch->load->sprite, 2);
        sfText_setColor(launch->name, sfColor_fromRGBA(255, 255, 255, alpha));
        sfSprite_setColor(launch->logo->sprite
            , sfColor_fromRGBA(color.r, color.g, color.b, alpha));
        sfRenderWindow_clear(gl->window, sfBlack);
        sfRenderWindow_drawSprite(gl->window, launch->logo->sprite, NULL);
        sfRenderWindow_drawText(gl->window, launch->name, NULL);
        sfRenderWindow_drawSprite(gl->window, launch->load->sprite, NULL);
        counter += load(launch->load, launch->clock);
        sfRenderWindow_display(gl->window);
    }
    clean_startup(gl, launch);
}

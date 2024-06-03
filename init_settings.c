/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

static void set_settings_sprite(settings_t *settings, button_t **buttons)
{
    for (int i = 0; settings->settings_buttons[i]; i++) {
        settings->settings_buttons[i]->sprite = sfSprite_create();
        settings->settings_buttons[i]->texture =
        sfTexture_createFromFile("rs/button_settings.png", NULL);
        sfSprite_setScale(settings->settings_buttons[i]->sprite,
        (sfVector2f){buttons[i]->size.x / 128.0, buttons[i]->size.y / 72.0});
        sfSprite_setTexture(settings->settings_buttons[i]->sprite,
        settings->settings_buttons[i]->texture, sfFalse);
        sfSprite_setPosition(settings->settings_buttons[i]->sprite,
        (sfVector2f){buttons[i]->pos.x, buttons[i]->pos.y});
    }
}

static void init_buttons_volume(button_t **buttons)
{
    buttons[15] = create_button((sfVector2i){600, 250},
    (sfVector2i){125, 125}, &music_down, "MUSIC DOWN");
    buttons[16] = create_button((sfVector2i){750, 250},
    (sfVector2i){125, 125}, &music_up, "MUSIC UP");
    buttons[17] = create_button((sfVector2i){600, 450},
    (sfVector2i){125, 125}, &sfx_down, "SFX DOWN");
    buttons[18] = create_button((sfVector2i){750, 450},
    (sfVector2i){125, 125}, &sfx_up, "SFX UP");
    buttons[19] = create_button((sfVector2i){1315, 240},
    (sfVector2i){145, 135}, &mute_volume, "MUTE VOLUME");
    buttons[20] = create_button((sfVector2i){1315, 440},
    (sfVector2i){145, 135}, &mute_sfx, "MUTE SFX");
    buttons[21] = create_button((sfVector2i){850, 800},
    (sfVector2i){225, 125}, &go_to_main_settings, "RETURN TO SETTINGS");
    buttons[22] = create_button((sfVector2i){850, 660},
    (sfVector2i){225, 125}, &go_to_control_settings, "BIND KEYS");
    buttons[23] = NULL;
}

static void init_buttons_bis(button_t **buttons)
{
    buttons[7] = create_button((sfVector2i){665, 550},
    (sfVector2i){580, 125}, &save_settings, "QUIT SETTINGS");
    buttons[8] = create_button((sfVector2i){335, 225},
    (sfVector2i){350, 125}, &bind_up, "BIND UP");
    buttons[9] = create_button((sfVector2i){335, 400},
    (sfVector2i){350, 125}, &bind_right, "BIND LEFT");
    buttons[10] = create_button((sfVector2i){335, 575},
    (sfVector2i){350, 125}, &bind_left, "BIND RIGHT");
    buttons[11] = create_button((sfVector2i){335, 750},
    (sfVector2i){350, 125}, &bind_down, "BIND DOWN");
    buttons[12] = create_button((sfVector2i){960, 225},
    (sfVector2i){490, 125}, &bind_select, "BIND SELECT");
    buttons[13] = create_button((sfVector2i){960, 400},
    (sfVector2i){490, 125}, &bind_interact, "BIND INTERACT");
    buttons[14] = create_button((sfVector2i){1130, 675},
    (sfVector2i){225, 125}, &go_to_game_settings, "SAVECONTROLS");
    init_buttons_volume(buttons);
}

button_t **init_settings_buttons(void)
{
    button_t **buttons = my_malloc(sizeof(button_t *) * 24);

    buttons[0] = create_button((sfVector2i){450, 250}, (sfVector2i){125, 125},
    &change_resolution_left, "<");
    buttons[1] = create_button((sfVector2i){590, 250}, (sfVector2i){125, 125},
    &change_resolution_right, ">");
    buttons[2] = create_button((sfVector2i){600, 500}, (sfVector2i){700, 125},
    &fullscreen_func, "VIDEO MODE");
    buttons[3] = create_button((sfVector2i){835, 760}, (sfVector2i){225, 125},
    &go_to_main_settings, "RETURN TO SETTINGS");
    buttons[4] = create_button((sfVector2i){600, 150}, (sfVector2i){700, 125},
    &go_to_video_settings, "VIDEO_SETTINGS");
    buttons[5] = create_button((sfVector2i){600, 350}, (sfVector2i){700, 125},
    &go_to_game_settings, "GAME_SETTINGS");
    buttons[6] = create_button((sfVector2i){600, 750}, (sfVector2i){700, 125},
    &go_to_main_menu, "GO_MAIN_MENU");
    init_buttons_bis(buttons);
    return buttons;
}

void init_keys(settings_t *settings)
{
    settings->move_keys[0] = sfKeyZ;
    settings->move_keys[1] = sfKeyQ;
    settings->move_keys[2] = sfKeyS;
    settings->move_keys[3] = sfKeyD;
    settings->move_keys[4] = sfKeyA;
    settings->move_keys[5] = sfKeyE;
    settings->move_keys[6] = sfKeyP;
    settings->move_keys[7] = sfKeyM;
}

static void init_settings_bis(settings_t *settings)
{
    settings->volume_mute = sfFalse;
    settings->sfx_mute = sfFalse;
    settings->rect.left = 685;
    settings->rect.top = 0;
    settings->rect.width = 220;
    settings->rect.height = 350;
    settings->volume_sprite1 = sfSprite_create();
    settings->volume_texture1 = sfTexture_createFromFile("rs/vol.png", NULL);
    sfSprite_setTexture(settings->volume_sprite1,
    settings->volume_texture1, sfFalse);
    sfSprite_setTextureRect(settings->volume_sprite1, settings->rect);
    settings->volume_sprite2 = sfSprite_create();
    settings->volume_texture2 = sfTexture_createFromFile("rs/vol.png", NULL);
    sfSprite_setTexture(settings->volume_sprite2,
    settings->volume_texture2, sfFalse);
    sfSprite_setTextureRect(settings->volume_sprite2, settings->rect);
    sfSprite_setPosition(settings->volume_sprite1, (sfVector2f){1495, 175});
    sfSprite_setPosition(settings->volume_sprite2, (sfVector2f){1495, 475});
    sfSprite_setScale(settings->volume_sprite1, (sfVector2f){0.65, 0.65});
    sfSprite_setScale(settings->volume_sprite2, (sfVector2f){0.65, 0.65});
}

settings_t *init_settings(void)
{
    settings_t *settings = my_malloc(sizeof(settings_t));

    settings->mouse_hold = 0;
    settings->mouse_pressed = 0;
    settings->mouse_released = 0;
    settings->settings_index = 0;
    init_keys(settings);
    settings->settings_active = 0;
    settings->window_size_type = 0;
    settings->is_fullscreen = 0;
    settings->selected_button_index = 0;
    settings->sfx_volume = 50;
    settings->music_volume = 50;
    settings->settings_buttons = init_settings_buttons();
    settings->main_music = sfMusic_createFromFile("rs/The-Quest-Begins.ogg");
    set_settings_sprite(settings, settings->settings_buttons);
    init_settings_bis(settings);
    return settings;
}

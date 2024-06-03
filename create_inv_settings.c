/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"


object_t **create_inventory_settings_menu(void)
{
    object_t **tab = my_malloc(sizeof(object_t *) * 4);

    tab[0] = create_inv_obj((sfVector2f){450, 100},
    (sfVector2f){1400, 250}, &graphics_state);
    tab[1] = create_inv_obj((sfVector2f){450, 400},
    (sfVector2f){1400, 250}, &audio_state);
    tab[2] = create_inv_obj((sfVector2f){450, 700},
    (sfVector2f){1400, 250}, &control_state);
    tab[3] = NULL;
    return tab;
}

object_t **create_inventory_settings_graphics(void)
{
    object_t **tab = my_malloc(sizeof(object_t *) * 6);

    tab[0] = create_inv_obj((sfVector2f){450, 200},
    (sfVector2f){150, 200}, &change_resolution_left);
    tab[1] = create_inv_obj((sfVector2f){650, 200},
    (sfVector2f){1010, 200}, &tmp);
    tab[2] = create_inv_obj((sfVector2f){1710, 200},
    (sfVector2f){150, 200}, &change_resolution_right);
    tab[3] = create_inv_obj((sfVector2f){450, 500},
    (sfVector2f){1400, 250}, &fullscreen_func);
    tab[4] = create_inv_obj((sfVector2f){1620, 930},
    (sfVector2f){300, 150}, &state_2);
    tab[5] = NULL;
    return tab;
}

static void create_inv_set_bis(object_t **tab)
{
    tab[5] = create_inv_obj((sfVector2f){1100, 350},
    (sfVector2f){100, 100}, &bind_select);
    tab[6] = create_inv_obj((sfVector2f){1100, 550},
    (sfVector2f){100, 100}, &bind_confirm);
    tab[7] = create_inv_obj((sfVector2f){1100, 750},
    (sfVector2f){100, 100}, &bind_minimap);
    tab[8] = create_inv_obj((sfVector2f){1620, 930},
    (sfVector2f){300, 150}, &state_2);
    tab[9] = NULL;
}

object_t **create_inventory_settings_controls(void)
{
    object_t **tab = my_malloc(sizeof(object_t *) * 10);

    tab[0] = create_inv_obj((sfVector2f){600, 400},
    (sfVector2f){100, 100}, &bind_up);
    tab[1] = create_inv_obj((sfVector2f){450, 550},
    (sfVector2f){100, 100}, &bind_left);
    tab[2] = create_inv_obj((sfVector2f){600, 550},
    (sfVector2f){100, 100}, &bind_down);
    tab[3] = create_inv_obj((sfVector2f){750, 550},
    (sfVector2f){100, 100}, &bind_right);
    tab[4] = create_inv_obj((sfVector2f){1100, 150},
    (sfVector2f){100, 100}, &bind_interact);
    create_inv_set_bis(tab);
    return tab;
}

static void create_inv_audio_bis(object_t **tab)
{
    tab[5] = create_inv_obj((sfVector2f){1720, 500},
    (sfVector2f){150, 150}, &sfx_up);
    tab[6] = create_inv_obj((sfVector2f){1620, 930},
    (sfVector2f){300, 150}, &state_2);
    tab[7] = create_inv_obj((sfVector2f){1500, 200},
    (sfVector2f){150, 150}, &mute_volume);
    tab[8] = create_inv_obj((sfVector2f){1500, 500},
    (sfVector2f){150, 150}, &mute_sfx);
    tab[9] = NULL;
}

object_t **create_inventory_settings_audio(void)
{
    object_t **tab = my_malloc(sizeof(object_t *) * 10);

    tab[0] = create_inv_obj((sfVector2f){450, 200},
    (sfVector2f){150, 150}, &music_down);
    tab[1] = create_inv_obj((sfVector2f){650, 200},
    (sfVector2f){1020, 150}, &tmp);
    tab[2] = create_inv_obj((sfVector2f){1720, 200},
    (sfVector2f){150, 150}, &music_up);
    tab[3] = create_inv_obj((sfVector2f){450, 500},
    (sfVector2f){150, 150}, &sfx_down);
    tab[4] = create_inv_obj((sfVector2f){650, 500},
    (sfVector2f){1020, 150}, &tmp);
    create_inv_audio_bis(tab);
    return tab;
}

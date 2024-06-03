/*
** EPITECH PROJECT, 2024
** ui
** File description:
** ui
*/

#include "include/include.h"

void init_inventory_tab(global_t *global)
{
    global->select_tab = create_inventory_select();
    global->inventory_tab = create_inventory_obj();
    global->settings_menu_tab = create_inventory_settings_menu();
    global->graphics_tab = create_inventory_settings_graphics();
    global->audio_tab = create_inventory_settings_audio();
    global->controls_tab = create_inventory_settings_controls();
    global->inventory_state = 2;
    global->settings_state = 0;
}

void display_text(global_t *global, sfVector2f pos, int size, char *str)
{
    sfText_setCharacterSize(global->inventory_text, size);
    sfText_setString(global->inventory_text, str);
    sfText_setPosition(global->inventory_text, pos);
    sfRenderWindow_drawText(global->window, global->inventory_text, NULL);
}

void display_select_text(global_t *global)
{
    sfText_setFont(global->inventory_text, global->startup_font);
    display_text(global, (sfVector2f){50, 80}, 40, "MENU");
    display_text(global, (sfVector2f){50, 250}, 25, "SETTINGS");
    display_text(global, (sfVector2f){50, 420}, 20, "INVENTORY");
    display_text(global, (sfVector2f){50, 590}, 30, "SKILLS");
    display_text(global, (sfVector2f){50, 760}, 30, "MAP");
    display_text(global, (sfVector2f){50, 930}, 30, "SAVE");
}

void display_minimap(global_t *global)
{
    if (global->inventory_state != 5)
        return;
    show_sprite(global->window, "rs/map/minimap.png",
    (sfVector2f){650, -110}, (sfVector2f){1.3, 1.3});
}

void inventory_ui(global_t *global)
{
    sfRenderWindow_clear(global->window, sfWhite);
    show_sprite(global->window, "rs/Save_Menu_bg.png", (sfVector2f){0, 0},
    (sfVector2f){1.5, 1.5});
    if (global->inventory_state == 3)
        for (int i = 0; global->inventory_tab[i]; i++)
            sfRenderWindow_drawRectangleShape(global->window,
            global->inventory_tab[i]->shape, NULL);
    if (global->inventory_state == 2)
        manage_settings_obj(global);
    if (global->inventory_state == 4)
        skill_tree_loop(global, global->skill_nodes);
    for (int i = 0; global->select_tab[i]; i++)
        manage_select_obj(global, i);
    display_select_text(global);
    display_settings_text(global);
    display_minimap(global);
    display_inventory_settings(global);
    mouse(global);
}

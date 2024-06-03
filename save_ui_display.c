/*
** EPITECH PROJECT, 2024
** save ui
** File description:
** save ui
*/

#include "include/include.h"


void display_save_ui_menu(global_t *global, sfText *text)
{
    sfText_setPosition(text, (sfVector2f){800, 175});
    sfText_setString(text, "LOAD");
    sfText_setCharacterSize(text, 100);
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SAVE");
    sfText_setPosition(text, (sfVector2f){800, 475});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "EXIT");
    sfText_setPosition(text, (sfVector2f){815, 775});
    sfRenderWindow_drawText(global->window, text, NULL);
}

void display_save_ui_save(global_t *global, sfText *text)
{
    sfText_setCharacterSize(text, 100);
    sfText_setString(text, "SLOT 1");
    sfText_setPosition(text, (sfVector2f){975, 175});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SLOT 2");
    sfText_setPosition(text, (sfVector2f){975, 475});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SLOT 3");
    sfText_setPosition(text, (sfVector2f){975, 775});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setCharacterSize(text, 50);
    sfText_setString(text, "RETURN");
    sfText_setPosition(text, (sfVector2f){175, 875});
    sfRenderWindow_drawText(global->window, text, NULL);
}

void display_auto_save_text(global_t *global, sfText *text)
{
    sfText_setCharacterSize(text, 25);
    sfText_setString(text, "Automatic save");
    sfText_setPosition(text, (sfVector2f){1570, 335});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setPosition(text, (sfVector2f){1570, 630});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setPosition(text, (sfVector2f){1570, 925});
    sfRenderWindow_drawText(global->window, text, NULL);
}

void display_save_ui_load_bis(global_t *global, sfText *text)
{
    sfText_setString(text, "SLOT 3");
    sfText_setPosition(text, (sfVector2f){675, 775});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SLOT 1");
    sfText_setPosition(text, (sfVector2f){1300, 175});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SLOT 2");
    sfText_setPosition(text, (sfVector2f){1300, 475});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SLOT 3");
    sfText_setPosition(text, (sfVector2f){1300, 775});
    sfRenderWindow_drawText(global->window, text, NULL);
    display_auto_save_text(global, text);
}

void display_save_ui_load(global_t *global, sfText *text)
{
    sfText_setCharacterSize(text, 50);
    sfText_setString(text, "RETURN");
    sfText_setPosition(text, (sfVector2f){175, 875});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setCharacterSize(text, 100);
    sfText_setString(text, "SLOT 1");
    sfText_setPosition(text, (sfVector2f){675, 175});
    sfRenderWindow_drawText(global->window, text, NULL);
    sfText_setString(text, "SLOT 2");
    sfText_setPosition(text, (sfVector2f){675, 475});
    sfRenderWindow_drawText(global->window, text, NULL);
    display_save_ui_load_bis(global, text);
}

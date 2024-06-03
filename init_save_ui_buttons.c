/*
** EPITECH PROJECT, 2024
** save ui
** File description:
** save ui
*/

#include "include/include.h"


void save_gb_bt_bis(global_t *global)
{
    global->save_ui_buttons[6] = create_button((sfVector2i){120, 840},
    (sfVector2i){325, 125}, &main_ui, "RETOUR");
    global->save_ui_buttons[7] = create_button((sfVector2i){520, 120},
    (sfVector2i){600, 270}, &load_man_save_1, "LOAD MAN SAVE 1");
    global->save_ui_buttons[8] = create_button((sfVector2i){1175, 120},
    (sfVector2i){600, 270}, &load_auto_save_1, "LOAD AUTO SAVE 1");
    global->save_ui_buttons[9] = create_button((sfVector2i){520, 410},
    (sfVector2i){600, 270}, &load_man_save_2, "LOAD MAN SAVE 2");
    global->save_ui_buttons[10] = create_button((sfVector2i){1175, 410},
    (sfVector2i){600, 270}, &load_auto_save_2, "LOAD AUTO SAVE 2");
    global->save_ui_buttons[11] = create_button((sfVector2i){520, 700},
    (sfVector2i){600, 270}, &load_man_save_3, "LOAD MAN SAVE 3");
    global->save_ui_buttons[12] = create_button((sfVector2i){1175, 700},
    (sfVector2i){600, 270}, &load_auto_save_3, "LOAD AUTP SAVE 3");
    global->save_ui_buttons[13] = create_button((sfVector2i){120, 840},
    (sfVector2i){325, 125}, &main_ui, "RETOUR");
    global->save_ui_buttons[14] = NULL;
}

void save_gb_bt(global_t *global)
{
    global->save_ui_buttons = my_malloc(sizeof(button_t *) * 15);
    global->save_ui_buttons[0] = create_button((sfVector2i){120, 120},
    (sfVector2i){1680, 270}, &button_save, "SAUVEGARDER");
    global->save_ui_buttons[1] = create_button((sfVector2i){120, 410},
    (sfVector2i){1680, 270}, &button_load, "CHARGER");
    global->save_ui_buttons[2] = create_button((sfVector2i){120, 700},
    (sfVector2i){1680, 270}, &quit_save_ui, "RETOUR");
    global->save_ui_buttons[3] = create_button((sfVector2i){520, 120},
    (sfVector2i){1280, 270}, &save_slot_1, "SAVE SLOT 1");
    global->save_ui_buttons[4] = create_button((sfVector2i){520, 410},
    (sfVector2i){1280, 270}, &save_slot_2, "SAVE SLOT 2");
    global->save_ui_buttons[5] = create_button((sfVector2i){520, 700},
    (sfVector2i){1280, 270}, &save_slot_3, "SAVE SLOT 3");
    save_gb_bt_bis(global);
}

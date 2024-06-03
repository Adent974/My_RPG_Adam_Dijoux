/*
** EPITECH PROJECT, 2024
** load
** File description:
** load
*/

#include "include/include.h"

void loader(global_t *global, int slot)
{
    char slot_number[2];
    char *buffer = NULL;
    char *filename = NULL;
    char **content = NULL;

    slot_number[0] = slot + '0';
    slot_number[1] = '\0';
    filename = my_strcat(strdup("SAVES/SAVE_SLOT_"), slot_number, "");
    buffer = fileread(filename);
    content = my_str_to_array(buffer, "\n");
    load_player(global, content);
    load_pnj(global, content);
    load_inventory(global, content);
    load_enemy(global, content);
    mini_cleaner(buffer, content);
    free(filename);
    global->transition_status = 0;
}

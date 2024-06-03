/*
** EPITECH PROJECT, 2024
** save
** File description:
** save
*/

#include "include/include.h"

void create_save_config(global_t *global, int fd)
{
    dprintf(fd, "##MUSIC##\n");
    dprintf(fd, "sfx:%f\n", global->settings->sfx_volume);
    dprintf(fd, "music:%f\n", global->settings->music_volume);
    dprintf(fd, "###WINDOW##");
    dprintf(fd, "size:%d\n", global->settings->window_size_type);
    dprintf(fd, "fullscreen:%d\n", global->settings->is_fullscreen);
}

static void create_save_dialogue(global_t *global, int fd)
{
    dprintf(fd, "##PNJ##\n");
    for (int i = 0; global->pnj[i]; i++) {
        dprintf(fd, "#PNJ_INFO#\n");
        dprintf(fd, "name:%s\n", global->pnj[i]->name);
        dprintf(fd, "id:%d\n", global->pnj[i]->id);
        dprintf(fd, "nb_talks:%d\n", global->pnj[i]->dialogue->nb_talks);
    }
}

static void create_save_inventory(global_t *global, int fd)
{
    dprintf(fd, "##INVENTORY##\n");
    dprintf(fd, "#GEAR#\n");
    for (int i = 0; global->pl->inv->gears[i]; i++)
        if (global->pl->inv->gears[i]->name)
            dprintf(fd, "%s\n", global->pl->inv->gears[i]->name);
    dprintf(fd, "#ITEM#\n");
    for (int i = 0; global->pl->inv->items[i]; i++)
        if (global->pl->inv->items[i]->name)
            dprintf(fd, "%s:%d\n", global->pl->inv->items[i]->name,
            global->pl->inv->items[i]->quantity);
}

void create_save_player(global_t *global, int fd)
{
    dprintf(fd, "##PLAYER##\n");
    for (int i = 0; i < 10; i++)
        dprintf(fd, "skill:%d:%d\n", i, global->pl->skills[i]);
    dprintf(fd, "enemy_killed:%d\n", global->pl->enemy_killed);
    dprintf(fd, "hp:%d\n", global->pl->stats->hp);
    dprintf(fd, "pos:%f:%f\n", global->pl->pos.x, global->pl->pos.y);
    dprintf(fd, "max_hp:%d\n", global->pl->stats->max_hp);
    dprintf(fd, "max_mn:%d\n", global->pl->stats->max_mana);
    dprintf(fd, "mana:%d\n", global->pl->stats->mana);
    dprintf(fd, "defense:%d\n", global->pl->stats->def);
}

void create_save_enemy(global_t *global, int fd)
{
    dprintf(fd, "##ENEMY##\n");
    for (int i = 0; global->enemies[i]; i++)
        dprintf(fd, "%d:%d\n", i, global->enemies[i]->dead);
}

void create_save(global_t *global, int slot)
{
    char slot_str[1024];
    char *filename = strdup("./SAVES/SAVE_SLOT");
    int fd = 0;

    gcvt(slot, sizeof(slot_str), slot_str);
    filename = my_strcat(filename, slot_str, "_");
    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    create_save_player(global, fd);
    create_save_inventory(global, fd);
    create_save_dialogue(global, fd);
    create_save_enemy(global, fd);
    dprintf(fd, "EOF");
    close(fd);
}

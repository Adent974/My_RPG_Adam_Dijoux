/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"

void display_stats_bis(global_t *global, char *buff)
{
    sprintf(buff, "%d", global->pl->stats->def);
    display_text(global, (sfVector2f){675, 75}, 40, buff);
    display_text(global, (sfVector2f){575, 120}, 40, "CRIT :");
    sprintf(buff, "%d", global->pl->stats->crit);
    display_text(global, (sfVector2f){680, 120}, 40, buff);
    display_text(global, (sfVector2f){575, 165}, 40, "XP :");
    sprintf(buff, "%d / %d", global->pl->xp, global->pl->xp_limit);
    display_text(global, (sfVector2f){660, 165}, 40, buff);
    display_text(global, (sfVector2f){800, 75}, 40, "Coins :");
    sprintf(buff, "%d", 10);
    display_text(global, (sfVector2f){925, 75}, 40, buff);
}

void display_stats(global_t *global, char *buff)
{
    sfText_setFont(global->inventory_text, global->regular_font);
    display_text(global, (sfVector2f){335, 75}, 40, "HP :");
    sprintf(buff, "%d", global->pl->stats->hp);
    display_text(global, (sfVector2f){415, 75}, 40, buff);
    display_text(global, (sfVector2f){325, 120}, 40, "MANA :");
    sprintf(buff, "%d", global->pl->stats->mana);
    display_text(global, (sfVector2f){475, 120}, 40, buff);
    display_text(global, (sfVector2f){325, 165}, 40, "ATK :");
    sprintf(buff, "%d", global->pl->stats->dmg);
    display_text(global, (sfVector2f){415, 165}, 40, buff);
    display_text(global, (sfVector2f){575, 75}, 40, "DEF :");
    display_stats_bis(global, buff);
}

void display_main_text(global_t *global, char *buff)
{
    sfText_setFont(global->inventory_text, global->startup_font);
    display_text(global, (sfVector2f){700, 325}, 35, "Gears");
    display_text(global, (sfVector2f){700, 625}, 35, "Items");
    display_text(global, (sfVector2f){325, 25}, 35, "STATS");
    display_text(global, (sfVector2f){1100, 100}, 100, "LEVEL");
    sfText_setFont(global->inventory_text, global->karma_font);
    sprintf(buff, "%d", global->pl->level);
    display_text(global, (sfVector2f){1690, 70}, 120, buff);
}

void display_inventory_settings(global_t *global)
{
    char buff[1024];

    if (global->inventory_state != 3)
        return;
    display_main_text(global, buff);
    display_stats(global, buff);
    sfSprite_setPosition(global->pl->sprite, (sfVector2f){500, 550});
    sfSprite_setScale(global->pl->sprite, (sfVector2f){14, 14});
    anim_idle(global);
    sfSprite_setTexture(global->pl->sprite, global->pl->idle_texture, sfTrue);
    sfSprite_setTextureRect(global->pl->sprite, global->pl->rect);
    sfRenderWindow_drawSprite(global->window, global->pl->sprite, NULL);
}

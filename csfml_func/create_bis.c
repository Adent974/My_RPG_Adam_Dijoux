/*
** EPITECH PROJECT, 2024
** create_bis
** File description:
** create diffrent things
*/
#include "../include/include.h"

object_t *create_object(char *name, sfVector2f scaling, sfVector2f pos,
    sfIntRect rect)
{
    object_t *obj = malloc(sizeof(object_t) + 1);

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(name, NULL);
    obj->rect = rect;
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setScale(obj->sprite, scaling);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return obj;
}

static enemy_t *create_enemy_bis(enemy_t *tmp, sfVector2f pos)
{
    tmp->hp_bar = malloc(sizeof(sfRectangleShape *) * 3);
    tmp->hp_bar[0] = create_rectangle((sfVector2f){450, 750},
        (sfVector2f){600, 30},
        sfColor_fromRGB(115, 115, 115));
    tmp->hp_bar[1] = create_rectangle((sfVector2f){450, 750},
        (sfVector2f){get_ratio(tmp->stats->hp
            , tmp->stats->max_hp, 600), 30}, sfRed);
    tmp->hp_bar[2] = NULL;
    tmp->dead = 0;
    tmp->status_list = init_status(tmp->status_list);
    tmp->bounds = create_rectangle(pos, (sfVector2f){100, 100}, sfRed);
}

static enemy_t *create_enemy(char *path, sfVector2f pos, int type, char *name)
{
    enemy_t *tmp = malloc(sizeof(enemy_t) + 1);

    tmp->name = strdup(name);
    tmp->stats = set_stats();
    tmp->pos = pos;
    tmp->enemy_type = type;
    tmp->stats->hp = 40;
    tmp->stats->max_hp = 40;
    tmp->stats->crit = 10;
    tmp->stats->dmg = 10;
    tmp->stats->def = 5;
    tmp->stats->dmg_save = 0;
    tmp->stats->def_save = 0;
    tmp->stats->mode = 1;
    tmp->level = 1;
    tmp->obj = create_object(path, (sfVector2f){0.2, 0.2}, pos
    , create_rect(0, 0, 480, 480));
    tmp->xp_given = 5;
    create_enemy_bis(tmp, pos);
    return tmp;
}

enemy_t **init_enemy(void)
{
    enemy_t **tab = malloc(sizeof(enemy_t *) * 4);

    tab[0] = create_enemy("rs/goblin.png"
        , (sfVector2f){1200, 300}, 1, "MALA MANGATEL");
    tab[1] = create_enemy("rs/goblin.png"
        , (sfVector2f){1300, 300}, 1, "MALA MANGATEL");
    tab[2] = create_enemy("rs/goblin.png"
        , (sfVector2f){1400, 300}, 1, "MALA MANGATEL");
    tab[3] = NULL;
    return tab;
}

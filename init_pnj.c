/*
** EPITECH PROJECT, 2024
** pnj
** File description:
** pnj
*/

#include "include/include.h"

static pnj_t *create_pnj(char *path, int id, char *name, sfVector2f pos)
{
    pnj_t *pnj = my_malloc(sizeof(pnj_t));

    pnj->dialogue = my_malloc(sizeof(dialogue_t));
    init_dialogue(pnj->dialogue, path);
    pnj->id = id;
    pnj->name = strdup(name);
    pnj->pos = pos;
    return pnj;
}

pnj_t *get_pnj_from_name(global_t *global, char *pnj_name)
{
    for (int i = 0; global->pnj[i]; i++)
        if (strcmp(global->pnj[i]->name, pnj_name) == 0) {
            return global->pnj[i];
        }
    return NULL;
}

void pnj_aux(global_t *global, int i)
{
    if (get_distance((sfVector2i){global->pl->pos.x, global->pl->pos.y},
        (sfVector2i){global->pnj[i]->pos.x, global->pnj[i]->pos.y}) < 100 &&
        sfKeyboard_isKeyPressed(global->settings->move_keys[5])) {
            global->dialogue = global->pnj[i]->dialogue;
            global->quest->current_pnj = i;
            global->dialogue_active = 1;
            global->animation->is_active = 1;
            if (global->quest->current_pnj == 4)
                combat_hud(global);
    }
}

void animate_pnj(pnj_t **pnj, global_t *global)
{
    int passed = 0;

    for (int i = 0; pnj[i]; i++) {
        pnj[i]->pnj_obj->rect.left =
            (pnj[i]->pnj_obj->rect.left == 240)
                ? 0 : pnj[i]->pnj_obj->rect.left;
        if (sfClock_getElapsedTime(global->animation_clock)
            .microseconds >= 250000) {
            passed = 1;
            pnj[i]->pnj_obj->rect.left += 80;
        }
        sfSprite_setTextureRect(pnj[i]->pnj_obj->sprite
            , pnj[i]->pnj_obj->rect);
    }
    if (passed == 1)
        sfClock_restart(global->animation_clock);
}

void manage_pnj(global_t *global)
{
    for (int i = 0; global->pnj[i]; i++) {
        global->pnj[i]->pos = sfSprite_getPosition
            (global->pnj[i]->pnj_obj->sprite);
        roam_enemy(global, global->pnj);
        sfSprite_move(global->pnj[i]->pnj_obj->sprite, global->pnj[i]->offset);
        animate_pnj(global->pnj, global);
        sfRenderWindow_drawSprite(global->window
            , global->pnj[i]->pnj_obj->sprite, NULL);
        show_text(global->window, global->pnj[i]->name,
        (sfVector3f){global->pnj[i]->pos.x - 30,
        global->pnj[i]->pos.y + 20, 20}, "rs/adam.ttf");
        if (get_distance((sfVector2i){global->pl->pos.x, global->pl->pos.y},
        (sfVector2i){global->pnj[i]->pos.x, global->pnj[i]->pos.y}) < 100) {
            show_text(global->window, "*INTERACT*",
            (sfVector3f){global->pnj[i]->pos.x - 50,
            global->pnj[i]->pos.y - 50, 20}, "rs/adam.ttf");
        }
        pnj_aux(global, i);
    }
}

static void init_sprite(pnj_t **pnj_tab)
{
    int x = 0;
    int y = 0;
    int way = 0;

    for (int i = 0; pnj_tab[i]; i++) {
        way = rand() % 2 - 1;
        x = (way == -1) ? (rand() % 300 - 150) + pnj_tab[i]->pos.x
            : ((rand() % 300 - 150) + pnj_tab[i]->pos.x) * -1;
        y = (way == -1) ? (rand() % 300 - 150) + pnj_tab[i]->pos.y
            : ((rand() % 300 - 150) + pnj_tab[i]->pos.y) * -1;
        pnj_tab[i]->pnj_obj = create_object("rs/PNJ/run.png"
            , (sfVector2f){3, 3}, pnj_tab[i]->pos, (sfIntRect){0, 0, 80, 80});
        sfSprite_setOrigin(pnj_tab[i]->pnj_obj->sprite, (sfVector2f){40, 40});
        pnj_tab[i]->offset = (sfVector2f){(x) / 1000, (y) / 1000};
    }
}

pnj_t **init_pnj(void)
{
    pnj_t **pnj_tab = my_malloc(sizeof(pnj_t *) * (6));

    pnj_tab[0] = create_pnj("dialogues_txt/test.txt", 0,
    "monsieur 0", (sfVector2f){700, 700});
    pnj_tab[1] = create_pnj("dialogues_txt/pnj_1.txt", 1,
    "monsieur 1", (sfVector2f){1000, 700});
    pnj_tab[2] = create_pnj("dialogues_txt/pnj_2.txt", 2,
    "monsieur 2", (sfVector2f){1300, 700});
    pnj_tab[3] = create_pnj("dialogues_txt/bresom.txt", 2,
    "(?)", (sfVector2f){1700, 700});
    pnj_tab[4] = create_pnj("dialogues_txt/mael.txt", 2,
    "Mata Mangael", (sfVector2f){2000, 700});
    pnj_tab[5] = NULL;
    init_sprite(pnj_tab);
    return pnj_tab;
}

/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "include/include.h"

static bar_t *init_bar(global_t *global)
{
    bar_t *tmp = malloc(sizeof(bar_t) + 1);

    tmp->inter = create_rectangle((sfVector2f){1400, 660}
        , (sfVector2f){500, 400}, sfWhite);
    tmp->life = malloc(sizeof(sfRectangleShape *) * 3);
    tmp->mana = malloc(sizeof(sfRectangleShape *) * 3);
    tmp->life[0] = create_rectangle((sfVector2f){1500, 725}
        , (sfVector2f){375, 25}, sfColor_fromRGBA(115, 115, 115, 255));
    tmp->life[1] = create_rectangle((sfVector2f){1500, 725}
        , (sfVector2f){get_ratio(global->pl->stats->hp
            , global->pl->stats->max_hp, 375), 25}, sfGreen);
    tmp->life[2] = NULL;
    tmp->mana[0] = create_rectangle((sfVector2f){1500, 825}
        , (sfVector2f){375, 25}, sfColor_fromRGBA(115, 115, 115, 255));
    tmp->mana[1] = create_rectangle((sfVector2f){1500, 825}
        , (sfVector2f){get_ratio(global->pl->stats->mana
            , global->pl->stats->max_hp, 375), 25}, sfBlue);
    tmp->mana[2] = NULL;
    return tmp;
}

static void init_player_bis(player_t *player, global_t *gl)
{
    player->offset.x = 0;
    player->offset.y = 0;
    player->pffset.x = 75;
    player->pffset.y = 100;
    player->rect.left = 0;
    player->rect.top = 0;
    player->rect.height = 80;
    player->rect.width = 120;
    player->level = 1;
    player->xp = 0;
    player->xp_limit = 20;
    player->status = my_strdup("NORMAL");
    player->bars = init_bar(gl);
    player->obj = create_object("rs/Player/Idle.png", (sfVector2f){3, 3}
        , (sfVector2f){400, 400}, create_rect(0, 0, 231, 190));
    sfSprite_setScale(player->sprite, (sfVector2f) {2.5, 2.5});
}

static void add_starting_gear(global_t *gl, player_t *pl)
{
    add_gear(pl->inv, get_gear("Baton"));
    equip(gl, gear_from_inv(gl, "Baton"));
    add_gear(pl->inv, get_gear("Epee en bois"));
    equip(gl, gear_from_inv(gl, "Epee en bois"));
    add_gear(pl->inv, get_gear("Lance Pierre"));
    add_item(pl->inv, get_item("Monster"), 5);
    equip(gl, gear_from_inv(gl, "Lance Pierre"));
}

static player_t *init_player(global_t *gl)
{
    player_t *player = my_malloc(sizeof(player_t));

    gl->pl = player;
    player->stats = set_pl_stat(set_stats());
    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile("rs/_Run.png", NULL);
    player->idle_texture = sfTexture_createFromFile("rs/_Idle.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->pos = (sfVector2f){450, 8525};
    player->pl_clock = sfClock_create();
    player->inv = init_inventory(player);
    player->status_list = init_status(player->status_list);
    sfSprite_setOrigin(player->sprite, (sfVector2f) {55, 55});
    add_starting_gear(gl, player);
    init_player_bis(player, gl);
    return player;
}

sfRectangleShape **init_transition(void)
{
    sfRectangleShape **rects = my_malloc(sizeof(sfRectangleShape *) * 3);

    rects[0] = create_rectangle((sfVector2f){0, 100}
        , (sfVector2f){10, 600}, sfBlack);
    rects[1] = create_rectangle((sfVector2f){1920, 700}
        , (sfVector2f){10, 600}, sfBlack);
    rects[2] = NULL;
    return rects;
}

animation_t *init_animation(void)
{
    animation_t *anim = my_malloc(sizeof(animation_t));

    anim->cur_size = (sfVector2i){0, 0};
    anim->is_active = 0;
    anim->clock = sfClock_create();
    return anim;
}

void global_aux(global_t *global, sfVector2f pos)
{
    global->state_game = sfFalse;
    global->menu = my_malloc(sizeof(menu_t));
    global->menu->menu_buttons = init_main_menu_buttons();
    set_menu_sprite(global->menu, global->menu->menu_buttons);
    global->combat = init_combat(global);
    global->combat->combat_view = (sfVector2f){pos.x + 450, pos.y + 35};
    global->pl->bars->texts = status_bar(global);
    global->save_ui_state = -1;
    global->state_game = sfFalse;
    global->state_menu = sfTrue;
    save_gb_bt(global);
}

static void init_clock(global_t *global)
{
    global->clock = sfClock_create();
    global->roam_clock = sfClock_create();
    global->animation_clock = sfClock_create();
}

static void init_global_bis(global_t *global)
{
    global->settings = init_settings();
    global->pl = init_player(global);
    global->pnj = init_pnj();
    global->current_pnj = NULL;
    global->dialogue = global->pnj[0]->dialogue;
    global->enemies = init_enemy();
    global->animation = init_animation();
    global->map_struct = init_map();
}

void init_global(global_t *global)
{
    sfVector2f pos;

    srand(time(0));
    global->window = window_create(1920, 1080, 32, 60);
    global->view = sfView_create();
    init_clock(global);
    pos = sfView_getCenter(global->view);
    global->dialogue_active = 0;
    global->time = sfClock_getElapsedTime(global->clock);
    sfView_setSize(global->view, (sfVector2f){1920, 1080});
    global->quest = init_quest("quetes_txt/main.txt");
    init_global_bis(global);
    global_aux(global, pos);
    global->selecting = 0;
    global->pl->bounds = create_rectangle(global->pl->pos,
    (sfVector2f){100, 100}, sfRed);
}

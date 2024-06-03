/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT
    #define STRUCT
    #include "include.h"

struct global_s;
struct item_s;
struct gear_s;
typedef struct stats_s {
    int hp;
    int mana;
    int max_hp;
    int max_mana;
    int dmg;
    int def;
    int speed;
    int crit;
    int prec;
    int esq;
    float skip;
    int dmg_save;
    int def_save;
    int mode;
}stats_t;

typedef struct status_s {
    int type;
    int force;
    int duration;
}status_t;

typedef struct statlist_s {
    status_t *poison;
    status_t *burn;
    status_t *para;
    status_t *stun;
    status_t *frozen;
    status_t *atk_boost;
    status_t *def_boost;
    status_t *speed_boost;
    status_t *crit_boost;
}statlist_t;

typedef struct object_s {
    sfIntRect rect;
    sfRectangleShape *shape;
    void (*func)(struct global_s *);
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
}object_t;

typedef struct item_s { //ajouter un pointeur sur fonction pour un effet
    char *name;
    char *type;
    int dmg;
    int crit;
    int quantity;
    int mode;
    object_t *img;
    void (*func)(struct global_s *, struct gear_s *, struct item_s *, int);
    char *desc;
}item_t;

typedef struct gear_s { //ajouter un pointeur sur fonction pour un effet
    char *name;
    char *type;
    int dmg;
    int crit;
    int def;
    int force;
    int duration;
    int mode;
    int used;
    object_t *img;
    void (*func)(struct global_s *, struct gear_s *, struct item_s *, int);
    char *desc;
}gear_t;


typedef struct inventory_s {

    gear_t *armor;
    gear_t *spells[4];
    gear_t *slasher;
    gear_t *stunner;
    gear_t *ranger;

    item_t **items;
    gear_t **gears;
    int weapon; //0 slash //1 stun//2 range
    int spell_id;
}inventory_t;

typedef struct bar_s {
    float hp;
    float mn;
    float max_hp;
    float max_mn;
    sfText **texts;
    object_t **sprites;
    sfRectangleShape *inter;
    sfRectangleShape **life;
    sfRectangleShape **mana;
}bar_t;

typedef struct player_s {
    stats_t *stats;
    sfVector2f pos;
    sfVector2f velocity;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *idle_texture;
    sfVector2f offset;
    sfVector2i pffset;
    bar_t *bars;
    sfClock *pl_clock;
    int enemy_killed;
    int start_top_or;
    int start_left_idle;
    int start_top_idle;
    char *status;
    int xp;
    int xp_limit;
    int level;
    int nb_skill_pts;
    int skills[13]; // 10 à changer en fonction du nombre de compétences
    object_t *obj;
    int inventory_available_space;
    inventory_t *inv;
    statlist_t *status_list;
    sfRectangleShape *bounds;
} player_t;

typedef struct enemy_s {
    char *name;
    stats_t *stats;
    sfVector2f pos;
    int enemy_type;
    int level;
    object_t *obj;
    float xp_given;
    int dead;
    sfRectangleShape **hp_bar;
    statlist_t *status_list;
    sfVector2f offset;
    sfRectangleShape *bounds;
} enemy_t;

typedef struct dialogue_s {
    sfClock *clock;
    int current_letter;
    char **speech;
    int page;
    char ***tab;
    int nb_talks;
    int nb_talks_max;
    char *tmp_speech;
} dialogue_t;

typedef struct pnj_s {
    sfVector2f pos;
    object_t *pnj_obj;
    dialogue_t *dialogue;
    sfVector2f offset;
    int id;
    char *name;
} pnj_t;

typedef struct button_s {
    char *sprite_path;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i pos;
    sfRectangleShape *rect;
    sfVector2i size;
    void (*func)(struct global_s *); // fonction a executer quand active
    char *button_name;
    sfText *text;
} button_t;

typedef struct settings_s {
    int selected_button_index;
    int settings_index; // faites pas gaffe pour l'instant c pour moi
    int mouse_pressed;
    int mouse_hold;
    int mouse_released;
    float music_volume;
    float sfx_volume;
    int move_keys[8];
    int window_size_type;
    int is_fullscreen;
    int settings_active;
    sfMusic *main_music;
    button_t **settings_buttons;
    sfSprite *volume_sprite1;
    sfTexture *volume_texture1;
    sfSprite *volume_sprite2;
    sfTexture *volume_texture2;
    sfBool volume_mute;
    sfBool sfx_mute;
    sfIntRect rect;
} settings_t;

typedef struct animation_s {
    int is_active;
    sfVector2i cur_size;
    sfClock *clock;
} animation_t;

typedef struct menu_s {
    button_t **menu_buttons;
    sfBool mouse_pressed;
    sfBool mouse_hold;
    sfBool mouse_released;
    object_t *obj;
    object_t **name;
} menu_t;

typedef struct actions_s {
    button_t **spell;
    button_t **attacks;
    item_t **items;
}action_t;

typedef struct quest_s {
    int current_quest;
    char **quest_text;
    int current_pnj;
    int enemies_killed;
} quest_t;

typedef struct combat_s {
    sfRectangleShape **interface;
    action_t *action;
    button_t **button;
    enemy_t *curent_enemy;
    sfClock *clock;
    sfTime time;
    sfRectangleShape **trans;
    button_t **inv_cases;
    int index;
    sfText **quantity;
    sfText **description;
    sfVector2f combat_view;
    object_t *background;
    int active_attack;
    int active_spells;
    int active_inventory;
}combat_t;

typedef struct launch_s {
    object_t *load;
    object_t *logo;
    sfText *name;
    sfClock *clock;
    sfSound *sound;
}launch_t;

typedef struct map_s {
    int state_map;
    sfSprite *map_sprite;
    sfTexture *map_texture;
    sfIntRect map_rect;
    sfClock *map_clock;
}map_t;

typedef struct node_s {
    sfVector2f pos;
    int ID;
    int is_active;
    int status; // 0 disabled, 1 can be enabled, 2 enabled
    int cost;
    sfRectangleShape *rect; // for collision w/ mouse;
    struct node_s **next;
}node_t;

typedef struct global_s {
    int **map;
    int dialogue_active;
    int fighting;
    int selecting;
    button_t **save_ui_buttons;
    int save_ui_state;
    animation_t *animation;
    dialogue_t *dialogue;
    pnj_t *current_pnj; // pour load
    sfView *view;
    sfRenderWindow *window;
    settings_t *settings;
    sfClock *clock; // pour que la logique entiere soit basée sur la mm clock
    sfTime time; // pour avoir le temps passé de la clock;
    player_t *pl;
    combat_t *combat;
    button_t **buttons;
    enemy_t **enemies;
    pnj_t **pnj;
    menu_t *menu;
    sfClock *roam_clock;
    sfClock *animation_clock;
    sfBool state_game;
    sfBool state_menu;
    quest_t *quest;
    map_t *map_struct;
    sfSprite *load_sp[10];
    sfTexture *load_tx[10];
    sfSprite *map_sprites[10];
    sfTexture *map_tx[10];
    sfSprite *trans_sp[2];
    sfTexture *trans_tx[2];
    int transition_status;
    sfClock *transition_clock;
    sfRectangleShape *mouse_rect;
    sfView *minimap;
    sfSprite *save_bt_sp;
    sfTexture *save_bt_tx;
    sfText *save_ui_text;
    node_t **skill_nodes;
    sfRectangleShape *node_link;
    int node_status;

    ///----
    int inventory_state;
    int settings_state;
    object_t **select_tab;
    object_t **inventory_tab;
    object_t **settings_menu_tab;
    object_t **graphics_tab;
    object_t **audio_tab;
    object_t **controls_tab;
    sfText *inventory_text;
    sfText *skill_text;
    sfSprite *skill_sp;
    sfTexture *skill_tx;
    sfFont *regular_font;
    sfFont *startup_font;
    sfFont *karma_font;
    ///----
    sfText *button_text;
    int exit_program;
} global_t;

extern gear_t all_gears[];
extern item_t all_items[];
#endif

/*
** EPITECH PROJECT, 2024
** functions
** File description:
** functions
*/

#ifndef FUNC
    #define FUNC
    #include "include.h"
    #include "struct.h"
sfRenderWindow *window_create(int width, int height, int bPP, int framerate);
sfRenderWindow *window_create_fullscreen(int width,
    int height, int bPP, int framerate);

sfRectangleShape *create_rectangle(sfVector2f pos,
    sfVector2f size, sfColor color);
void show_sprite(sfRenderWindow *window, char *path,
    sfVector2f pos, sfVector2f scale);

void show_text(sfRenderWindow *window, char *str,
    sfVector3f dimensions, char *font_name);

void show_rect(sfRenderWindow *window, sfVector2f pos,
    sfColor color[2], sfVector3f dimensions);

void show_circle(sfRenderWindow *w, sfVector2f pos, float rad, sfColor color);
button_t *create_button(sfVector2i pos, sfVector2i size,
    void(*func)(global_t *), char *name);

int button_behavior(global_t *global, button_t **buttons, int index);
int manage_buttons(global_t *global, button_t **buttons);
button_t **init_settings_buttons(void);
void change_resolution_right(global_t *global);
void change_resolution_left(global_t *global);
void fullscreen_func(global_t *global);
void save_settings(global_t *global);
void go_to_video_settings(global_t *global);
void go_to_main_settings(global_t *global);
void go_to_game_settings(global_t *global);
void bind_up(global_t *global);
void bind_left(global_t *global);
void bind_right(global_t *global);
void bind_down(global_t *global);
void bind_interact(global_t *global);
void bind_select(global_t *global);
void go_to_control_settings(global_t *global);
void cleaner(global_t *global);
void tmp(global_t *global);
void bind_minimap(global_t *global);
void bind_confirm(global_t *global);


quest_t *init_quest(char *filepath);
map_t *init_map(void);
void manage_map(global_t *global);
void global_aux(global_t *global, sfVector2f pos);

void music_down(global_t *global);
void music_up(global_t *global);
void mute_volume(global_t *global);
void sfx_up(global_t *global);
void sfx_down(global_t *global);
void mute_sfx(global_t *global);

char *my_number_to_str(int nb);
char *float_to_str(float nb, int prec);
char *fileread(char *filepath);
char *my_strcat(char *dest, char *src, char *sep);
int my_strlen(char *str);
char **my_str_to_array(char *str, char *delim);
int my_tablen(char **tab);
char *my_strdup(char *src);
int is_str_equal(char *str, char *str1); // faut ajouter stcmp
void my_put(void *pointer, char type, int nb);
// char type:
// s pour str, c pour char, S pour char **, d pour nb et mettre "" pour le ptr

float get_angle(sfVector2i start, sfVector2i finish);
float get_a(sfVector2f pos1, sfVector2f pos2);
double get_distance(sfVector2i posA, sfVector2i posB);
int mouse_in_rect(global_t *global, sfRectangleShape *rectangle);

void display_player(global_t *global);
void show_map_matrix(global_t *global);
void init_global(global_t *global);
void manage_input_events(global_t *global); // au niveau des inputs
void manage_settings(global_t *global);
void manage_window_size(global_t *global);
void select_settings_page(global_t *global);
void settings_game(global_t *global);
void settings_video(global_t *global);
void show_settings_button(global_t *global, button_t **buttons);
void show_actual_res(global_t *global);
void show_video_icons(global_t *global);
void show_game_icons(global_t *global);
void show_volume(global_t *global);
void show_controls_icons(global_t *global);
void settings_controls(global_t *global);

void manage_highlight(global_t *global, button_t *actual_button);
int key_binder(global_t *global, int index);
void disp_controls_icon(global_t *global, int key_in_use);

settings_t *init_settings(void);
void manage_movement(global_t *global);
void finish_loop(global_t *global);
void manage_settings_buttons(global_t *global, button_t **buttons);

sfVector2i get_matrix_index_from_pos(sfVector2f pos);
void disp_matrix(int **matrix);
int **create_matrix(sfVector2i size);


void dialogue(global_t *global, dialogue_t *dialogue);
void init_current_tab(dialogue_t *dialogue);
void game_loop(global_t *global);

void manage_move(global_t *global);
void manage_movement(global_t *global);
void anim(global_t *gb, sfVector2i max_v);
void manage_view(global_t *global);
void init_dialogue(dialogue_t *dialogue, char *str);
pnj_t **init_pnj(void);
pnj_t *get_pnj_from_name(global_t *global, char *pnj_name);
void manage_pnj(global_t *global);
void wait_select(global_t *global);
void display_dialogue(global_t *global);

void display_main_menu(global_t *global);
button_t **init_main_menu_buttons(void);
void set_menu_sprite(menu_t *menu, button_t **buttons);
void settings_button_behavior(global_t *global, button_t **buttons, int index);
void settings_button_behavior_bis(global_t *global
    , button_t **buttons, int index);
void attack(global_t *global);
void defense(global_t *global);
void spells(global_t *global);
void combat_inventory(global_t *global);
void combat_hud(global_t *global);
sfText *create_text(char const *name, char *filepath,
    sfVector2f pos, sfColor color);
sfIntRect create_rect(int left, int top, int w, int h);
void lauch_animation(global_t *global, object_t *obj, int size, int iteration);
object_t *create_object(char *name, sfVector2f scaling, sfVector2f pos,
    sfIntRect rect);
enemy_t **init_enemy(void);
void transition(global_t *gl);
void transition2(global_t *gl);
sfText **status_bar(global_t *global);
action_t *init_action(global_t *global);
void display_attack(global_t *gl);
void disp_actions(global_t *gl, combat_t *combat);
void display_spells(global_t *gl);
void enemy_turn(global_t *gl);
void enemy_disp(global_t *gl);
gear_t *set_gear(gear_t *gear, gear_t *gear_2);
item_t *set_items(item_t *items, item_t *items_2);
void open_inv(global_t *global);
void use(global_t *global, item_t *item, gear_t *gear);
status_t *reset_status(void);
statlist_t *init_status(statlist_t *statlist);
int my_strcmp(char const *s1, char const *s2);
int delete_items(inventory_t *inv, item_t *target, int nbr);
void add_item(inventory_t *inv, item_t *new, int nbr);
void add_gear(inventory_t *inv, gear_t *new);
int delete_gear(inventory_t *inv, gear_t *target);
item_t *reset_item(item_t *items);
void disp_test(inventory_t *inv);
void display_quest(global_t *global);
void manage_quest(global_t *global);
void go_to_main_menu(global_t *global);
item_t *get_item(char *name);
gear_t *get_gear(char *name);
inventory_t *init_inventory(player_t *player);
sfRectangleShape **init_transition(void);
void init_combat_bis(global_t *global, combat_t *c);
combat_t *init_combat(global_t *global);
void create_save(global_t *global, int slot);
void loader(global_t *global, int slot);
void load_player(global_t *global, char **content);
void load_pnj(global_t *global, char **content);
void load_inventory(global_t *global, char **content);
void load_enemy(global_t *global, char **content);
void mini_cleaner(char *str, char **tab);
void save_ui(global_t *global);

void button_load(global_t *global);
void button_save(global_t *global);
void quit_save_ui(global_t *global);
void main_ui(global_t *global);
void save_slot_1(global_t *global);
void save_slot_2(global_t *global);
void save_slot_3(global_t *global);
void load_man_save_1(global_t *global);
void load_man_save_2(global_t *global);
void load_man_save_3(global_t *global);
void load_auto_save_1(global_t *global);
void load_auto_save_2(global_t *global);
void load_auto_save_3(global_t *global);
void save_gb_bt(global_t *global);
void start_up(global_t *gl);
void roam_enemy(global_t *global, pnj_t **pnj);

void bars_bis(player_t *pl);
void animate_player(global_t *gl);
void apply_status(global_t *gl);
void effect_of_status(global_t *gl, statlist_t *statlist, stats_t *stats);
stats_t *set_stats(void);
stats_t *set_pl_stat(stats_t *stats);
void defense(global_t *global);
int launch_attack(global_t *global, stats_t *bully, stats_t *target);
void open_inv(global_t *global);
void use(global_t *global, item_t *item, gear_t *gear);
void use_all_eq(global_t *global);
void equip(global_t *global, gear_t *gear);
void heal(struct global_s *global, gear_t *gear, item_t *item, int mode);
void heal_percent(struct global_s *global, gear_t *gear,
    item_t *item, int mode);
void reco_mana(struct global_s *global, gear_t *gear,
    item_t *item, int mode);
void reco_mana_percent(struct global_s *global, gear_t *gear,
    item_t *item, int mode);
void freeze_or_burn(struct global_s *global, gear_t *gear,
    item_t *item, int mode);
void apply_burn(struct global_s *global, gear_t *gear, item_t *item, int mode);
void apply_poison(struct global_s *global, gear_t *gear,
    item_t *item, int mode);
void apply_para(struct global_s *global, gear_t *gear, item_t *item, int mode);
void apply_frozen(struct global_s *global, gear_t *gear,
    item_t *item, int mode);
void para(global_t *gl, statlist_t *statlist, stats_t *stats);
void freeze(global_t *gl, statlist_t *statlist, stats_t *stats);
void atk_change(global_t *gl, statlist_t *statlist, stats_t *stats);
void def_change(global_t *gl, statlist_t *statlist, stats_t *stats);
void atk_buff(struct global_s *global, gear_t *gear, item_t *item, int mode);
void def_buff(struct global_s *global, gear_t *gear, item_t *item, int mode);
gear_t *gear_from_inv(global_t *gl, char *name);
item_t *item_from_inv(global_t *gl, char *name);
int get_random_id(int a, int b);
item_t *get_random_item(int a, int b);
void xp_up(global_t *global);

int get_ratio(int val, int max_val, int x);
void init_combat_inventory(global_t *global, combat_t *combat);

void hud_aux(global_t *global);
void spells_1(global_t *gl);
void spells_2(global_t *gl);
void spells_3(global_t *gl);
void spells_4(global_t *gl);

void create_load_sprite(global_t *global);
void display_bg_load(global_t *global);
int **parse_collision_csv(void);
void start_transition(global_t *global, sfClock *clock);
void mouse(global_t *global);
void display_save_ui_load(global_t *global, sfText *text);
void display_save_ui_save(global_t *global, sfText *text);
void display_save_ui_menu(global_t *global, sfText *text);
node_t **init_nodes(void);
void skill_tree_loop(global_t *global, node_t **nodes);
gear_t *un_gear(gear_t *gear);
void add_item(inventory_t *inv, item_t *new, int nbr);
void add_gear(inventory_t *inv, gear_t *new);
item_t *un_item(item_t *items);
void inventory_ui(global_t *global);
void init_inventory_ui(global_t *global);
void display_glow(global_t *global, sfVector2f size, sfVector2f pos);
void anim_idle(global_t *gb);
void init_save_ui(global_t *global);
void init_rpg(global_t *global);
void init_skill_tree(global_t *global);
void init_inventory_tab(global_t *global);
void init_map_bg(global_t *global);
void *my_malloc(size_t size);
void manage_select_obj(global_t *global, int index);
void manage_settings_obj(global_t *global);
void display_settings_text(global_t *global);
void display_inventory_settings(global_t *global);
object_t **create_inventory_obj(void);
object_t **create_inventory_select(void);
object_t *create_inv_obj(sfVector2f pos, sfVector2f size,
    void (*func)(struct global_s *));
object_t **create_inventory_settings_audio(void);
object_t **create_inventory_settings_controls(void);
object_t **create_inventory_settings_graphics(void);
object_t **create_inventory_settings_menu(void);

void control_state(global_t *global);
void audio_state(global_t *global);
void graphics_state(global_t *global);
void state_6(global_t *global);
void tmp(global_t *global);
void state_1(global_t *global);
void state_2(global_t *global);
void state_3(global_t *global);
void state_4(global_t *global);
void state_5(global_t *global);
void display_text(global_t *global, sfVector2f pos, int size, char *str);
void attack_s(global_t *gl);
void attack_r(global_t *gl);
void display_inventory(global_t *gl);
void display_enemies(global_t *global);
#endif

/*
** EPITECH PROJECT, 2024
** skill
** File description:
** tree
*/

#include "include/include.h"

void display_line(sfRenderWindow *window, sfRectangleShape *rect,
    sfVector2f pos1, sfVector2f pos2)
{
    sfVector2i pos_1 = {pos1.x, pos1.y};
    sfVector2i pos_2 = {pos2.x, pos2.y};
    sfVector2f size = {get_distance(pos_1, pos_2), 3};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos1);
    sfRectangleShape_setRotation(rect,
    get_angle((sfVector2i){pos1.x, pos1.y}, (sfVector2i){pos2.x, pos2.y}));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
}

void verify_big_node(sfRectangleShape *rect, node_t **nodes)
{
    if (nodes[12]->is_active == 1) {
        nodes[12]->status = 2;
        sfRectangleShape_setFillColor(rect, sfGreen);
        return;
    }
    nodes[12]->status = 0;
    sfRectangleShape_setFillColor(rect, sfTransparent);
    if (nodes[4]->is_active && nodes[5]->is_active &&
    nodes[10]->is_active && nodes[11]->is_active) {
        nodes[12]->status = 1;
        sfRectangleShape_setFillColor(rect, sfYellow);
    }
}

void manage_node_link(global_t *global, node_t *node1, node_t *node2)
{
    if (node1->is_active && !node2->is_active &&
    global->pl->nb_skill_pts < node1->cost) {
        node2->status = 1;
        sfRectangleShape_setFillColor(global->node_link, sfTransparent);
    }
    if (node1->is_active && !node2->is_active &&
    global->pl->nb_skill_pts >= node1->cost) {
        node2->status = 1;
        sfRectangleShape_setFillColor(global->node_link, sfYellow);
    }
    if (node1->is_active && node2->is_active) {
        node2->status = 2;
        sfRectangleShape_setFillColor(global->node_link, sfGreen);
    }
    if (!node1->is_active && !node2->is_active) {
        node2->status = 0;
        sfRectangleShape_setFillColor(global->node_link, sfTransparent);
    }
}

static void verify_node(global_t *global, node_t *cur_node)
{
    for (int j = 0; cur_node->next[j]; j++) {
        manage_node_link(global, cur_node, cur_node->next[j]);
        if (global->skill_nodes[12] == cur_node->next[j])
            verify_big_node(global->node_link, global->skill_nodes);
        display_line(global->window, global->node_link, cur_node->pos,
        cur_node->next[j]->pos);
    }
}

static void verify_all_nodes(global_t *global)
{
    for (int i = 0; global->skill_nodes[i]; i++) {
        verify_node(global, global->skill_nodes[i]);
        sfRenderWindow_drawRectangleShape(global->window,
        global->skill_nodes[i]->rect, NULL);
        sfSprite_setPosition(global->skill_sp, global->skill_nodes[i]->pos);
        sfRenderWindow_drawSprite(global->window, global->skill_sp, NULL);
        if (mouse_in_rect(global, global->skill_nodes[i]->rect))
            sfText_setString(global->skill_text, skill_desc[i]);
        sfRenderWindow_drawText(global->window, global->skill_text, NULL);
    }
}

static void show_ui(global_t *global)
{
    show_rect(global->window, (sfVector2f){330, 50},
    (sfColor[2]){sfColor_fromRGBA(0, 0, 0, 180),
    sfColor_fromRGB(180, 180, 180)}, (sfVector3f){1540, 680, 2});
    show_rect(global->window, (sfVector2f){330, 750},
    (sfColor[2]){sfColor_fromRGBA(0, 0, 0, 180),
    sfColor_fromRGB(180, 180, 180)}, (sfVector3f){1540, 250, 2});
}

void skill_tree_loop(global_t *global, node_t **nodes)
{
    sfRenderWindow_clear(global->window, sfBlack);
    show_sprite(global->window, "rs/Save_Menu_bg.png", (sfVector2f){0, 0},
    (sfVector2f){1.5, 1.5});
    show_ui(global);
    for (int i = 0; nodes[i]; i++) {
        if (mouse_in_rect(global, nodes[i]->rect) &&
        global->settings->mouse_pressed
        && nodes[i]->status == 1 &&
        global->pl->nb_skill_pts >= nodes[i]->cost) {
            global->pl->nb_skill_pts -= nodes[i]->cost;
            nodes[i]->is_active = 1;
        }
    }
    verify_all_nodes(global);
    mouse(global);
    for (int i = 0; i < 13; i++)
        global->pl->skills[i] = nodes[i]->is_active;
}

/*
** EPITECH PROJECT, 2024
** nodes
** File description:
** nodes
*/

#include "include/include.h"

static node_t *create_node(sfVector2f pos, int ID, int nb_next, int cost)
{
    node_t *node = my_malloc(sizeof(node_t));

    node->pos = pos;
    node->status = 0;
    node->ID = ID;
    node->is_active = 0;
    node->cost = cost;
    node->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(node->rect, pos);
    sfRectangleShape_setFillColor(node->rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setOrigin(node->rect, (sfVector2f){25, 25});
    sfRectangleShape_setSize(node->rect, (sfVector2f){50, 50});
    sfRectangleShape_setOutlineThickness(node->rect, 0);
    node->next = my_malloc(sizeof(node_t *) * nb_next + 1);
    return node;
}

void init_links_bis(node_t **nodes)
{
    nodes[6]->next[0] = nodes[7];
    nodes[6]->next[1] = NULL;
    nodes[7]->next[0] = nodes[8];
    nodes[7]->next[1] = nodes[9];
    nodes[7]->next[2] = NULL;
    nodes[8]->next[0] = nodes[10];
    nodes[8]->next[1] = NULL;
    nodes[9]->next[0] = nodes[11];
    nodes[9]->next[1] = NULL;
    nodes[10]->next[0] = nodes[12];
    nodes[10]->next[1] = NULL;
    nodes[11]->next[0] = nodes[12];
    nodes[11]->next[1] = NULL;
    nodes[12]->next[0] = NULL;
}

void init_links(node_t **nodes)
{
    nodes[0]->next[0] = nodes[1];
    nodes[0]->next[1] = NULL;
    nodes[1]->next[0] = nodes[2];
    nodes[1]->next[1] = nodes[3];
    nodes[1]->next[2] = NULL;
    nodes[2]->next[0] = nodes[4];
    nodes[2]->next[1] = NULL;
    nodes[3]->next[0] = nodes[5];
    nodes[3]->next[1] = NULL;
    nodes[4]->next[0] = nodes[12];
    nodes[4]->next[1] = NULL;
    nodes[5]->next[0] = nodes[12];
    nodes[5]->next[1] = NULL;
    init_links_bis(nodes);
}

void init_nodes_bis(node_t **nodes)
{
    nodes[8] = create_node((sfVector2f){1000, 450}, 0, 1, 2);
    nodes[9] = create_node((sfVector2f){1000, 650}, 0, 1, 2);
    nodes[10] = create_node((sfVector2f){1500, 450}, 0, 1, 2);
    nodes[11] = create_node((sfVector2f){1500, 650}, 0, 1, 2);
    nodes[12] = create_node((sfVector2f){1700, 387.5f}, 0, 1, 7);
    nodes[13] = NULL;
    nodes[0]->is_active = 1;
    nodes[6]->is_active = 1;
    init_links(nodes);
}

node_t **init_nodes(void)
{
    node_t **nodes = my_malloc(sizeof(node_t *) * 14);

    nodes[0] = create_node((sfVector2f){400, 225}, 0, 1, 1);
    nodes[1] = create_node((sfVector2f){600, 225}, 0, 2, 1);
    nodes[2] = create_node((sfVector2f){1000, 125}, 0, 1, 2);
    nodes[3] = create_node((sfVector2f){1000, 325}, 0, 1, 2);
    nodes[4] = create_node((sfVector2f){1500, 125}, 0, 1, 2);
    nodes[5] = create_node((sfVector2f){1500, 325}, 0, 1, 2);
    nodes[6] = create_node((sfVector2f){400, 550}, 0, 1, 1);
    nodes[7] = create_node((sfVector2f){600, 550}, 0, 2, 1);
    init_nodes_bis(nodes);
    return nodes;
}

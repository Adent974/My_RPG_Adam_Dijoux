/*
** EPITECH PROJECT, 2024
** inv
** File description:
** inv
*/

#include "include/include.h"

object_t *create_inv_obj(sfVector2f pos, sfVector2f size,
    void (*func)(struct global_s *))
{
    object_t *object = my_malloc(sizeof(object_t));

    object->pos = pos;
    object->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(object->shape, size);
    sfRectangleShape_setOutlineColor(object->shape,
    sfColor_fromRGB(180, 180, 180));
    sfRectangleShape_setFillColor(object->shape,
    sfColor_fromRGBA(0, 0, 0, 180));
    sfRectangleShape_setOutlineThickness(object->shape, 2);
    sfRectangleShape_setPosition(object->shape, object->pos);
    object->func = func;
    return object;
}

object_t **create_inventory_select(void)
{
    object_t **tab = my_malloc(sizeof(object_t *) * 7);

    tab[0] = create_inv_obj((sfVector2f){30, 30},
    (sfVector2f){250, 170}, &state_1);
    tab[1] = create_inv_obj((sfVector2f){30, 200},
    (sfVector2f){250, 170}, &state_2);
    tab[2] = create_inv_obj((sfVector2f){30, 370},
    (sfVector2f){250, 170}, &state_3);
    tab[3] = create_inv_obj((sfVector2f){30, 540},
    (sfVector2f){250, 170}, &state_4);
    tab[4] = create_inv_obj((sfVector2f){30, 710},
    (sfVector2f){250, 170}, &state_5);
    tab[5] = create_inv_obj((sfVector2f){30, 880},
    (sfVector2f){250, 170}, &state_6);
    tab[6] = NULL;
    return tab;
}

object_t **create_inventory_obj(void)
{
    object_t **tab = my_malloc(sizeof(object_t *) * 20);

    tab[0] = create_inv_obj((sfVector2f){310, 0},
    (sfVector2f){710, 250}, NULL);
    tab[1] = create_inv_obj((sfVector2f){700, 370},
    (sfVector2f){1160, 220}, NULL);
    for (int i = 2; i < 10; i++)
        tab[i] = create_inv_obj((sfVector2f)
        {835 + ((i - 2)) * 125 + (i - 9) * 15, 415},
        (sfVector2f){125, 125}, NULL);
    tab[10] = create_inv_obj((sfVector2f){700, 670},
    (sfVector2f){1160, 220}, NULL);
    for (int i = 11; i < 19; i++)
        tab[i] = create_inv_obj((sfVector2f)
        {940 + ((i - 12)) * 125 + (i - 17) * 15, 710},
        (sfVector2f){125, 125}, NULL);
    tab[19] = NULL;
    return tab;
}

/*
** EPITECH PROJECT, 2024
** matrix
** File description:
** index
*/

#include "include/include.h"

sfVector2i get_matrix_index_from_pos(sfVector2f pos)
{
    sfVector2i final;

    final.x = pos.x / 60.0;
    final.y = pos.y / 60.0;
    if (pos.x < 0)
        final.x = 0;
    if (pos.y < 0)
        final.y = 0;
    if (pos.y > 8990)
        final.y = 149;
    if (pos.x > 11990)
        final.x = 199;
    return final;
}

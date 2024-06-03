/*
** EPITECH PROJECT, 2024
** malloc
** File description:
** malloc
*/

#include "include/include.h"

void *my_malloc(size_t size)
{
    void *ptr = NULL;

    ptr = malloc(size);
    if (!ptr) {
        dprintf(2, "Allocation Failed\n");
        exit(84);
    }
    return ptr;
}

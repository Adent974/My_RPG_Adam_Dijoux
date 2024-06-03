/*
** EPITECH PROJECT, 2024
** mini cleaner
** File description:
** mini cleaner
*/

#include <stdlib.h>

void mini_cleaner(char *str, char **tab)
{
    free(str);
    for (int i = 0; tab[i]; free(tab[i++]));
    free(tab);
}

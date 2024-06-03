/*
** EPITECH PROJECT, 2024
** include
** File description:
** include
*/

#include "include/include.h"

int *fill_line(char *line)
{
    char *tmp = strdup(line);
    char **tab = my_str_to_array(tmp, ",");
    int *matrix = my_malloc(sizeof(int) * (my_tablen(tab) + 1));
    int i = 0;

    for (i = 0; tab[i]; i++)
        matrix[i] = atoi(tab[i]);
    matrix[i] = -42;
    return matrix;
}

int **parse_collision_csv(void)
{
    char *buffer = fileread("rs/map/Collision.csv");
    char **tab = my_str_to_array(buffer, "\n");
    int **matrix = my_malloc(sizeof(int *) * my_tablen(tab) + 1);
    int i = 0;

    for (i = 0; tab[i]; i++) {
        matrix[i] = fill_line(tab[i]);
    }
    matrix[i] = NULL;
    free(buffer);
    return matrix;
}

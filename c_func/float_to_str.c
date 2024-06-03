/*
** EPITECH PROJECT, 2024
** float to str
** File description:
** float to str
*/

#include "../include/include.h"

char *get_dec_part(float dec, int nb2, int prec)
{
    char *number = my_malloc(sizeof(char) * (prec + 1));
    int i = 0;

    number[0] = '\0';
    for (; i < prec; i++) {
        dec *= 10;
        nb2 = dec;
        dec -= nb2;
        number[i] = (nb2 % 10) + '0';
    }
    number[i] = '\0';
    return number;
}

char *float_to_str(float nb, int prec)
{
    int nb2;
    char *number;
    int neg = 0;
    char *res = NULL;

    if (nb < 0) {
        neg++;
        nb *= -1;
    }
    nb2 = nb;
    res = my_number_to_str(nb2);
    if (prec == 0)
        return res;
    number = get_dec_part(nb - nb2, nb2, prec);
    res = my_strcat(res, number, ".");
    if (neg != 0)
        res = my_strcat("-", res, "");
    free(number);
    return res;
}

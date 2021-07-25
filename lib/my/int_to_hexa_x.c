/*
** EPITECH PROJECT, 2019
** int_to_hexa.C
** File description:
** function that convert int to hexa
*/

#include "my.h"

int int_to_hexa_x(int nb)
{
    char *str = "0123456789abcdef";

    if (nb <= 15)
        my_putchar(str[nb]);
    else if (nb > 0) {
        int_to_hexa_x(nb / 16);
        int_to_hexa_x(nb % 16);
    }
    return (nb);
}

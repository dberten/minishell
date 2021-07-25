/*
** EPITECH PROJECT, 2019
** int_to_hexa.C
** File description:
** function that convert int to hexa
*/

#include "my.h"

int int_to_hexa_maj(int nb)
{
    char *str = "0123456789ABCDEF";
    if (nb <= 15)
        my_putchar(str[nb]);
    else if (nb > 0) {
        int_to_hexa_maj(nb / 16);
        int_to_hexa_maj(nb % 16);
    }
    return (nb);
}

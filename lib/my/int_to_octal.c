/*
** EPITECH PROJECT, 2019
** int_to_octal
** File description:
** function that converts int into octal
*/
#include "my.h"

int int_to_octal(int nb)
{
    if (nb <= 8)
    {
        my_putchar(nb + '0');
    }
    else if (nb > 0) {
        int_to_octal( nb / 8 );
        my_putchar((nb % 8) + '0');
    }
    return (nb);
}


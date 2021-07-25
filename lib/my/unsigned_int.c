/*
** EPITECH PROJECT, 2019
** unsigned_int
** File description:
** my_printf unsigned int$
*/

#include "my.h"

unsigned int unsigned_int(unsigned int nb)
{
    if (nb > 0) {
        unsigned_int( nb / 10 );
        my_putchar((nb % 10) + '0');
    }
    return (nb);
}


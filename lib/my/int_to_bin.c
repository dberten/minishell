/*
** EPITECH PROJECT, 2019
** int_to_bin
** File description:
** convert int to binary
*/
#include "my.h"

unsigned int int_to_bin(unsigned int nb)
{
    if (nb <= 1)
    {
        my_putchar(nb + '0');
    }
    else if (nb > 0) {
        int_to_bin(nb / 2 );
        my_putchar(nb % 2 + '0');
    }
    return (nb);
}

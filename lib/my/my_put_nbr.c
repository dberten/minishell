/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar ('-');
        my_put_nbr((nb / 10) * (-1) + '0');
        my_putchar(((nb % 10) * (-1)) + '0');
    }
    else if (nb <= -10) {
        my_putchar('-');
        my_put_nbr((nb / 10) * (-1));
        my_putchar((nb % 10) * (-1) + '0');
    }
    else if (nb > 0) {
        my_put_nbr( nb / 10 );
        my_putchar((nb % 10) + '0');
    }
    return (nb);
}

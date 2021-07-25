/*
** EPITECH PROJECT, 2019
** print_add_ptr
** File description:
** function that print the address of a pointer
*/
#include "my.h"

long int print_add_ptr(long int nb)
{
    char str[] = "0123456789abcdef";

    if (nb > 16) {
        print_add_ptr(nb / 16);
        print_add_ptr(nb % 16);
    }
    else if (nb < 16)
        my_putchar(str[nb]);
    return (nb);
}

void adress(long int nb)
{
    my_putstr("0x");
    print_add_ptr(nb);
}

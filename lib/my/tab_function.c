/*
** EPITECH PROJECT, 2019
** tab_function
** File description:
** function that initit function
*/

#include "my.h"

void init_function(void(**contain)())
{
    contain[0] = (void *) &my_putchar;
    contain[1] = (void *) &my_put_nbr;
    contain[2] = (void *) &my_put_nbr;
    contain[3] = (void *) &my_putstr;
    contain[4] = (void *) &int_to_hexa_x;
    contain[5] = (void *) &int_to_hexa_maj;
    contain[6] = (void *) &int_to_octal;
    contain[7] = (void *) &int_to_bin;
    contain[8] = (void *) &unsigned_int;
    contain[9] = (void *) &adress;
}

/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** function my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void init_function(void(**contain)());

int check_flags(char s)
{
    char str[10] = "cidsxXobup";
    int i = 0;

    while (str[i] != '\0') {
        if (s == str[i])
            return (i);
        i++;
    }
    return (84);
}

int my_printf(char *s, ...)
{
    va_list list;
    void (*contain[10])();
    int i = 0;

    init_function(contain);
    va_start(list, s);
    while (s[i] != '\0') {
        if (s[i] == '%') {
            i++;
            contain[check_flags(s[i])](va_arg(list, void *));
        }
        else
            my_putchar(s[i]);
        i++;
    }
    va_end(list);
    return (0);
}


/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** reproduce the behavior of the my_strcmp function
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] != '\0')
        a++;
    return (s1[a] - s2[a]);
}

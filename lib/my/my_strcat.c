/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int rep = my_strlen(src);
    char *tmp = malloc(sizeof(char) * (dest_len + rep + 1));
    int i = 0;
    int j = 0;

    for (; dest[i] ; i++)
        tmp[i] = dest[i];
    for (; src[j] ; j++)
        tmp[i + j] = src[j];
    tmp[i + j] = 0;
    return (tmp);
}
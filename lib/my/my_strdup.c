/*
** EPITECH PROJECT, 2024
** PSU_my_ls_2019
** File description:
** Created by Dorian Berten
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    char *contain = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i] != '\0'; i++) {
        contain [i] = str[i];
    }
    contain[i] = '\0';
    return (contain);
}
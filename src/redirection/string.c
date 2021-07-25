/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int coord_chevron(char *str, int i)
{
    int tmp = 0;

    for (; str[i]; i++) {
        if (str[i] == '>' || str[i] == '<')
            tmp = 1;
    }
    if (tmp == 1) {
        for (i = 0; str[i] != '>' && str[i] != '<'; i++);
        return (i);
    }
    return (0);
}

char *get_files(char *str)
{
    int i = 0;
    int rep = 0;

    while (str[i] != '>' && str[i] != '<')
        char_remove(i, str);
    while (str[i] == '>' || str[i] == '<')
        char_remove(i, str);
    rep = coord_chevron(str, 0);
    if (rep != 0) {
        while (str[rep] == '>' || str[rep] == '<')
            char_remove(rep, str);
    }
    return (str);
}

char *nice_string(char *str)
{
    for (int i =  0; str[i]; i++) {
        if (str[i] == '\n')
            str[i] = str[i + 1];
    }
    return (str);
}
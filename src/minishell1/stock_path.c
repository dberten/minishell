/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

char *cut_str(char *str)
{
    int i = 0;

    for (; str[i] != '='; i++);
    str = &str[i + 1];
    return (str);
}
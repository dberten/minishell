/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int my_exec(main_struct_t *main_struct, char **tab)
{
    int rep = 0;

    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++)
            if (tab[i][j] == '/') {
                break;
            }
    }
    rep = my_fork(tab[0], main_struct, tab);
    return (rep);
}


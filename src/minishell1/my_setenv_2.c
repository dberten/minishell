/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int manage_all_case(modif_t *modif, char **tab)
{
    int size  = 0;

    for (; tab[size]; size++);
    if (size == 1) {
        print_tab(modif->env_tab);
        return (0);
    }
    modif->env_tab = mult_arg(modif, tab, size);
    return (0);
}
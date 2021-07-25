/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int condition_cd(modif_t *modif, char **tab)
{
    if (cd_mult(modif, tab) == 0)
        return (0);
    modif->return_value = 1;
    return (modif->return_value);
}

int parse_cd(modif_t *modif, char **tab)
{
    if (tab[1] && my_strcmp(tab[1], "~"))
        return (condition_cd(modif, tab));
    else if (!my_strcmp(tab[0], "cd") ||
        !my_strcmp(tab[1], "~")) {
        if (my_simple_cd(modif) == 1) {
            modif->return_value = 1;
            return (1);
        }
        return (0);
    }
    return (0);
}
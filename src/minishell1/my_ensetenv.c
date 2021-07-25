/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int find_variable(char *str, modif_t *modif)
{
    int len = my_strlen(str);

    for (int i = 0; modif->env_tab[i] != NULL; i++)
        if (my_strncmp(str, modif->env_tab[i], len) == 0)
            return (i);
    return (0);
}

void decall_str(char **tab, int nb)
{
    for (; tab[nb]; nb++)
        tab[nb] = tab[nb + 1];
}

int remove_variable(modif_t *modif, char *str)
{
    int len = my_strlen(str);

    for (int i = 0; modif->env_tab[i]; i++) {
        if (my_strncmp(modif->env_tab[i], str, len) == 0
        && modif->env_tab[i][len] == '=') {
            decall_str(modif->env_tab, i);
        }
    }
    return (0);
}

int my_unsetenv(modif_t *modif, char **tab)
{
    int size = 0;

    for (; tab[size]; size++);
    if (size == 1) {
        write(2, "unsetenv: Too few arguments\n", 29);
        return (1);
    }
    for (int i = 1; tab[i]; i++)
        remove_variable(modif, tab[i]);
    return (0);
}
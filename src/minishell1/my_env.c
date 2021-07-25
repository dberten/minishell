/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "my.h"
#include "mysh.h"

int size_env(char **envp)
{
    int i = 0;

    for (; envp[i]; i++);
    return (i);
}

int error_env(char **tab)
{
    int size = 0;

    for (; tab[size]; size++);
    if (size == 2) {
        my_printf("env: '%s': No such file or directory\n", tab[1]);
        return (127);
    }
    return (0);
}

int env_tab(modif_t *modif, char **envp)
{
    int i = 0;

    if (envp == NULL)
        return (1);
    modif->env_tab = malloc(sizeof(char *) * (size_env(envp) + 1));
    if (modif->env_tab == NULL)
        return (84);
    for (; envp[i]; i++) {
        modif->env_tab[i] = malloc(sizeof(char) * (my_strlen(envp[i]) + 1));
        modif->env_tab[i] = my_strdup(envp[i]);
    }
    modif->env_tab[i] = NULL;
    return (0);
}
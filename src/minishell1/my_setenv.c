/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"
#include "my.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
}

char *fuse_str(char *sa, char *sb)
{
    char *str = my_strcat(sa, "=");

    if (sb)
        str = my_strcat(str, sb);
    return (str);
}

char **last_line(modif_t *modif, char **tab, int size)
{
    int i = 0;
    char **setenv_tab = malloc(sizeof(char *) * (size_env(modif->env_tab) + 2));

    for (; modif->env_tab[i]; i++)
        setenv_tab[i] = my_strdup(modif->env_tab[i]);
    if (size == 2)
        setenv_tab[i] = fuse_str(tab[1], NULL);
    else
        setenv_tab[i] = fuse_str(tab[1], tab[2]);
    setenv_tab[i + 1] = NULL;
    modif->env_tab = setenv_tab;
    return (setenv_tab);
}

char *condition_modif(modif_t *modif, char **tab, int size)
{
    int nb = find_variable(tab[1], modif);

    if (nb != 0) {
        if (size == 2)
            modif->env_tab[nb] = fuse_str(tab[1], NULL);
        else
            modif->env_tab[nb] = fuse_str(tab[1], tab[2]);
    }
    return (modif->env_tab[nb]);
}

char **mult_arg(modif_t  *modif, char **tab, int size)
{
    int len = my_strlen(tab[1]);

    for (int i = 0; modif->env_tab[i]; i++) {
        if (my_strncmp(tab[1], modif->env_tab[i], len) == 0
        && modif->env_tab[i][len] == '=') {
            modif->env_tab[i] = condition_modif(modif, tab, size);
            return (modif->env_tab);
        }
    }
    modif->env_tab = last_line(modif, tab, size);
    return (modif->env_tab);
}


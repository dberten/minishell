/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int my_simple_cd(modif_t *modif)
{
    char *home = find_var("HOME=", modif);
    char *old = NULL;

    if (home == NULL)
        return (1);
    old = getcwd(NULL, 0);
    for (int j = 0; modif->env_tab[j]; j++) {
        if (my_strncmp("OLDPWD=", modif->env_tab[j], 7) == 0)
            modif->env_tab[j] = my_strcat("OLDPWD=", old);
    }
    chdir(home);
    for (int j = 0; modif->env_tab[j]; j++) {
        if (my_strncmp("PWD=", modif->env_tab[j], 4) == 0)
            modif->env_tab[j] = my_strcat("PWD=",
                getcwd(NULL, 0));
    }
    return (0);
}

char *concat_str(char *str, char **tab)
{
    str = my_strcat(str, "/");
    str = my_strcat(str, tab[1]);
    return (str);
}

int my_mult_cd(modif_t *modif, char **tab)
{
    char *str = NULL;
    char *str1 = NULL;
    char *old = NULL;
    int tmp = 0;

    old = getcwd(NULL, 0);
    str = getcwd(NULL, 0);
    for (int j = 0; modif->env_tab[j]; j++) {
        if (my_strncmp("OLDPWD=", modif->env_tab[j], 7) == 0)
            modif->env_tab[j] = my_strcat("OLDPWD=", old);
        if (my_strncmp("PWD=", modif->env_tab[j], 4) == 0) {
            str = concat_str(str, tab);
            tmp = condition_error_cd(str, str1, tab);
            modif->env_tab[j] = my_strcat("PWD=",
                getcwd(NULL, 0));
        }
    }
    if (tmp == 1)
        return (1);
    return (0);
}

int my_dash_cd(modif_t *modif)
{
    char *oldpwd = find_var("OLDPWD=", modif);
    char *old = getcwd(NULL, 0);

    if (oldpwd == NULL)
        return (1);
    chdir(oldpwd);
    for (int j = 0; modif->env_tab[j]; j++) {
        if (my_strncmp("OLDPWD=", modif->env_tab[j], 7) == 0) {
            modif->env_tab[j] = my_strcat("OLDPWD=", old);
        }
    }
    for (int j = 0; modif->env_tab[j]; j++) {
        if (my_strncmp("PWD=", modif->env_tab[j], 4) == 0)
            modif->env_tab[j] = my_strcat("PWD=", getcwd(NULL, 0));
    }
    return (0);
}
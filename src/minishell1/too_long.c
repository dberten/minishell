/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "../include/mysh.h"

void error_exec(char **tab)
{
    char *str = NULL;

    str = my_strcat(tab[0], ": ");
    str = my_strcat(str, strerror(errno));
    str = my_strcat(str, ".\n");
    if (!my_strcmp(strerror(errno), "Exec format error"))
        str = my_strcat(str, "Wrong Architecture.\n");
    write(2, str, my_strlen(str));
    exit(1);
}

int condition_error_cd(char *str, char *str1, char **tab)
{
    char *tmp = NULL;

    if (len_tab(tab) > 2) {
        write(2, "cd: Too many arguments.\n", 25);
        return (1);
    }
    if (chdir(str) ==  -1) {
        str1 = strerror(errno);
        tmp = my_strcat(tab[1], ": ");
        str1 = my_strcat(tmp, str1);
        str1 = my_strcat(str1, ".\n");
        write(2, str1, my_strlen(str1));
        return (1);
    }
    return (0);
}

int error_alpha_setenv(char **tab)
{
    for (int j = 1; tab[1][j]; j++) {
        if (is_alpha(tab[1][j]) == 0 && tab[1][j] != '.' &&
            tab[1][j] != '_')
            return (1);
    }
    return (0);
}

int cd_mult(modif_t *modif, char **tab)
{
    if (!my_strcmp(tab[1], "-"))
        my_dash_cd(modif);
    else
        if (my_mult_cd(modif, tab) == 1)
            return (1);
    return (0);
}

int get_return(int status)
{
    int rep = WTERMSIG(status);
    char *tmp = NULL;

    if (WIFSIGNALED(status)) {
        tmp = strsignal(rep);
        if (rep == 8 && !WCOREDUMP(status)) {
            write(2, "Floating exception\n", 20);
            return (rep + 128);
        }
        if (WCOREDUMP(status) && rep != 8) {
            tmp = my_strcat(tmp, " (core dumped)\n");
            write(2, tmp, my_strlen(tmp));
        } else
            write(2, "Floating exception (core dumped)\n", 34);
        return (rep + 128);
    }
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (0);
}
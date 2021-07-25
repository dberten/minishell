/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int check_after_pipe(char *str)
{
    int rep = 0;
    int i = 0;

    for (; str[i] != '|'; i++);
    for (i = i + 1; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    i += 1;
    if (str[i] == '\0')
        rep = 1;
    return (rep);
}

int check_before_pipe(char *str)
{
    int rep = 0;
    int i = 0;

    for (;str[i] == ' ' || str[i] == '\t'; i++);
    if (str[i] == '|')
        rep = 1;
    return (rep);
}

void close_tab_fd(main_struct_t *main_struct, int rep, int status, int check)
{
    if (main_struct->pipe->nb_pipe >= 2) {
        close(main_struct->pipe->old_tab[0]);
        close(main_struct->pipe->old_tab[1]);
    }
    while (check > 0)
        check = waitpid(rep, &status, 0);
}
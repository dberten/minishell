/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int exit_programm(char **tab)
{
    int nb = 0;
    int size = 0;

    for (; tab[size]; size++);
    if (size == 1) {
        write(1, "exit\n", 6);
        return (nb);
    }
    if (size > 1) {
        nb = my_getnbr(tab[1]);
        write(1, "exit\n", 6);
        return (nb);
    }
    return (nb);
}

int error_setenv(char **tab, int size)
{
    if (size > 3) {
        write(2, "setenv: Too many arguments\n", 28);
        return (1);
    }
    if (size > 1) {
        if ((tab[1][0] < 'A' || tab[1][0] > 'Z') &&
            (tab[1][0] < 'a' || tab[1][0] > 'z') &&
            tab[1][0] != '_') {
            write(2, "setenv: Variable name "
                     "must begin with letter.\n", 47);
            return (1);
        }
        if (error_alpha_setenv(tab) == 1) {
            write(2, "setenv: Variable name must contain "
                     "alphanumeric characters.\n", 61);
            return (1);
        }
    }
    return (0);
}

int manage_input(char *str, main_struct_t *main_struct, int size)
{
    int rep = 0;

    if (check_pipe(str) == 1) {
        rep = manage_pipe(str, main_struct);
        return (rep);
    }
    main_struct->pipe->nb_pipe = 0;
    if (check_redirection(str) == 1) {
        rep = mult_redirection(main_struct, str, size);
        return (rep);
    }
    main_struct->modif->tab = my_str_to_word_array(str, ' ');
    size = len_tab(main_struct->modif->tab);
    rep = all_function(main_struct, main_struct->modif->tab, size);
    return (rep);
}

int main_parse(main_struct_t *main_struct, int rep, int size, char *str)
{
    my_semicolon(main_struct, str, size);
    for (int i = 0; main_struct->semicolon->function[i]; i++) {
        rep = manage_input(main_struct->semicolon->function[i], main_struct,
            size);
    }
    return (rep);
}

int loop(main_struct_t *main_struct, char **envp)
{
    char *str = NULL;
    size_t len;
    int size = 0;
    int rep = 0;

    env_tab(main_struct->modif, envp);
    while (1) {
        isatty(0) ? my_printf("$>") : 0;
        if (getline(&str, &len, stdin) == -1) {
            isatty(0) ? my_printf("exit\n") : 0;
            return (main_struct->modif->return_value);
        }
        str = nice_string(str);
        str = clean_str(str);
        if (str[0] == '\n' || str[0] == '\0' || check_good_str(str) == 1)
            continue;
        rep = main_parse(main_struct, rep, size, str);
        if (main_struct->modif->return_value == 84)
            return (rep);
    }
}
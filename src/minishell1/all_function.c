/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int builtin_2(main_struct_t *main_struct, char **tab, int tmp)
{
    if (tab[0][0] == '/') {
        tmp = exec_path(main_struct, tab);
        if (tmp == 0)
            return (0);
        main_struct->modif->return_value = tmp;
        return (main_struct->modif->return_value);
    } else if (tab[0][0] == '.') {
        tmp = my_exec(main_struct, tab);
        if (tmp == 0)
            return (0);
        main_struct->modif->return_value = tmp;
        return (main_struct->modif->return_value);
    }
    tmp = exec_function(main_struct, tab);
    if (tmp != 0) {
        main_struct->modif->return_value = tmp;
        return (main_struct->modif->return_value);
    }
    return (-1);
}

int all_function_2(main_struct_t *main_struct, char **tab)
{
    int rep = 0;

    if (my_strcmp(tab[0], "exit") == 0) {
        main_struct->modif->return_value = 84;
        rep = exit_programm(tab);
        return (rep);
    }
    if (!my_strcmp(tab[0], "cd")) {
        main_struct->modif->return_value = parse_cd(main_struct->modif, tab);
        return (main_struct->modif->return_value);
    }
    return (-1);
}

int builtin_1(modif_t *modif, char **tab, int size)
{
    int rep = 0;

    if (my_strcmp(tab[0], "env") == 0) {
        rep = error_env(tab);
        if (rep == 0) {
            print_tab(modif->env_tab);
            return (0);
        }
        modif->return_value = rep;
        return (modif->return_value);
    }
    if (my_strcmp(tab[0], "setenv") == 0) {
        if (error_setenv(tab, size) == 0) {
            manage_all_case(modif, tab);
            return (0);
        }
        modif->return_value = 1;
        return (modif->return_value);
    }
    return (-1);
}

int condition_return(main_struct_t *main_struct, char **tab, int tmp)
{
    int rep = 0;

    rep = all_function_2(main_struct, tab);
    if (rep != -1)
        return (rep);
    rep = builtin_2(main_struct, tab, tmp);
    if (rep != -1) {
        main_struct->modif->return_value = rep;
        return (main_struct->modif->return_value);
    }
    return (-1);
}

int all_function(main_struct_t *main_struct, char **tab, int size)
{
    int rep = 0;
    int tmp = 0;

    if (my_strcmp(tab[0], "unsetenv") == 0) {
        if (my_unsetenv(main_struct->modif, tab) == 0)
            return (0);
        main_struct->modif->return_value = 1;
        return (main_struct->modif->return_value);
    }
    rep = builtin_1(main_struct->modif, tab, size);
    if (rep != -1) {
        main_struct->modif->return_value = rep;
        return (main_struct->modif->return_value);
    }
    rep = condition_return(main_struct, tab, tmp);
    if (rep != -1)
        return (rep);
    return (0);
}
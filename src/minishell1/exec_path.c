/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int len_tab(char **tab)
{
    int size = 0;

    for (; tab[size]; size++);
    return (size);
}

int exec_path(main_struct_t *main_struct, char **tab)
{
    char *path = find_var("PATH=", main_struct->modif);
    char **path_tab = NULL;
    int tmp = -1;

    if (path == NULL) {
        path = my_strcat(tab[0], ": Command not found.\n");
        write(2, path, my_strlen(path));
        return (1);
    }
    path_tab = my_get_path(path);
    for (int i = 0; path_tab[i]; i++) {
        if (access(tab[0], X_OK) == 0) {
            tmp = my_fork(tab[0], main_struct, tab);
            break;
        }
    }
    return (manage_error(tmp, tab));
}
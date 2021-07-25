/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int my_fork(char *str, main_struct_t *main_struct, char **tab)
{
    int rep = 0;
    int status = 0;
    pid_t pid;

    if (main_struct->pipe->nb_pipe > 0) {
        execve(str, tab, main_struct->modif->env_tab);
        error_exec(tab);
        return (rep);
    }
    pid = fork();
    if (pid == 0) {
        execve(str, tab, main_struct->modif->env_tab);
        error_exec(tab);
    }
    if (pid > 0)
        waitpid(pid, &status, 0);
    if (pid == -1)
        perror("fork");
    rep  = get_return(status);
    return (rep);
}

char *find_var(char *str, modif_t *modif)
{
    char *tmp = NULL;
    int len = my_strlen(str);

    for (int i = 0; modif->env_tab[i]; i++) {
        if (my_strncmp(modif->env_tab[i], str, len) == 0) {
            tmp = my_strdup(cut_str(modif->env_tab[i]));
            return (tmp);
        }
    }
    return (NULL);
}

char **my_get_path(char *path)
{
    char **path_tab = NULL;

    path_tab = my_str_to_word_array(path, ':');
    for (int i = 0; path_tab[i]; i++)
        path_tab[i] = my_strcat(path_tab[i], "/");
    return (path_tab);
}

int manage_error(int tmp, char **tab)
{
    char *str = NULL;

    if (tmp == -1) {
        str = my_strcat(tab[0], ": Command not found.\n");
        write(2, str, (22 + my_strlen(tab[0])));
        return (1);
    }
    return (tmp);
}

int exec_function(main_struct_t *main_struct, char **tab)
{
    char **path_tab = NULL;
    char *path = find_var("PATH=", main_struct->modif);
    int rep = 0;
    int tmp = -1;

    if (path == NULL) {
        path = my_strcat(tab[0], ": Command not found.\n");
        write(2, path, my_strlen(path));
        return (1);
    }
    path_tab = my_get_path(path);
    for (int i = 0; path_tab[i]; i++) {
        path_tab[i] = my_strcat(path_tab[i], tab[0]);
        if (access(path_tab[i], F_OK) == 0) {
            tmp = my_fork(path_tab[i], main_struct, tab);
            break;
        }
    }
    rep = manage_error(tmp, tab);
    return (rep);
}

/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int my_right_redirection(int i, main_struct_t *main_struct)
{
    int fd = open(main_struct->redirection->tab_file[i],
        O_CREAT | O_RDWR, 0777);;
    char *str = NULL;

    if (fd == -1) {
        str = my_strcat(main_struct->redirection->tab_file[i],
            ": No such file or directory.\n");
        write(2, str, my_strlen(main_struct->redirection->tab_file[i]) + 30);
        return (1);
    }
    dup2(fd, 1);
    return (0);
}

int my_left_redirection(int i, main_struct_t *main_struct)
{
    char *str = NULL;
    int fd = open(main_struct->redirection->tab_file[i], O_RDONLY);

    if (fd == -1) {
        str = my_strcat(main_struct->redirection->tab_file[i],
            ": No such file or directory.\n");
        write(2, str, my_strlen(main_struct->redirection->tab_file[i]) + 30);
        return (1);
    }
    dup2(fd, 0);
    return (0);
}

int my_double_right_redirect(int i, main_struct_t *main_struct)
{
    char *str = NULL;
    int fd = open(main_struct->redirection->tab_file[i],
        O_CREAT | O_APPEND | O_WRONLY, 0777);

    if (fd == -1) {
        str = my_strcat(main_struct->redirection->tab_file[i],
            ": No such file or directory.\n");
        write(2, str, my_strlen(main_struct->redirection->tab_file[i]) + 30);
        return (1);
    }
    dup2(fd, 1);
    return (0);
}
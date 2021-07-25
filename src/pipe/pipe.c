/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int check_pipe(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '|')
            return (1);
    }
    return (0);
}

int nb_pipe(char *str)
{
    int nb_pipe = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '|')
            nb_pipe++;
    }
    return (nb_pipe);
}

void child(main_struct_t *main_struct, char **tab, int i)
{
    if (i != 0 ) {
        dup2(main_struct->pipe->old_tab[0], 0);
        close(main_struct->pipe->old_tab[0]);
        close(main_struct->pipe->old_tab[1]);
    }
    if (main_struct->pipe->parse_pipe[i + 1]) {
        close(main_struct->pipe->new_tab[0]);
        dup2(main_struct->pipe->new_tab[1], 1);
        close(main_struct->pipe->new_tab[1]);
    }
    all_function(main_struct, tab, len_tab(tab));
}

int my_pipe(main_struct_t *main_struct, char **tab, int i)
{
    pid_t pid;
    int tmp_value[2] = {dup(0), dup(1)};

    if (main_struct->pipe->parse_pipe[i + 1])
        pipe(main_struct->pipe->new_tab);
    pid = fork();
    if (pid == 0)
        child(main_struct, tab, i);
    else if (pid > 0){
        if (i != 0) {
            close(main_struct->pipe->old_tab[0]);
            close(main_struct->pipe->old_tab[1]);
        }
        if (main_struct->pipe->parse_pipe[i + 1]) {
            main_struct->pipe->old_tab[0] = main_struct->pipe->new_tab[0];
            main_struct->pipe->old_tab[1] = main_struct->pipe->new_tab[1];
        }
    }
    close_fd(tmp_value[0], tmp_value[1]);
    return (pid);
}

int manage_pipe(char *str, main_struct_t *main_struct)
{
    int check = 1;
    int rep = 0;
    int status = 0;
    char **tab = NULL;

    main_struct->pipe->nb_pipe = nb_pipe(str);
    main_struct->pipe->parse_pipe = my_str_to_word_array(str, '|');
    if (check_after_pipe(str) == 1 || check_before_pipe(str) == 1) {
        write(2, "Invalid null command.\n", 23);
        main_struct->modif->return_value = 1;
        return (1);
    }
    for (int i = 0; main_struct->pipe->parse_pipe[i]; i++) {
        main_struct->pipe->parse_pipe[i] =
            clean_str(main_struct->pipe->parse_pipe[i]);
        tab = my_str_to_word_array(main_struct->pipe->parse_pipe[i], ' ');
        rep = my_pipe(main_struct, tab, i);
    }
    close_tab_fd(main_struct, rep, status, check);
    return (rep);
}




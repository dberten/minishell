/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "my.h"
#include "mysh.h"

void init_struct(main_struct_t *main_struct)
{
    main_struct->pipe->nb_pipe = 0;
    main_struct->pipe->parse_pipe = NULL;
    main_struct->redirection->redirect = NULL;
    main_struct->redirection->tab_file = NULL;
    main_struct->semicolon->function = NULL;
    main_struct->modif->tab = NULL;
    main_struct->modif->env_tab = NULL;
    main_struct->modif->return_value = 0;
}

int main(int ac, char **av, char **envp)
{
    main_struct_t *main_struct = malloc(sizeof(main_struct_t));
    main_struct->pipe = malloc(sizeof(pipe_t));
    main_struct->redirection = malloc(sizeof(redirection_t));
    main_struct->semicolon = malloc(sizeof(semicolon_t));
    main_struct->modif = malloc(sizeof(modif_t));

    init_struct(main_struct);
    int rep = loop(main_struct, envp);
    free(main_struct);
    return (rep);
}
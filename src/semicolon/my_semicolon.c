/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int is_semicolon(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == ';')
            return (1);
    return (0);
}

int my_semicolon(main_struct_t *main_struct, char *str, int size)
{
    if (is_semicolon(str) == 1) {
        main_struct->semicolon->function = my_str_to_word_array(str, ';');
        return (0);
    }
    main_struct->semicolon->function = malloc(sizeof(char *) * 2);
    main_struct->semicolon->function[0] = my_strdup(str);
    main_struct->semicolon->function[1] = NULL;
    return (0);
}
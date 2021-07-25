/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

char *check_space_before(char *str)
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;
    char *tmp2 = NULL;

    for (; str[i] != '>' && str[i] != '<'; i++);
    tmp = malloc(sizeof(char) * i + 1);
    i = 0;
    for (;  str[i] != '>' && str[i] != '<'; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    tmp2 = malloc(sizeof(char) * (my_strlen(str) - i + 1));
    for (; str[i]; i++, j++)
        tmp2[j] = str[i];
    tmp2[j] = '\0';
    tmp = my_strcat(tmp , " ");
    tmp = my_strcat(tmp, tmp2);
    return (tmp);
}

int check_redirection(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '>' || str[i] == '<')
            return (1);
    }
    return (0);
}

int check_space(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i != 0 && (str[i] == '>' || str[i] == '<') &&
        (str[i - 1] == ' ' || str[i - 1] == '\t'))
            return (1);
    }
    return (2);
}

int get_space(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] == '>' || str[i] == '<') && str[i + 1] == ' ')
            return (i + 1);
    }
    return (0);
}

char *get_redirect(char *str, main_struct_t *main_struct, char c)
{
    int i = 0;
    char *tmp = NULL;

    main_struct->redirection->parse_str = my_str_to_word_array(str, ' ');
    for (i = 0; main_struct->redirection->parse_str[i]; i++) {
        if (main_struct->redirection->parse_str[i][0] == c)
            break;
    }
    if (main_struct->redirection->parse_str[i][1] != '\0') {
        if (main_struct->redirection->parse_str[i][1] != ' ' &&
            main_struct->redirection->parse_str[i][1] != c)
            return (main_struct->redirection->parse_str[i]);
    }
    if (main_struct->redirection->parse_str[i + 1]) {
        tmp = my_strcat(main_struct->redirection->parse_str[i],
            main_struct->redirection->parse_str[i + 1]);
        return (tmp);
    }
    return (main_struct->redirection->parse_str[i]);
}




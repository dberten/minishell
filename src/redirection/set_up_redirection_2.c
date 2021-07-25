/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"


void char_remove(int i, char *str)
{
    for (; str[i]; i++)
        str[i] = str[i + 1];
}

int get_rep(char *str, int i)
{
    int rep = 0;

    i += 1;
    for (; str[i] && str[i] != '<' && str[i] != '>'; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            rep = 1;
    }
    if (rep == 1)
        return (i);
    return (-1);
}

void remove_last_part(char *str, int *i, main_struct_t *main_struct)
{
    if (str[*i + 1] == str[*i])
        *i = (*i) + 2;
    else
        *i = (*i) + 1;
    for ( ;(str[*i] == ' ' || str[*i] == '\t') && str[*i] != '\0'; (*i)++);
    if (str[*i] == '\0') {
        write(2, "Missing name for redirect.\n", 23);
        return;
    }
    (*i)++;
    for (; str[*i] && str[*i] != ' '; (*i)++);
}

char *check_missing_name(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (((str[i] == '<' || str[i] == '>') &&
            str[i + 1] != str[i] && (i = get_rep(str, i )) == -1)) {
            write(2, "Missing name for redirect.\n", 28);
            return (NULL);
        }
        if (((str[i] == '<' || str[i] == '>') &&
            str[i + 1] == str[i] && (i = get_rep(str, i + 1 )) == -1)) {
            write(2, "Missing name for redirect.\n", 28);
            return (NULL);
        }
    }
    return (str);
}

char *remove_redirect(char *str, main_struct_t *main_struct)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;

    if (check_missing_name(str) == NULL)
        return (NULL);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '>' || str[i] == '<')
            remove_last_part(str, &i, main_struct);
        tmp[j] = str[i];
        j++;
    }
    tmp[j] = '\0';
    if (tmp[0] == '\0') {
        write(2, "Invalid null command.\n", 23);
        return (NULL);
    }
    return (tmp);
}
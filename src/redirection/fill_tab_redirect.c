
/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

int check_car(char c)
{
    if (c == '>' || c == '<')
        return (1);
    return (0);
}

int len_tab_chevron(char *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++) {
        if (( i != 0 && str[i - 1] != str[i]
        && check_car(str[i]) == 1 && str[i] != str[i + 1]) ||
            (check_car(str[i]) && str[i] == str[i + 1])) {
            len++;
        }
    }
    return (len);
}

int get_type_redirect(char *str, int i)
{
    if (i == 0 && str[i] == '>' && str[i + 1] != '>')
        return (1);
    if (i == 0 && str[i] == '<' && str[i + 1] != '<')
        return (2);
    if (i == 0 && str[i] == '>' && str[i + 1] == '>' && str[i + 1] != '>')
        return (3);
    if (i != 0 && str[i - 1] != '>' && str[i] == '>' && str[i + 1] != '>')
        return (1);
    if (i != 0 && str[i - 1] != '<' && str[i] == '<' && str[i + 1] != '<')
        return (2);
    if (i != 0 && str[i - 1] != '>' && str[i] == '>' && str[i + 1] == '>'
    && str[i + 2 ] && str[i + 2] != '>')
        return (3);
    if (i != 0 && str[i - 1] != '<' && str[i] == '<' && str[i + 1] == '<'
    && str[i + 2] && str[i + 2] != '<')
        return (4);
    return (0);
}

void fill_tab_int(main_struct_t *main_struct, char *str)
{
    int len_tab = len_tab_chevron(str);
    int rep = 0;
    int j = 0;

    main_struct->redirection->redirect = malloc(sizeof(int) * (len_tab + 1));
    for (int i = 0; str[i]; i++) {
        rep = get_type_redirect(str, i);
        if (rep != 0) {
            main_struct->redirection->redirect[j] = rep;
            j++;
        }
    }
    main_struct->redirection->redirect[j] = -1;
}

void fill_tab_file(main_struct_t *main_struct, char *str)
{
    str = get_files(str);
    str = clean_str(str);
    main_struct->redirection->tab_file = my_str_to_word_array(str, ' ');
}

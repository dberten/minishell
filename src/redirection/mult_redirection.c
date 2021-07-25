/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Dorian Berten
*/

#include "mysh.h"

void close_fd(int tmp1, int tmp2)
{
    close(tmp1);
    close(tmp2);
}

void dup_and_close(int tmp1, int tmp2)
{
    dup2(tmp1, 1);
    dup2(tmp2, 0);
    close(tmp1);
    close(tmp2);
}

int boucle_redirect(main_struct_t *main_struct)
{
    int return_value = 0;

    for (int i = 0; main_struct->redirection->redirect[i] != -1; i++) {
        if (main_struct->redirection->redirect[i] == 1)
            return_value = my_right_redirection(i, main_struct);
        if (main_struct->redirection->redirect[i] == 2)
            return_value = my_left_redirection(i, main_struct);
        if (main_struct->redirection->redirect[i] == 3)
            return_value = my_double_right_redirect(i, main_struct);
    }
    return (return_value);
}

int mult_redirection(main_struct_t *main_struct, char *str, int size)
{
    char *tmp = my_strdup(str);
    int rep = 0;
    int rep2 = 0;
    int tmp_value[2] = {dup(1), dup(0)};
    char *function = remove_redirect(str, main_struct);

    if (function == NULL) {
        main_struct->modif->return_value = 1;
        return (1);
    }
    main_struct->redirection->parse_str = my_str_to_word_array(function, ' ');
    fill_tab_int(main_struct, tmp);
    fill_tab_file(main_struct, tmp);
    rep2 = boucle_redirect(main_struct);
    if (rep2 == 1)
        return (1);
    rep = all_function(main_struct, main_struct->redirection->parse_str, size);
    dup_and_close(tmp_value[0], tmp_value[1]);
    return (rep);
}
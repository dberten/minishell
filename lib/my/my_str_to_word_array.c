/*
** EPITECH PROJECT, 2024
** PSU_my_ls_2019
** File description:
** Created by Dorian Berten
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int nb_of_word(char *str, char c)
{
    int nb_of_word = 0;
    int nb_of_space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i != 0 && str[i - 1] != c && str[i] == c)
            nb_of_space++;
    }
    nb_of_word = nb_of_space + 1;
    return (nb_of_word);
}

int *size_of_word(char *str, char c)
{
    int j = 0;
    int len_word = 0;
    int *length = malloc(sizeof(int) * (nb_of_word(str, c)));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            break;
        if (str[i] != c)
            len_word++;
        if (i != 0 && str[i - 1] != c && str[i] == c) {
            length[j++] = len_word;
            len_word = 0;
        }
    }
    length[j] = len_word;
    return (length);
}

char **my_str_to_word_array(char *str, char c)
{
    char **big_tab = malloc(sizeof(char *) * (nb_of_word(str, c) + 1));
    int *size_word = size_of_word(str, c);
    int i = 0;
    int y = 0; int j = 0;

    for (; str[y] == c || str[y] == ' ' || str[y] == '\t'; y++);
    for (; i < nb_of_word(str, c); i++) {
        if (str[y] == '\n' || str[y] == '\0')
            break;
        big_tab[i] = malloc(sizeof(char) * (size_word[i] + 2));
        for (j = 0; str[y] != c && str[y] != '\0'; j++) {
            if (str[y] == '\n')
                break;
            big_tab[i][j] = str[y++];
        }
        big_tab[i][j] = '\0';
        for (; str[y] == c || str[y] == ' ' || str[y] == '\t'; y++);
    }
    big_tab[i] = NULL;
    return (big_tab);
}
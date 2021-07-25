/*
** EPITECH PROJECT, 2020
** clean_str
** File description:
** clean_str
*/

#include "my.h"
#include "mysh.h"

int check_good_str(char *str)
{
    int i = 0;

    for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    if (i == my_strlen(str))
        return (1);
    return (0);
}

char *clean_str(char *str)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;

    for (; str[i]; i++) {
        if (str[i] == '\t') {
            tmp[j++] = ' ';
            for (; str[i] == '\t'; i++);
        }
        if (i == 0 && (str[i] == ' ' || str[i] == '\t'))
            for (; str[i] == ' ' || str[i] == '\t'; i++);
        if (str[i] == ' ')
            for (; str[i + 1] == ' ' || str[i + 1] == '\t'; i++);
        tmp[j++] = str[i];
    }
    tmp[j] = '\0';
    return (tmp);
}
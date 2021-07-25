/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count and return number of  characters
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy characters from a string into another
*/

char    *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (i; src[i] != '\0'; i++) {
        dest [i] = src [i];
    if (i == n - 1)
        return (dest);
    }
}

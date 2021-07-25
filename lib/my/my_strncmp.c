/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** reproduce the behavior of the my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;
    n = n - 1;

    while (s1[a] == s2[a] && a < n)
        a++;
    return (s1[a] - s2[a]);
}
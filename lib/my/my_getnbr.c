/*
** EPITECH PROJECT, 2024
** BOO_phoenix_d01_2019
** File description:
** Created by Dorian Berten
*/

int nb_of_add(char const *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '+')
            c++;
    return (c);
}

int nb_of_less(char const *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            c++;
    return (c);
}

int my_getnbr(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        }
    }
    if (nb_of_less(str) > nb_of_add(str))
        nb *= -1;
    return (nb);
}

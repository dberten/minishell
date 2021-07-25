/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap values of two integers
*/
void    my_swap(int *a, int *b)
{
    int c;
    int d;
    c = *a;
    d = *b;
    *a = d;
    *b = c;
}

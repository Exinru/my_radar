/*
** EPITECH PROJECT, 2023
** EPITECH PROJECT TEK1
** File description:
** functions needed
*/

#include "../include/my.h"

int my_nlen(int x)
{
    int cont = 0;

    if (x < 0)
        cont = 1;
    while (x != 0) {
        x = x / 10;
        cont++;
    }
    return (cont);
}

int my_nlen_long(long long x)
{
    int cont = 0;

    if (x < 0)
        cont = 1;
    while (x != 0) {
        x = x / 10;
        cont++;
    }
    return (cont);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int cont = 0;

    while (str[cont] != '\0') {
    cont++;
    }
    return (cont);
}

int my_putstr(char const *str)
{
    int cont = 0;
    int nb = my_strlen(str);

    while (str[cont] != '\0') {
        my_putchar(str[cont]);
        cont++;
    }
    return (nb);
}

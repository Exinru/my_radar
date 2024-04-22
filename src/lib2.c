/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Ints to terminal
*/
#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    while (s1[i] == s2[i]){
        if (s1[i] == 0)
            break;
        i ++;
    }
    return (s1[i] - s2[i]);
}

char *my_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    while (src[i] != 0){
        dest[i] = src[i];
        i ++;
    }
    dest[i] = src[i];
    return (dest);
}

char *my_strdup(char const *src)
{
    size_t len = my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * len);

    if (result == NULL)
        return (NULL);
    my_strcpy(result, src);
    return (result);
}

void my_put_nbr(int nb)
{
    unsigned int n;
    char c;

    n = nb;
    if (nb < 0){
        n = -nb;
        c = '-';
        write(1, &c, 1);
    }
    if (n / 10 != 0)
        my_put_nbr(n / 10);
    my_putchar('0' + (n % 10));
}

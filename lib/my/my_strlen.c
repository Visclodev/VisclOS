/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** return length of string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

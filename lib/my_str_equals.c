/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_str_equals.c
*/

#include <stdlib.h>

int str_equals(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    if (s1[i] != s2[i])
        return 0;
    return 1;
}

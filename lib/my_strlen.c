/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_strlen.c
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}

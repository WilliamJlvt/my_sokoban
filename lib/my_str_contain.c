/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_str_contain.c
*/

int my_str_contain(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

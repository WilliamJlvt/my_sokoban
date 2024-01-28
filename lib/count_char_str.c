/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** count_char_str.c
*/

int count_char_str(char const *str, char c)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            result++;
    return result;
}

/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_strcpy.c
*/

void my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
}

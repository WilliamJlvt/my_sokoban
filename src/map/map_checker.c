/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_checker.c
*/

#include <unistd.h>
#include "../../include/my_sokoban.h"
#include "../../include/my_lib.h"

const char VALID_CHAR[] = {
    ' ', '#', 'O', 'P', 'X', '\n'
};
const unsigned int NB_VALID_CHAR = 6;

static int is_valid_char(char c)
{
    for (int i = 0; i < NB_VALID_CHAR; i++) {
        if (c == VALID_CHAR[i])
            return 1;
    }
    return 0;
}

int is_hashtag_line(const char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != '#')
            return 0;
    }
    return 1;
}

int is_valid_borders(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++) {
        if ((i > 0 && i < map->height - 1) && (map->map[i][0] != '#' ||
            map->map[i][map->width - 1] != '#'))
            return 0;
        if ((i == 0 || i == map->height - 1) && !is_hashtag_line(map->map[i]))
            return 0;
    }
    return 1;
}

int check_chars(map_t *map, int line)
{
    for (int j = 0; map->map[line][j] != '\0'; j++) {
        if (!is_valid_char(map->map[line][j]))
            return 0;
    }
    return 1;
}

int has_valid_boxes(map_t *map)
{
    int nb_boxes = 0;
    int nb_storage = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        nb_boxes += count_char_str(map->map[i], 'X');
        nb_storage += count_char_str(map->map[i], 'O');
    }
    if (nb_boxes == 0 || nb_boxes != nb_storage)
        return 0;
    return 1;
}

int is_valid_map(map_t *map)
{
    if (!has_valid_boxes(map))
        return 0;
    for (int i = 0; map->map[i] != NULL; i++) {
        if (my_strlen(map->map[i]) != map->width)
            return 0;
        check_chars(map, i);
    }
    return 1;
}

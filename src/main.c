/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_sokoban.h"

int main(int argc, char *argv[])
{
    char *buffer_file = read_map(argv[1]);
    map_t *map = malloc(sizeof(map_t));
    int result = args_handling(argc, argv, buffer_file);

    if (result != -1) {
        free(map);
        free(buffer_file);
        return result;
    }
    map->buffer = buffer_file;
    if (!init_map(buffer_file, map) || map == NULL || !is_valid_map(map)) {
        write(2, "Error: Invalid map\n", 19);
        return ERROR;
    }
    init_window(map);
    free(buffer_file);
    return !map->win;
}

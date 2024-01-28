/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_parser.c
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../../include/my_sokoban.h"
#include "../../include/my_lib.h"

static long long get_byte_size(char const *filepath)
{
    struct stat *stat_buf = malloc(sizeof(struct stat));
    long long size = -1;

    if (stat_buf == NULL)
        return -1;
    if (stat(filepath, stat_buf) == 0)
        size = stat_buf->st_size;
    free(stat_buf);
    return size;
}

int get_width(char const *map)
{
    int max_width = 0;
    int current_width = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '\n') {
            current_width++;
            continue;
        }
        if (current_width > max_width) {
            max_width = current_width;
        }
        current_width = 0;
    }
    return max_width;
}

static int get_height(char const *map)
{
    int result = 1;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '\n')
            result++;
    return result;
}

char *read_map(char const *filepath)
{
    long long size = get_byte_size(filepath);
    char *buffer;
    int file;

    if (size == -1)
        return NULL;
    buffer = malloc((size * sizeof(char)) + 1);
    if (buffer == NULL)
        return NULL;
    file = open(filepath, O_RDONLY);
    if (file == -1)
        return NULL;
    read(file, buffer, size);
    buffer[size] = '\0';
    close(file);
    return buffer;
}

static int init_positions(char c, int i, int j, map_t *map)
{
    if (c == 'P' && map->player != NULL) {
        return 0;
    }
    if (c == 'P') {
        map->player = malloc(sizeof(cell_t));
        if (map->player == NULL)
            return 0;
        map->player->width = j;
        map->player->height = i;
    }
    if (c == 'X') {
        map->boxes++;
    }
    return 1;
}

static void fill_str(int *j, char **array, int i, map_t *map)
{
    while (*j < map->width) {
        array[i][*j] = ' ';
        (*j)++;
    }
}

int is_valid_char(char c)
{
    return c == 'X' || c == '#' || c == ' ' || c == 'O' || c == 'P';
}

static int init_array(const char *buffer, char **array, map_t *map)
{
    int i = 0;
    int j = 0;

    for (int k = 0; buffer[k] != '\0'; k++) {
        if (buffer[k] == '\n') {
            fill_str(&j, array, i, map);
            array[i][j] = '\0';
            i++;
            j = 0;
            continue;
        }
        if (!init_positions(buffer[k], i, j, map) || !is_valid_char(buffer[k]))
            return 0;
        array[i][j] = buffer[k];
        j++;
    }
    array[i] = NULL;
    return 1;
}

int init_map(char *buffer, map_t *map)
{
    int height = get_height(buffer) - 1;
    int width = get_width(buffer);
    char **array = malloc(sizeof(char *) * (height + 1));
    char **copy = malloc(sizeof(char *) * (height + 1));

    if (array == NULL)
        return 0;
    for (int k = 0; k < height; k++) {
        array[k] = malloc(sizeof(char) * (width + 1));
        copy[k] = malloc(sizeof(char) * (width + 1));
    }
    map->height = height;
    map->width = width;
    if (!init_array(buffer, array, map) || map->player == NULL)
        return 0;
    map->map = array;
    for (int i = 0; map->map[i] != NULL; i++)
        my_strcpy(copy[i], map->map[i]);
    map->copy = copy;
    return 1;
}

void reset_map(map_t *map)
{
    map->player = NULL;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            map->map[i][j] = map->copy[i][j];
            init_positions(map->map[i][j], i, j, map);
        }
    }
}

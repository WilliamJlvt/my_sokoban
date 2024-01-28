/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_manager.c
*/

#include <unistd.h>
#include "../../include/my_sokoban.h"
#include "../../include/my_lib.h"

int move_player(map_t *map, int dx, int dy)
{
    int x = map->player->width;
    int y = map->player->height;

    if (map->map[y + dy][x + dx] == '#')
        return 0;
    if (map->map[y + dy][x + dx] == 'X' &&
        map->map[y + dy * 2][x + dx * 2] == '#')
        return 0;
    if (map->map[y + dy][x + dx] == 'X' &&
        map->map[y + dy * 2][x + dx * 2] == 'X')
        return 0;
    if (map->map[y + dy][x + dx] == 'X') {
        map->map[y + dy][x + dx] = ' ';
        map->map[y + dy * 2][x + dx * 2] = 'X';
    }
    map->map[y][x] = map->copy[y][x] == 'O' ? 'O' : ' ';
    map->map[y + dy][x + dx] = 'P';
    map->player->width += dx;
    map->player->height += dy;
    return 1;
}

int is_collid(char c)
{
    return c == '#' || c == 'X';
}

int check_box_corner(map_t *map, int y)
{
    int result = 0;

    for (int x = 0; map->map[y][x] != '\0'; x++) {
        if (map->map[y][x] != 'X')
            continue;
        if (is_collid(map->map[y][x + 1]) && is_collid(map->map[y + 1][x]) ||
            is_collid(map->map[y][x - 1]) && is_collid(map->map[y + 1][x]) ||
            is_collid(map->map[y][x + 1]) && is_collid(map->map[y - 1][x]) ||
            is_collid(map->map[y][x - 1]) && is_collid(map->map[y - 1][x]))
            result += 1;
    }
    return result;
}

int boxes_are_in_corner(map_t *map)
{
    int blocked_boxes = 0;

    for (int i = 0; map->map[i] != NULL; i++)
        blocked_boxes += check_box_corner(map, i);
    map->win = blocked_boxes != map->boxes;
    return blocked_boxes == map->boxes;
}

int check_win(map_t *map)
{
    if (map->copy[map->player->height][map->player->width] == 'O')
        return 0;
    for (int i = 0; map->map[i] != NULL; i++)
        if (my_str_contain(map->map[i], 'O'))
            return 0;
    map->win = 1;
    return 1;
}

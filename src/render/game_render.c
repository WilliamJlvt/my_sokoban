/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_render.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../../include/my_sokoban.h"

struct direction {
    int action;
    int x;
    int y;
};

struct direction directions[] = {
    {KEY_UP, 0, -1},
    {KEY_DOWN, 0, 1},
    {KEY_LEFT, -1, 0},
    {KEY_RIGHT, 1, 0}
};

void draw_map(map_t *map, int row_size, int col_size)
{
    for (int i = 0; i < map->height; i++) {
        mvprintw(
            (row_size - map->height) / 2 + i,
            (col_size - map->width) / 2, "%s\n", map->map[i]
        );
    }
}

int update_map(map_t *map, int ch_code, int row_size, int col_size)
{
    for (int i = 0; i < 4; i++) {
        if (ch_code != directions[i].action)
            continue;
        move_player(map, directions[i].x, directions[i].y);
        if (check_win(map) || boxes_are_in_corner(map)) {
            draw_map(map, row_size, col_size);
            return 0;
        }
    }
    if (ch_code == ' ')
        reset_map(map);
    clear();
    draw_map(map, row_size, col_size);
    return 1;
}

void uninit_game(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        free(map->map[i]);
        free(map->copy[i]);
    }
    free(map->map);
    free(map->copy);
    free(map->player);
    free(map);
}

/*
** EPITECH PROJECT, 2023
** final
** File description:
** unit_test.c
*/

#include "../include/my_sokoban.h"
#include <criterion/criterion.h>

struct test_map_s {
    char *file_path;
    int result;
    int width;
    int height;
    int player_x;
    int player_y;
};

struct test_map_s test_maps[6] = {
    {"maps/map_0", -1, 5, 7, 2, 4},
    {"maps/map_1", -1, 21, 7, 5, 4},
    {"maps/map_2", -1, 22, 15, 5, 12},
    {"maps/map_3", -1, 27, 15, 2, 9},
    {"maps/map_4", -1, 11, 15, 2, 7},
    {"maps/map_5", -1, 238, 55, 55, 9}
};

void tests(map_t *map, int i)
{
    cr_assert_eq(map->width, test_maps[i].width);
    cr_assert_eq(map->height, test_maps[i].height);
    cr_assert_eq(map->player->width, test_maps[i].player_x);
    cr_assert_eq(map->player->height, test_maps[i].player_y);
}

Test(my_sokoban, test_on_map)
{
    char *buffer_file;
    map_t *map;
    int result;
    char *argv[2] = {"./my_sokoban", ""};

    for (int i = 0; i < 6; i++) {
        buffer_file = read_map(test_maps[i].file_path);
        map = malloc(sizeof(map_t));
        argv[1] = test_maps[i].file_path;
        result = args_handling(2, argv, buffer_file);
        map->buffer = buffer_file;
        cr_assert_eq(result, test_maps[i].result);
        map->buffer = buffer_file;
        map->player = NULL;
        init_map(buffer_file, map);
        tests(map, i);
        uninit_game(map);
        free(buffer_file);
    }
}

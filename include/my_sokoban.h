/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_sokoban.h
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

    #define ERROR 84
    #define SUCCESS 0

typedef struct cell_s {
    int width;
    int height;
} cell_t;

typedef struct cell_node_s {
    cell_t *data;
    struct cell_node_s *next;
} cell_node_t;

typedef struct map_s {
    char **map;
    char **copy;
    int width;
    int height;
    cell_t *player;
    char *buffer;
    int win;
    int boxes;
} map_t;

//src/errors.c
int args_handling(int argc, char *argv[], const char *buffer_file);

//src/map/map_parser.c
char *read_map(char const *filepath);
int init_map(char *buffer, map_t *map);

//src/map/map_manager.c
int move_player(map_t *map, int dx, int dy);
int boxes_are_in_corner(map_t *map);
int check_win(map_t *map);

//src/map/map_parser.c
int get_width(char const *map);
void reset_map(map_t *map);
int is_valid_map(map_t *map);

//src/render/game_render.c
int update_map(map_t *map, int ch_code, int row_size, int col_size);
void uninit_game(map_t *map);

//src/render/window_render.c
void init_window(map_t *map);

//src/util/file_info_reader.c
void print_help_info(void);

#endif

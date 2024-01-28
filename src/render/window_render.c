/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** window_render.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../../include/my_sokoban.h"
#include "../../include/my_lib.h"

void print_centered_message(char *message, int row, int col)
{
    mvprintw(row / 2, (col - my_strlen(message)) / 2, "%s", message);
}

static void check_size(map_t *map, int row, int col)
{
    if (map->width > col || map->height > row) {
        clear();
        print_centered_message("Please resize your terminal\n", row, col);
    }
}

void init_screen(void)
{
    WINDOW *result = initscr();

    noecho();
    curs_set(FALSE);
    keypad(result, TRUE);
}

void init_window(map_t *map)
{
    int should_continue = 1;
    int row;
    int col;

    init_screen();
    getmaxyx(stdscr, row, col);
    update_map(map, -1, row, col);
    refresh();
    while (should_continue) {
        getmaxyx(stdscr, row, col);
        check_size(map, row, col);
        should_continue = update_map(map, getch(), row, col);
        refresh();
    }
    endwin();
    uninit_game(map);
}

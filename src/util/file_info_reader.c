/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** file_info_reader.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_sokoban.h"
#include "../../include/my_lib.h"

void print_help_info(void)
{
    char *help_info = read_map("resources/help.info");

    if (help_info == NULL) {
        write(2, "Cannot open resources/help.info\n", 32);
        return;
    }
    write(1, help_info, my_strlen(help_info));
    free(help_info);
}

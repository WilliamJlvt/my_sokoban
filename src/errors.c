/*
** EPITECH PROJECT, 2023
** final
** File description:
** errors.c
*/

#include "../include/my_sokoban.h"
#include "../include/my_lib.h"
#include <unistd.h>

int args_handling(int argc, char *argv[], const char *buffer_file)
{
    if (argc == 2 && str_equals(argv[1], "-h")) {
        print_help_info();
        return SUCCESS;
    }
    if (argc != 2) {
        write(2, "Error: Wrong number of arguments\n", 33);
        return ERROR;
    }
    if (buffer_file == NULL) {
        write(2, "Error: File not found\n", 22);
        return ERROR;
    }
    return -1;
}

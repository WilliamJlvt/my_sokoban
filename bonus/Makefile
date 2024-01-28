##
## EPITECH PROJECT, 2023
## my_sokoban
## File description:
## Makefile
##

CC	=	gcc

SRCS	=	unit_test.c									\
			../src/errors.c								\
			../src/map/map_parser.c						\
			../src/map/map_manager.c					\
			../src/map/map_checker.c					\
			../src/render/game_render.c					\
			../src/render/window_render.c				\
			../src/util/file_info_reader.c				\
			../lib/count_char_str.c						\
			../lib/my_str_contain.c						\
			../lib/my_strlen.c							\
			../lib/my_strcpy.c							\
			../lib/my_str_equals.c						\

HRCS	=	include

TARGET	=	my_sokoban_tests

BUILD_DIR = build

OBJS	=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all:	$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lcriterion -lncurses

re:	fclean all

clean:
	rm -f $(OBJS)
	rm -rf $(BUILD_DIR)

fclean:	clean
	rm -f $(TARGET)

# Shitty small makefile for test purpose of ger next line...

# Compiler options
NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM=rm -f

# Source files
SRC_NORMAL = \
	get_next_line.c \
	get_next_line_utils.c \
	get_next_line.h

SRC_BONUS = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	get_next_line_bonus.h

# Targets
.Phony: all normal bonus clean fclean re

all:
	echo "\nRun 'normal' or 'bonus'\n"

normal:
	$(CC) $(CFLAGS) $^ $(SRC_NORMAL) -o $(NAME)
	./$(NAME)

bonus:
	$(CC) $(CFLAGS) $^ $(SRC_BONUS) -o $(NAME)
	./$(NAME)
	
clean:
	

fclean:	clean
	$(RM) $(NAME)

re: fclean all

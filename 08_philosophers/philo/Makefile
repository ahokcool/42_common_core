# Makefile for philosophers
#.SILENT:

# Variables
NAME = philo

# Prints DEBUG Messages
DEBUG = 1

# Compiler options
CC = cc
CFLAGS = -D DEBUG=$(DEBUG) -Wall -Werror -Wextra #-g -fsanitize=address -fsanitize-address-use-after-scope
RM = rm -f

# Color codes
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m

# ->Files
SRCS = philo.c
	
# Object files
OBJS = $(SRCS:.c=.o)

# TARGETS
.PHONY: all clean fclean re norm bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	echo "$(GREEN)$(NAME): created$(RESET)"

clean:
	$(RM) $(OBJS)
	echo "$(RED)$(NAME): cleaned object files$(RESET)"
	
fclean: clean
	$(RM) $(NAME)
	echo "$(RED)$(NAME): cleaned program$(RESET)"

re: fclean all

bonus:
	echo to do

norm:
	norminette

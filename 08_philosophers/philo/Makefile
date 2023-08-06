# Makefile for philosophers
#.SILENT:

# Variables
NAME = philo
TEST_ARGS=5 800 200 200 7	# args for testing
PRINT_MORE_INFOS=1			# if 1, print more infos about the program during execution

# Compiler options
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -fsanitize-address-use-after-scope -DPRINT_MORE_INFOS=$(PRINT_MORE_INFOS)
# CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread -fsanitize-address-use-after-scope -DPRINT_MORE_INFOS=$(PRINT_MORE_INFOS)
RM = rm -f

# Color codes
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m

# ->Files
SRCS = \
	main.c \
	philo.c \
	philos.c \
	utils.c \
	check.c \
	table.c \
	lib_utils_1.c \
	ft_strcat_multi.c \
	lst.c\
	lst_clear.c \
	free.c \
	msg.c \
	philo_actions.c

# Object files
OBJS = $(SRCS:.c=.o)

# TARGETS
.PHONY: all clean fclean re norm bonus run run_count

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

run: re
	./$(NAME) $(TEST_ARGS)

run_count: re
	./$(NAME) $(TEST_ARGS) | ./tests/count_meals.sh  
norm:
	norminette

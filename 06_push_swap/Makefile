# Makefile for push_swap and tester

# Variables
NAME = push_swap
NAME_CHECKER = checker

# Prints DEBUG Messages
DEBUG = 0

# Compiler options
CC = cc
CFLAGS = -D DEBUG=$(DEBUG) -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope
CLIBS = -L$(LIB_FOLDER) -lft_printf -lm
CINCLUDES  = -I$(INCLUDE_FOLDER) 
RM = rm -f

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
RESET = \033[0m

# ->Folders
SRC_FOLDER = ./src/
SRC_FOLDER_CHECKER = ./src_checker/
OBJS_FOLDER = ./obj/
OBJS_FOLDER_CHECKER = ./obj_checker/
LIB_FOLDER = ./lib/
INCLUDE_FOLDER = ./include/

# ->Files
LIBFT_PRINTF = $(LIB_FOLDER)/libft_printf.a
SRCS = $(addprefix $(SRC_FOLDER), \
	main.c \
	check_argv.c \
	debug.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	stack.c \
	stack_utils.c \
	choose_solver.c \
	sort_radix.c \
	sort_small.c)

SRCS_CHECKER = $(addprefix $(SRC_FOLDER_CHECKER), \
	main.c \
	checker.c)

# Object files
OBJS = $(SRCS:$(SRC_FOLDER)%.c=$(OBJS_FOLDER)%.o)
OBJS_CHECKER = $(SRCS_CHECKER:$(SRC_FOLDER_CHECKER)%.c=$(OBJS_FOLDER_CHECKER)%.o)

# TARGETS
.PHONY:	$(NAME) all clean fclean re test checker

all: $(NAME)

checker: $(NAME_CHECKER)

$(NAME): $(OBJS) $(LIBFT_PRINTF)
	@$(CC) $(OBJS) $(CFLAGS) -D DEBUG=$(DEBUG) $(CLIBS) $(CINCLUDES) -o $(NAME)
	@echo "$(GREEN)\n$(NAME): created\n$(RESET)"

$(NAME_CHECKER): $(OBJS) $(OBJS_CHECKER) $(LIBFT_PRINTF)
	@$(CC) $(OBJS_CHECKER) $(filter-out $(OBJS_FOLDER)main.o, $(OBJS)) $(CFLAGS) -D DEBUG=$(DEBUG) $(CLIBS) $(CINCLUDES) -o $(NAME_CHECKER)
	@echo "$(GREEN)\n$(NAME_CHECKER): created\n$(RESET)"

$(OBJS_FOLDER)%.o: $(SRC_FOLDER)%.c
	@mkdir -p $(@D)
	@echo -n "."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_FOLDER_CHECKER)%.o: $(SRC_FOLDER_CHECKER)%.c
	@mkdir -p $(@D)
	@echo -n "."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PRINTF):
	@echo "$(ORANGE)\ncompiling: $(LIBFT_PRINTF)\n$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIB_FOLDER) DEBUG=$(DEBUG)

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)$(NAME): cleaned object files$(RESET)"
	@$(RM) $(OBJS_CHECKER)
	@echo "$(RED)$(NAME_CHECKER): cleaned object files$(RESET)"

fclean: clean
	@make --no-print-directory -C $(LIB_FOLDER) fclean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME): cleaned program$(RESET)"
	@$(RM) $(NAME_CHECKER)
	@echo "$(RED)$(NAME_CHECKER): cleaned program$(RESET)"

re: fclean all

test: re
	./tests/test_1_to_5.sh

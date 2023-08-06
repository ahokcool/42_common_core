# Makefile for philosophers
.SILENT:

# Variables
NAME = philo

# args for testing
TEST_ARGS_1=1 800 200 200
TEST_ARGS_2=5 800 200 200
TEST_ARGS_3=5 800 200 200 7 | ./tests/count_meals.sh
TEST_ARGS_4=4 410 200 200
TEST_ARGS_5=4 310 200 100
TEST_ARGS_6=2 300 200 100 42

PUT_MORE_INFOS=0			# if 1, print more infos about the program during execution

# Compiler options
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -fsanitize-address-use-after-scope -DPUT_MORE_INFOS=$(PUT_MORE_INFOS)
# CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread -fsanitize-address-use-after-scope -DPUT_MORE_INFOS=$(PUT_MORE_INFOS)
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
	time.c \
	check.c \
	table.c \
	lib_utils_1.c \
	ft_strcat_multi.c \
	lst.c\
	msg_values.c \
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

enable_pretty:
	$(eval PUT_MORE_INFOS = 1)

disable_pretty:
	$(eval PUT_MORE_INFOS = 0)

run_1: enable_pretty re
	@echo "------------------------------------------------------------"
	@echo -n "ARGUMENTS:\t$(TEST_ARGS_1)" | tr ' ' ' '
	@echo  ""
	@echo -n "RESULT:\t	He should die...\n"
	@echo "------------------------------------------------------------"
	./$(NAME) $(TEST_ARGS_1)

run_2: enable_pretty re
	@echo "------------------------------------------------------------"
	@echo -n "ARGUMENTS:\t$(TEST_ARGS_2)" | tr ' ' ' '
	@echo  ""
	@echo -n "RESULT:\t	No one dies!\n"
	@echo "------------------------------------------------------------"
	sleep 5
	./$(NAME) $(TEST_ARGS_2)

run_3: disable_pretty re
	@echo "------------------------------------------------------------"
	@echo -n "ARGUMENTS:\t$(TEST_ARGS_3)" | tr ' ' ' '
	@echo  ""
	@echo -n "RESULT:\t	No one dies and stop after 7 meals...\n"
	@echo "------------------------------------------------------------"
	./$(NAME) $(TEST_ARGS_3)

run_4: enable_pretty re
	@echo "------------------------------------------------------------"
	@echo -n "ARGUMENTS:\t$(TEST_ARGS_4)" | tr ' ' ' '
	@echo  ""
	@echo -n "RESULT:\t	No one dies!\n"
	@echo "------------------------------------------------------------"
	sleep 5
	./$(NAME) $(TEST_ARGS_4)

run_5: enable_pretty re
	@echo "------------------------------------------------------------"
	@echo -n "ARGUMENTS:\t$(TEST_ARGS_5)" | tr ' ' ' '
	@echo  ""
	@echo -n "RESULT:\t	Someone dies!\n"
	@echo "------------------------------------------------------------"
	sleep 5
	./$(NAME) $(TEST_ARGS_5)

run_6: enable_pretty re
	@echo "------------------------------------------------------------"
	@echo -n "ARGUMENTS:\t$(TEST_ARGS_6)" | tr ' ' ' '
	@echo  ""
	@echo -n "RESULT:\t	Check timesstamps...\n"
	@echo "------------------------------------------------------------"
	sleep 5
	./$(NAME) $(TEST_ARGS_6)

norm:
	norminette

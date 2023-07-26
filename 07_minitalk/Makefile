# Makefile for minitalk

# Variables
NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client

# Prints DEBUG Messages
DEBUG = 0

# Compiler options
CC = cc
CFLAGS = -D DEBUG=$(DEBUG) -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope
CLIBS = -L$(LIB_FOLDER) -lft_printf -lm
CINCLUDES  = -I$(INCLUDE_FOLDER) 
RM = rm -f

# Color codes
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m

# ->Folders
LIB_FOLDER = ./lib/
SRC_FOLDER_SERVER = ./src/server/
SRC_FOLDER_CLIENT = ./src/client/
OBJS_FOLDER_SERVER = ./obj/server/
OBJS_FOLDER_CLIENT = ./obj/client/

INCLUDE_FOLDER = ./include/

# ->Files
LIBFT_PRINTF = $(LIB_FOLDER)libft_printf.a
SRCS_SERVER = $(addprefix $(SRC_FOLDER_SERVER), \
	server.c)

SRCS_CLIENT = $(addprefix $(SRC_FOLDER_CLIENT), \
	client.c)
	
# Object files
OBJS_SERVER = $(SRCS_SERVER:$(SRC_FOLDER_SERVER)%.c=$(OBJS_FOLDER_SERVER)%.o)
OBJS_CLIENT = $(SRCS_CLIENT:$(SRC_FOLDER_CLIENT)%.c=$(OBJS_FOLDER_CLIENT)%.o)


# TARGETS
.PHONY:	$(NAME) $(NAME_SERVER) $(NAME_CLIENT) all clean fclean re norm

all: $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT_PRINTF) $(OBJS_SERVER)
	@$(CC) $(OBJS_SERVER) $(CFLAGS) -D DEBUG=$(DEBUG) $(CLIBS) $(CINCLUDES) -o $(NAME_SERVER)
	@echo "$(GREEN)\n$(NAME_SERVER): created$(RESET)"

$(NAME_CLIENT): $(LIBFT_PRINTF) $(OBJS_CLIENT)
	@$(CC) $(OBJS_CLIENT) $(CFLAGS) -D DEBUG=$(DEBUG) $(CLIBS) $(CINCLUDES) -o $(NAME_CLIENT)
	@echo "$(GREEN)\n$(NAME_CLIENT): created$(RESET)"

$(OBJS_FOLDER_SERVER)%.o: $(SRC_FOLDER_SERVER)%.c
	@mkdir -p $(@D)
	@echo -n "$(ORANGE).$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_FOLDER_CLIENT)%.o: $(SRC_FOLDER_CLIENT)%.c
	@mkdir -p $(@D)
	@echo -n "$(ORANGE).$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PRINTF):
	@echo "$(ORANGE)\ncompiling: $(LIBFT_PRINTF)\n$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIB_FOLDER) DEBUG=$(DEBUG)

clean:
	@$(RM) $(OBJS_SERVER)
	@echo "$(RED)$(NAME_SERVER): cleaned object files$(RESET)"
	@$(RM) $(OBJS_CLIENT)
	@echo "$(RED)$(NAME_CLIENT): cleaned object files$(RESET)"

fclean: clean
	@make --no-print-directory -C $(LIB_FOLDER) fclean
	@$(RM) $(NAME_SERVER)
	@echo "$(RED)$(NAME_SERVER): cleaned program$(RESET)"
	@$(RM) $(NAME_CLIENT)
	@echo "$(RED)$(NAME_CLIENT): cleaned program$(RESET)"

re: fclean all

norm:
	@norminette
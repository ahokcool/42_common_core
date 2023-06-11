# Makefile for ft_printf

# Compiler options
CC = cc
CFLAGS =  -Wall -Werror -Wextra 
RM = rm -f

# VARIABLES
NAME = libftprintf.a

# ->Folders
SRC_FOLDER = src/
LIB_FOLDER = lib/

# ->Files
LIBFT = $(LIB_FOLDER)libft.a
SRCS = \
	$(SRC_FOLDER)ft_printf.c \
	$(SRC_FOLDER)print_char.c \
	$(SRC_FOLDER)print_str.c \
	$(SRC_FOLDER)print_dez_to_hexa.c \
	$(SRC_FOLDER)print_ptr.c \
	$(SRC_FOLDER)print_nbr.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Targets
.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cp lib/libft.a $@
	ar -crs $@ $(OBJS) 

$(LIBFT):
	make -C $(LIB_FOLDER)
	echo "\nLIBFT compiled!\n"

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT)
	make -C $(LIB_FOLDER) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

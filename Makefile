NAME		= push_swap
BONUS		= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC			= -I. -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

COMMON		= src/fonctions_string_utils.c \
			  src/founction_sort_utils.c \
			  src/founction_sort_utils_1.c \
			  src/operations_1.c \
			  src/operations_2.c \
			  src/operations_3.c \
			  src/operations_4.c \
			  src/parsing.c \
			  src/sort_big.c \
			  src/sort_small.c \
			  src/utils_main.c

SRC			= $(COMMON) push_swap.c
BONUS_SRC	= $(COMMON) bonus/checker.c

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re

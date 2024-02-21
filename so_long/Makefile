NAME = so_long

NAME_bonus = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/parsing/split.c \
		mandatory/parsing/parsing_utils1.c \
		mandatory/parsing/parsing_utils2.c \
		mandatory/parsing/parsing_utils3.c \
		mandatory/parsing/parsing.c \
		mandatory/get_next_line.c \
		mandatory/get_next_line_utils.c \
		mandatory/moves.c \
		mandatory/moves_utils.c \
		mandatory/so_long.c \
		mandatory/main.c \
		mandatory/ft_printf.c \
		mandatory/ft_printf_utils.c \

SRC_bonus = bonus/parsing_bonus/split_bonus.c \
			bonus/parsing_bonus/itoa_bonus.c \
			bonus/parsing_bonus/parsing_utils1_bonus.c \
			bonus/parsing_bonus/parsing_utils2_bonus.c \
			bonus/parsing_bonus/parsing_utils3_bonus.c \
			bonus/parsing_bonus/parsing_bonus.c \
			bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c \
			bonus/moves_bonus.c \
			bonus/moves_utils_bonus.c \
			bonus/so_long_bonus.c \
			bonus/main_bonus.c \
			bonus/ft_printf_bonus.c \
			bonus/ft_printf_utils_bonus.c \


OBJ = $(SRC:.c=.o)

OBJ_bonus = $(SRC_bonus:.c=.o)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c mandatory/so_long.h  bonus/so_long_bonus.h
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME_bonus): $(OBJ_bonus)
	@ $(CC) $(CFLAGS) $(OBJ_bonus) -o $(NAME_bonus) -lmlx -framework OpenGL -framework AppKit

bonus: $(NAME_bonus)

clean:
	@ rm -rf $(OBJ) $(OBJ_bonus)

fclean: clean
	@ rm -rf $(NAME) $(NAME_bonus)

re: fclean all
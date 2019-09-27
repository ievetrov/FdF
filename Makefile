
NAME = fdf

SRCS = srcs/ft_build_mlx.c \
	   srcs/ft_get_map.c \
	   srcs/ft_add.c \
	   srcs/ft_add2.c \
	   srcs/ft_draw_pixel.c \
	   srcs/ft_print_img.c \
	   srcs/main.c \

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a
	echo "Fdf done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

NAME = so_long
CC = gcc
SRCS = ft_printf/ft_hex.c ft_printf/ft_pointer.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_uns.c ft_printf/ft_uphex.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c map_animation.c map_decore.c map_decore2.c map_file.c map_image.c map_key_move.c so_long.c so_long_utils.c so_long_utils2.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c    
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)    
	make -C ./mlx
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f libmlx.a 
	rm -f $(OBJS)   

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(NAME)   
    
re: fclean all

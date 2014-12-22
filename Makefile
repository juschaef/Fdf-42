NAME = FdF
SRC = {main,draw,calculs,mlx,parsing,utils,zoom_option}.c
SRC += {make_point,move_option,projection,mouse,rotate}.c
SRC += {display,hook}.c
LIB_H = -I libft/
LIB = libft/libft.a
FLAG = -L /usr/X11/lib -lmlx -lXext -lX11
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc -Wall -Wextra -Werror -c $(LIB_H) $(SRC) $(FLAG) 
	gcc -Wall -Wextra -Werror -g $(OBJ) $(LIB_H) $(LIB) $(FLAG) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 11:43:01 by mboy              #+#    #+#              #
#    Updated: 2021/09/14 11:43:02 by mboy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC		=	so_long

CC			=	gcc
RM			= 	rm -f
FLAG		=	-Wall -Werror -Wextra

LIBFT_DIR	=	./ToolBox/Libft
LIBFT_EXEC	=	./ToolBox/Libft/libft

MLX_DIR		=	./ToolBox/MiniLibX
MLX_EXEC	=	./ToolBox/MiniLibX/libmlx.a
MLX_LIB		=	$(MLX_EXEC) -framework OpenGL -framework AppKit -lm

SRC			=	./Sources/main.c\
				./Sources/solong.c\
				./Sources/init.c\
				./Sources/parse.c\
				./Sources/text.c\
				./Sources/draw.c\
				./Sources/key.c\
				./Sources/map.c\
				./Sources/player.c\
				./Sources/collect.c
OBJ			=	$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(FLAG) $(LIBFT_EXEC) $(MLX_LIB) $(SRC) -o $(EXEC)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re

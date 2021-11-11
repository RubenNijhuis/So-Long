# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/11 13:21:32 by rnijhuis      #+#    #+#                  #
#    Updated: 2021/11/11 13:22:25 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILES = main.c\

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

CC = gcc

COMPILE = $(CC) $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -Imlx $(CFLAGS) $(FILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	make -C get_next_line

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"

fclean: clean
	rm -rf $(NAME)

re: fclean all

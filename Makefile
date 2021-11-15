# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/11 13:21:32 by rnijhuis      #+#    #+#                  #
#    Updated: 2021/11/15 15:17:52 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
SRC_DIR := src
BIN_DIR := ./bin/

SRCS := src/main.c\

INCLUDES := ./includes/libft.a\
			./includes/get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

$(NAME): $(OBJS) ./includes/so_long.h
	@$(CC) $(SRCS) $(INCLUDES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BIN_DIR)$(NAME)

libft:
	@make -C ./libs/LibFT/src
	@mv ./libs/LibFT/src/libft.a ./libs/include
	@echo "📦 Moving libft to 'includes'"

get_next_line:
	@make -C ./libs/Get-Next-Line/src
	@mv ./libs/Get-Next-Line/src/get_next_line.a ./libs/include
	@echo "📦 Moving get-next-line to 'includes'"

run:
	./bin/so_long

all: libft get_next_line

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"

fclean: clean
	rm -rf ./bin/$(NAME)


re: fclean all

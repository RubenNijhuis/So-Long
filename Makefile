# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/11 13:21:32 by rnijhuis      #+#    #+#                  #
#    Updated: 2021/11/19 12:44:59 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
INCLUDE_DIR := include
SRC_DIR := src
BIN_DIR := ./bin/

SRCS := src/main.c\
		src/render.c\
		src/exit_strategy.c\
		src/map/utils.c\
		src/map/validation.c\
		src/initialize_data.c\

INCLUDES := ./include/libft.a\
			./include/get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

$(NAME): $(OBJS) ./include/so_long.h
	@$(COMPILE) $(SRCS) $(INCLUDES) -I $(INCLUDE_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BIN_DIR)$(NAME)

libft:
	@make -C ./libs/LibFT/src
	@mv ./libs/LibFT/src/libft.a ./include
	@cp ./libs/LibFT/src/libft.h ./include
	@echo "📦 Moving libft to 'include'"

get_next_line:
	@make -C ./libs/Get-Next-Line/src
	@mv ./libs/Get-Next-Line/src/get_next_line.a ./include
	@cp ./libs/Get-Next-Line/src/get_next_line.h ./include
	@echo "📦 Moving get-next-line to 'include'"

mlx:
	@make -C ./mlx
	@cp ./mlx/mlx.h ./include
	@echo "📦 Moving mlx to 'include'"

run:
	./bin/so_long assets/map1.ber

all: libft get_next_line mlx

clean:
	@rm -rf $(OBJS)
	@echo "🧹 Removing object files"

fclean: clean
	@rm -rf ./bin/$(NAME)
	@echo "🧹 Removing $(NAME) executable"

re: fclean all

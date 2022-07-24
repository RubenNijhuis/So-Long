# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mjoosten <mjoosten@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/12 11:05:57 by rnijhuis      #+#    #+#                  #
#    Updated: 2022/07/24 13:18:29 by rubennijhui   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

EXEC_NAME := so_long

INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libs
OBJS_DIR := objs
BIN_DIR := bin

NAME			:=	$(BIN_DIR)/$(EXEC_NAME)

#=====================================#
#============ Input files ============#
#=====================================#

HEADERS			:=	$(wildcard $(INCLUDE_DIR)/*.h)

LIBS := $(LIBS_DIR)/LibFT/libft.a \
		$(LIBS_DIR)/Get-Next-Line/get-next-line.a \
		$(LIBS_DIR)/mlx/libmlx.a \

LIBS_HEADERS :=	-I $(INCLUDE_DIR) \
				-I $(LIBS_DIR)/LibFT/include/ \
				-I $(LIBS_DIR)/Get-Next-Line/include/ \
				-I $(LIBS_DIR)/mlx \

SRCS := src/render.c \
		src/initialization/initialize_data.c \
		src/initialization/initialize_images.c \
		src/exit_strategy.c \
		src/map/validation.c \
		src/map/set_values.c \
		src/map/utils.c \
		src/main.c \
		src/player/render.c \
		src/player/movement.c \

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

INC := $(LIBS_HEADERS)

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -framework OpenGL -framework AppKit

#=====================================#
#=============== Rules ===============#
#=====================================#

$(OBJS_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(INC) -o $@ $<
	@echo "🔨 Compiling: $<"
	
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LDFLAGS) $(LIBS) $(MLX) -g -fsanitize=address -o $(NAME)
	@echo "✅ Built $(NAME)"

submodules:
	@git submodule update --init --recursive

run: $(NAME)
	@./$(NAME) $(INPUT_FILE)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBS_DIR)/LibFT
	@make fclean -C $(LIBS_DIR)/Get-Next-Line
	@make  clean -C $(LIBS_DIR)/mlx
	@rm -f $(NAME)

re: fclean all

#=====================================#
#=============== Libs ================#
#=====================================#

$(LIBS_DIR)/LibFT/libft.a:
	@make -C $(LIBS_DIR)/libft

$(LIBS_DIR)/Get-Next-Line/get-next-line.a:
	@make -C $(LIBS_DIR)/Get-Next-Line

$(LIBS_DIR)/mlx/libmlx.a:
	@make -C $(LIBS_DIR)/mlx

#=====================================#
#=============== Misc ================#
#=====================================#

.PHONY: all re run clean fclean

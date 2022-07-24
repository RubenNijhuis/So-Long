# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/12 15:41:57 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/06/28 13:15:04 by rubennijhui   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

NAME := libft
INCLUDE_DIR := include
SRC_DIR := src
OBJS_DIR := objs
OUTPUT := $(NAME).a

#=====================================#
#============ Input files ============#
#=====================================#

INC = -I $(INCLUDE_DIR)

SRCS =  misc/ft_free_2d_array.c \
		misc/ft_nbrlen.c \
		misc/ft_error.c \
		misc/ft_2d_arrlen.c \
		\
		memory/ft_memcmp.c \
		memory/ft_bzero.c \
		memory/ft_memcpy.c \
		memory/ft_memchr.c \
		memory/ft_memset.c \
		memory/ft_memmove.c \
		memory/ft_calloc.c \
		\
		is_type/ft_isdigit.c \
		is_type/ft_isascii.c \
		is_type/ft_isprint.c \
		is_type/ft_isalpha.c \
		is_type/ft_isalnum.c \
		\
		linked_list/ft_lstadd_back.c \
		linked_list/ft_lstnew.c \
		linked_list/ft_lstlast.c \
		linked_list/ft_lstclear.c \
		linked_list/ft_lstiter.c \
		linked_list/ft_lstmap.c \
		linked_list/ft_lstsize.c \
		linked_list/ft_lstadd_front.c \
		linked_list/ft_lstdelone.c \
		\
		conversion/ft_atoi.c \
		conversion/ft_itoa.c \
		\
		string/ft_strnstr.c \
		string/ft_putstr_fd.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_putnbr_fd.c \
		string/ft_strchr.c \
		string/ft_striteri.c \
		string/ft_strjoin.c \
		string/ft_putendl_fd.c \
		string/ft_toupper.c \
		string/ft_split.c \
		string/ft_strrchr.c \
		string/ft_putchar_fd.c \
		string/ft_substr.c \
		string/ft_strncmp.c \
		string/ft_strmapi.c \
		string/ft_strtrim.c \
		string/ft_strlcat.c \
		string/ft_strdup.c \
		string/ft_tolower.c \
		string/ft_isinset.c \
		string/ft_str_contains_char.c \
		string/ft_strtolower.c \
		string/ft_strtoupper.c \
		string/ft_repl_chr.c \
		string/ft_str_occur.c \

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Wextra -g $(INC)
LDFLAGS = 

#=====================================#
#=============== Rules ===============#
#=====================================#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "🔨 Compiling: $^"

all: $(NAME)

$(NAME): $(OUTPUT)

$(OUTPUT): $(OBJS)
	@ar -cr $@ $^
	@echo "✅ Built $(NAME) \n"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Done cleaning objects"

get_src_files:
	@find $(SRC_DIR) | cut -b 5-

test:
	@make run -C tests/

fclean: clean
	@rm -f $(NAME).a
	@make fclean -C tests/
	@echo "🧹 Done cleaning archive"

norm:
	@echo "\033[92m========= $(NAME) norm ========\033[0m"
	@-norminette $(INCLUDE_DIR)
	@-norminette $(SRC_DIR)
	@echo "\033[92m========= $(NAME) norm ========\033[0m"

re: fclean all

.PHONY: all clean fclean re 

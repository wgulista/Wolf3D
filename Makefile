# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgulista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/12 16:11:57 by wgulista          #+#    #+#              #
#    Updated: 2016/07/20 15:50:13 by                  ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = wolf3d
LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a
SRC_NAME = main.c env.c error.c expose_hook.c key_hook.c move.c map.c \
			display.c features.c key_release.c wolf3d.c move2.c
OBJ_PATH = obj
SRC_PATH = srcs
HEADER = includes/wolf3d.h
INC = -I includes -I libft/includes
CFLAGS = -Wall -Wextra -Werror

OBJ = $(OBJ_PATH)/display.o \
	$(OBJ_PATH)/env.o \
	$(OBJ_PATH)/error.o \
	$(OBJ_PATH)/expose_hook.o \
	$(OBJ_PATH)/features.o \
	$(OBJ_PATH)/key_hook.o \
	$(OBJ_PATH)/key_release.o \
	$(OBJ_PATH)/main.o \
	$(OBJ_PATH)/map.o \
	$(OBJ_PATH)/move.o \
	$(OBJ_PATH)/move2.o \
	$(OBJ_PATH)/wolf3d.o

LIBX = -lm -L libft/ -lft -I/usr/local/include -I/usr/local/lib \
	   -L minilibx/ -lmlx -framework OpenGL -framework AppKit

VPATH = srcs

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@make -C ./minilibx/
	@gcc $(LIBX) $(INC) $(OBJ) -o $(NAME)
	@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(OBJ_PATH)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(CFLAGS) $(INC) $< -o $@
	@echo "\033[33mLinking" [ $< ] "\033[0m"

norme:
	@echo "\033[33mNorme LIBFT\033[0m"
	@norminette ./libft/*
	@echo "\n\033[33mNorme includes/wolfd3d.h\033[0m"
	@norminette ./includes/wolf3d.h
	@echo "\n\033[33mNorme sources Wolf3D\033[0m"
	@norminette ./srcs
	@echo "\n\033[33mFICHIER AUTEUR \033[0m"
	@cat -e auteur

clean:
	@rm -fv $(OBJ)
	@rm -Rf $(OBJ_PATH)
	@make clean -C ./libft/
	@make clean -C ./minilibx/
	@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@make fclean -C ./libft/
	@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all

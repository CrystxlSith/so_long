# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crystal <crystal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 19:00:12 by crystal           #+#    #+#              #
#    Updated: 2024/07/12 19:01:21 by crystal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c srcs/errors/errors_end.c srcs/errors/ft_error.c srcs/init/get_map.c srcs/init/init_map.c srcs/inputs/handler.c \
		srcs/inputs/check_map.c srcs/utils/utils.c
			
UNAME := $(shell uname)

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes/
RM = rm -rf
EXEC = so_long
NAME = so_long.a
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
OBJS = $(SRCS:.c=.o)

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
MAGENTA= \033[35m
CYAN   = \033[36m
RESET  = \033[0m
ifeq ($(shell uname), Linux)
	MLX_FLAGS = mlx/libmlx.a mlx/libmlx_Linux.a -lX11 -lXext
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
 

.SILENT:

all: $(MLX_LIB) so_long
# [...]
 
# .c.o:
# 	$(CC) $(CFLAGS) -c -o $(EXEC) $@ $< $(INCLUDES)

so_long: $(NAME) $(OBJS)
	echo "${CYAN}Compiling so_long...${RESET}"
	cc so_long.a libft.a mlx/libmlx.a mlx/libmlx_Linux.a -lX11 -lXext -o so_long
	echo "${GREEN}Succes!!!${RESET}"
$(NAME): $(OBJS)
	echo "${CYAN}Compiling libft...${RESET}"
	$(MAKE) --no-print-directory -C ./libft
	cp libft/libft.a ../so_long
	ar rc $(NAME) $(OBJS)
	mkdir objs
	mv $(OBJS) objs
$(MLX_LIB):
	@make -C $(MLX_DIR)
clean:
	echo "${RED}Cleaning libft && Push_swap...${RESET}"
	$(MAKE) clean --no-print-directory -C ./libft
	$(RM) $(OBJS) objs
	echo "${GREEN}Succes!!!${RESET}"
	
fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	echo "${RED}Cleaning exucutable files...${RESET}"
	$(RM) $(NAME) so_long
	echo "${GREEN}Succes!!!${RESET}"
re: fclean all

.PHONY: all clean fclean re
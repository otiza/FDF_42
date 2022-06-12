# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaaiza <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 17:50:46 by amaaiza           #+#    #+#              #
#    Updated: 2021/09/18 17:51:29 by amaaiza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = minilibx_macos/libmlx.a 

SRC = src/main.c src/draw_cntl.c src/draw.c src/get_board_info.c\
	  src/utils/ft_atoi.c \
	  src/utils/ft_bzero.c \
	  src/utils/ft_calloc.c \
	  src/utils/ft_memcpy.c \
	  src/utils/ft_memset.c \
	  src/utils/ft_strdup.c \
	  src/utils/ft_strlcpy.c \
	  src/utils/ft_strlen.c \
	  src/utils/ft_strsplit.c \
	  src/utils/ft_wdcounter.c \
	  src/utils/gnl.c \
	  src/utils/utils.c

CC = gcc -Wall -Wextra -Werror

all	:	$(NAME)

$(MLX) :
	@make -C minilibx_macos/  
	@make clean -C minilibx_macos/

$(NAME) :	$(SRC) $(MLX)
	$(CC) -o $(NAME) $(SRC) -Iincludes $(MLX) -framework OpenGL -framework AppKit 

re : clean all

clean : 
	rm fdf

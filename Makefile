# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@42seoul.student.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 15:59:55 by shan              #+#    #+#              #
#    Updated: 2022/06/29 16:16:42 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

CC			= gcc
CFLAG		= -Wall -Werror -Wextra

OS			= $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX		= ./mlx
	LINK	= -L $(MLX) -lmlx -framework OpenGL -framework Appkit
else
	MLX		= ./minilibx-linux
	LINK	= -L $(MLX) -lmlx -lXext -lX11 -lm -lbsd
endif

SRC			= so_long.c\
			  ft_split.c\
			  ft_strjoin.c\
			  ft_strlcpy.c\
			  ft_utils.c\
			  map_draw.c\
			  read_map.c\
			  so_long_utils.c\
			  so_long_utils2.c\
			  take_keys.c\

INC			= so_long.h
OBJ			= $(SRC:.c=.o)
all			: $(NAME)

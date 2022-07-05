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
BONUS		= so_long_bonus

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
			ft_split.c \
			ft_strjoin.c \
			ft_strlcpy.c \
			ft_utils.c \
			map_draw.c \
			read_map.c\
			so_long_utils1.c\
			so_long_utils2.c\
			take_keys.c\

SRCB		= so_long_bonus.c\
			ft_split_bonus.c \
			ft_strjoin_bonus.c \
			ft_strlcpy_bonus.c \
			ft_utils_bonus.c \
			map_draw_bonus.c \
			read_map_bonus.c\
			so_long_utils1_bonus.c\
			so_long_utils2_bonus.c\
			take_keys_bonus.c\
			move_enemy.c\
			moves_in_win.c

INC			= so_long.h
INCB		= so_long_bonus.h

OBJ			= $(SRC:.c=.o)
OBJB		= $(SRCB:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJ) $(INC)
			$(CC) $(CFLAG) $(SRC) -o $(NAME) $(LINK)

bonus		: $(BONUS)

$(BONUS)	: $(OBJB) $(INCB)
			$(CC) $(CFLAGS) $(SRCB) -o $(BONUS) $(LINK)

clean		:
			rm -rf $(OBJ)
			rm -fr $(OBJB)

fclean		: clean
			rm -rf $(NAME)
			rm -rf $(BONUS)

re			: fclean all bonus
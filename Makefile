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

SRC			= mandatory/so_long.c\
			mandatory/ft_split.c \
			mandatory/ft_strjoin.c \
			mandatory/ft_strlcpy.c \
			mandatory/ft_utils.c \
			mandatory/map_draw.c \
			mandatory/read_map.c\
			mandatory/so_long_utlis1.c\
			mandatory/so_long_utlis2.c\
			mandatory/take_keys.c\

SRCB		= bonus/so_long_bonus.c\
			bonus/ft_split.c \
			bonus/ft_strjoin.c \
			bonus/ft_strlcpy.c \
			bonus/ft_strlen.c \
			bonus/map_draw_bonus.c \
			bonus/read_map_bonus.c\
			bonus/so_long_bonus_utls1.c\
			bonus/so_long_bonus_utls2.c\
			bonus/take_keys_bonus.c\
			bonus/mouve_enemy.c\
			bonus/mouves_in_win.c

INC			= so_long.h
INCB		= so_long_bonus.h

OBJ			= $(SRC:.c=.o)
OBJB		= $(SRCB:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJ) $(INC)
			$(CC) $(CFLAG) $(MLX) $(SRC) -o $(NAME)

bonus		: $(BONUS)

$(BONUS)	: $(OBJB) $(INCB)
			$(CC) $(CFLAGS) $(MLX) $(SRCB) -o $(BONUS)

clean		:
			@rm -rf $(NAME)
			@rm -fr $(BONUS)

fclean		: clean
			@rm -rf $(NAME)
			@rm -rf $(BONUS)

re			: fclean all bonus
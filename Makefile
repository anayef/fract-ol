# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anayef <anayef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 18:53:26 by anayef            #+#    #+#              #
#    Updated: 2023/07/06 11:56:19 by anayef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fractol
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
HDRS =			fractol.h
SRCS =			main.c fractol.c hook.c fractol_utils.c
OBJS =			$(SRCS:.c=.o)
LIBFT_PATH	=	./libft
MLX_PATH =		./mlx_linux
#MLX_PATH =		./mlx
RM = rm -rf

all: $(NAME)

$(NAME)		:	$(OBJS) $(HDRS)
				make -C $(MLX_PATH)
				make -C $(LIBFT_PATH)
#				$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_PATH) -lft -o $(NAME)
				$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L$(LIBFT_PATH) -lft -o $(NAME)
#.o: %.c
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				make clean -C $(LIBFT_PATH)
				make clean -C $(MLX_PATH)

re			:	fclean all

.PHONY		:	all clean fclean re

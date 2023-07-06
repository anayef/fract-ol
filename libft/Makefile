# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anayef <anayef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 11:57:39 by anayef            #+#    #+#              #
#    Updated: 2023/07/05 20:22:04 by anayef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a

SRCS		= ft_toupper.c \
		  ft_putstr.c \
		  ft_putchar.c \
		  ft_atoi.c \
		  ft_strncmp.c ft_isdigit.c \

OBJS		= $(SRCS:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY		:	all clean fclean re

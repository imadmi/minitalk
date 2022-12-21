# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imimouni <imimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 20:48:26 by imimouni          #+#    #+#              #
#    Updated: 2022/12/20 15:11:18 by imimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS	= ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_calloc.c \
	ft_memcmp.c \
	ft_bzero.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strdup.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_striteri.c \
	ft_printf.c \
	ft_helper.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all
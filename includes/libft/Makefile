# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:00:07 by bgeorges          #+#    #+#              #
#    Updated: 2018/03/27 21:51:31 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
	ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstmap.c ft_lstiter.c \
	ft_lstadd.c ft_lstnew.c \
	ft_lstdel.c ft_lstdelone.c get_next_line.c ft_strclen.c ft_itoa_base_lower.c \
	ft_itoa_base_upper.c ft_strilen.c ft_ulltoa.c ft_ltoa.c \
	ft_ultoa_base_lower.c \
	ft_uitoa_base_lower.c ft_uitoa_base_upper.c ft_ltoa_base_lower.c \
	ft_ltoa_base_upper.c ft_ustoa_base_lower.c ft_ulltoa_base_lower.c \
	ft_ulltoa_base_upper.c ft_ultoa_base_upper.c ft_ustoa_base_upper.c \
	ft_uimtoa_base_lower.c ft_uimtoa_base_upper.c ft_lltoa.c ft_stoa.c \
	ft_str_toupper.c  ft_atoll.c ft_strjoin_free.c ft_strjoin_free_2.c \
	ft_atoi_base.c ft_str_tolower.c ft_strsub_free.c \

OBJ 	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I libft.h
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

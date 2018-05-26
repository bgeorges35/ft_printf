# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 11:16:54 by bgeorges          #+#    #+#              #
#    Updated: 2018/03/29 14:22:27 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
TMP		=	tmp.a

CC		:=	gcc -Wall -Wextra -Werror
FLAGS	:=


SRC 	=	ft_printf.c \
			ft_find_flags.c \
			ft_find_lenght.c \
			ft_find_specifiers.c \
			ft_find_type.c \
			ft_specifier_dec.c \
			ft_specifier_str.c \
			ft_specifier_base.c \
			ft_get_flags_neg_pos_sp.c \
			ft_get_flags_hash_zero.c \
			ft_find_width.c \
			ft_check_specifiers_flags.c \
			ft_dispatcher_flags.c \
			ft_aff_unicode.c \
			ft_change_width.c \
			ft_transform_wchar_in_char.c \

OBJ 	=	$(SRC:.c=.o)

LIB		= 	libft.a
LIB_DIR	=	./includes/libft/
OBJ_PATH =	./obj/
OBJ_DIR =	$(addprefix ./obj/,$(OBJ))
SRC_DIR =	$(addprefix ./src/,$(SRC))

all: $(NAME)
$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(LIB)
	@$(CC) $(FLAGS) -c $(SRC_DIR) -I src/ft_printf.h
	@mv $(OBJ) $(OBJ_PATH)
	ar rcs $(TMP) $(OBJ_DIR)
	libtool -static -o $(NAME) $(TMP) $(LIB_DIR)$(LIB)
	rm -f $(TMP)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	@rm -f $(OBJ_DIR)
	@rm -f $(LIB_DIR)$(LIB)

re: fclean all

.PHONY: all clean fclean re

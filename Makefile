# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 16:36:24 by droly             #+#    #+#              #
#    Updated: 2018/05/18 10:57:53 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

SRC = ft_bzero.s \
	  ft_strcat.s\
	  ft_isalpha.s\
	  ft_isdigit.s\
	  ft_isalnum.s\
	  ft_isascii.s\
	  ft_isprint.s\
	  ft_toupper.s\
	  ft_tolower.s\
	  ft_putstr.s\
	  ft_strlen.s\
	  ft_puts.s\
	  ft_memset.s\
	  ft_memcpy.s\
	  ft_strdup.s\
	  ft_cat.s

OBJ = $(SRC:.s=.o)

FLAGS = -f macho64

.PHONY: clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "compilation libfts.a."

%.o: %.s
		@nasm $(FLAGS) $< -o  $@

clean:
	@rm -f $(OBJ)
	@echo "supression .o ..."

fclean: clean
	@rm -f $(NAME)
	@echo "supression totale..."

re: fclean all

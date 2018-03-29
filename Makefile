# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 16:36:24 by droly             #+#    #+#              #
#    Updated: 2018/03/29 16:45:43 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

SRC = ft_bzero.s

OBJ = $(SRC:.s=.o)

FLAGS = -f macho64

.PHONY: clean fclean re

all: $(NAME)

$(NAME) :
	@nasm $(FLAGS) $(SRC) -o $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "compilation libfts.a."

clean:
	@rm -f $(OBJ)
	@echo "supression .o ..."

fclean: clean
	@rm -f $(NAME)
	@echo "supression totale..."

re: fclean all

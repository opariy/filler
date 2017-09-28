# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opariy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:07:08 by opariy            #+#    #+#              #
#    Updated: 2017/07/23 16:03:00 by opariy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
SOURCE = filler.c get_next_line.c find_and_place.c
OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	gcc libft/*.o $(OBJ) -o ${NAME}

.c.o:
	#gcc -Wall -Wextra -Werror -c -o $@ $<
	gcc -c -o $@ $<

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all


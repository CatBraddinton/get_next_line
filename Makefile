# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 11:08:54 by kdudko            #+#    #+#              #
#    Updated: 2019/02/15 23:03:40 by kdudko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl
FLAGS = -Wall -Wextra -Werror
INCL = -I libft/includes

all: $(NAME)
	
$(NAME): get_next_line.o main.o
	clang -o $(NAME) get_next_line.o main.o $(INCL) -L libft/ -lft
get_next_line.o:
	clang $(FLAGS) $(INCL) -o get_next_line.o -c get_next_line.c

main.o:
	clang $(FLAGS) $(INCL) -o main.o -c main.c

clean:
	rm get_next_line.o main.o $(NAME)

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:35 by gleger            #+#    #+#              #
#    Updated: 2014/01/19 18:11:37 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	room

HEADERS = -I .

SRC =	source.cpp \
		Server.class.cpp \
		Datacenter.class.cpp

OBJ =	$(SRC:.cpp=.o)
 
C++ =	g++ -std=c++11 -g -Wall -Wextra -Werror -O3

%.o:		%.cpp
	@echo "\033[1;36;m[Compiling $<]\t\033[0m: " | tr -d '\n'
	$(C++) -c $< $(HEADERS)

all:		$(NAME)

$(NAME):	$(OBJ) Server.class.hpp Datacenter.class.hpp
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(C++) -o $@ $(OBJ)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean:		clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 22:23:46 by hfiqar            #+#    #+#              #
#    Updated: 2024/05/21 14:34:42 by hfiqar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

FILE_C = client

FILE_S = server

SRC_C = $(FILE_C:=.c)

SRC_S = $(FILE_S=.c)

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

HEADER = minitalk.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_C) $(OBJ_S)
	$(NAME) $(OBJ_C) $(OBJ_S)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "%s .....\r" $@
clean :
	rm -rf $(OBJ_C) $(OBJ_S)

fclean : clean
	rm -rf $(NAME)

re : fclean all

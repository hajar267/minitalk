# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 22:23:46 by hfiqar            #+#    #+#              #
#    Updated: 2024/05/21 20:52:04 by hfiqar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

FILE_C = client

FILE_S = server

SRC_C = $(FILE_C:=.c)

SRC_S = $(FILE_S:=.c)

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

HEADER = minitalk.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
	@$(CC) $(OBJ_C) -o $(NAME_C) $(CFLAGS)
	@printf "%s .....\r" $@

$(NAME_S) : $(OBJ_S)
	@$(CC) $(OBJ_S) -o $(NAME_S) $(CFLAGS)
	@printf "%s .....\r" $@

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "%s .....\r" $@
clean :
	rm -rf $(OBJ_C) $(OBJ_S)

fclean : clean
	rm -rf $(NAME_C) $(NAME_S)

re : fclean all


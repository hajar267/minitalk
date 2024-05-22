# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 22:23:46 by hfiqar            #+#    #+#              #
#    Updated: 2024/05/22 04:05:46 by hfiqar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME_C = client
# NAME_S = server

# FILE_C = client

# FILE_S = server

# FILE_C_B = client_bonus

# FILE_S_B = server_bonus

# SRC_C = $(FILE_C:=.c)
# SRC_C_B = $(FILE_C_B:=.c)

# SRC_S = $(FILE_S:=.c)
# SRC_S_B = $(FILE_S_B:=.c)

# OBJ_C = $(SRC_C:.c=.o)
# OBJ_C_B = $(SRC_C_B:.c=.o)

# OBJ_S = $(SRC_S:.c=.o)
# OBJ_S_B = $(SRC_S_B:.c=.o)

# HEADER = minitalk.h
# HEADER_B = minitalk_bonus.h

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# all : $(NAME_C) $(NAME_S)

# $(NAME_C) : $(OBJ_C)
# 	@$(CC) $(OBJ_C) -o $(NAME_C) $(CFLAGS)
# 	@printf "%s .....\r" $@

# $(NAME_S) : $(OBJ_S)
# 	@$(CC) $(OBJ_S) -o $(NAME_S) $(CFLAGS)
# 	@printf "%s .....\r" $@
	
# bonus : $(NAME_C_B) $(NAME_S_B)

# $(NAME_C_B) : $(OBJ_C_B)
# 	@$(CC) $(OBJ_C_B) -o $(NAME_C_B) $(CFLAGS)
# 	@printf "%s .....\r" $@

# $(NAME_S_B) : $(OBJ_S_B)
# 	@$(CC) $(OBJ_S_B) -o $(NAME_S_B) $(CFLAGS)
# 	@printf "%s .....\r" $@

# %.o : %.c $(HEADER) $(HEADER_B)
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@printf "%s .....\r" $@
# clean :
# 	rm -rf $(OBJ_C) $(OBJ_S)

# fclean : clean
# 	rm -rf $(NAME_C) $(NAME_S)

# re : fclean all

# Variables for the regular versions
NAME_C = client
NAME_S = server
FILE_C = client
FILE_S = server
SRC_C = $(FILE_C:=.c)
SRC_S = $(FILE_S:=.c)
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

# Variables for the bonus versions
NAME_C_B = client_bonus
NAME_S_B = server_bonus
FILE_C_B = client_bonus
FILE_S_B = server_bonus
SRC_C_B = $(FILE_C_B:=.c)
SRC_S_B = $(FILE_S_B:=.c)
OBJ_C_B = $(SRC_C_B:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)

HEADER = minitalk.h
HEADER_B = minitalk_bonus.h
# Common flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target
all: $(NAME_C) $(NAME_S)

# Regular versions compilation
$(NAME_C): $(OBJ_C)
	@$(CC) $(OBJ_C) -o $(NAME_C) $(CFLAGS)
	@echo "$(NAME_C) compiled."

$(NAME_S): $(OBJ_S)
	@$(CC) $(OBJ_S) -o $(NAME_S) $(CFLAGS)
	@echo "$(NAME_S) compiled."

# Bonus versions compilation
bonus: $(NAME_C_B) $(NAME_S_B)

$(NAME_C_B): $(OBJ_C_B)
	@$(CC) $(OBJ_C_B) -o $(NAME_C_B) $(CFLAGS)
	@echo "$(NAME_C_B) compiled."

$(NAME_S_B): $(OBJ_S_B)
	@$(CC) $(OBJ_S_B) -o $(NAME_S_B) $(CFLAGS)
	@echo "$(NAME_S_B) compiled."

# Compilation rules
%.o: %.c $(HEADER) $(HEADER_B)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

# Fclean rule
fclean: clean
	rm -rf $(NAME_C) $(NAME_S) $(NAME_C_B) $(NAME_S_B)

# Rebuild rule
re: fclean all
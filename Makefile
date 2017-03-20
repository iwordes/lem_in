# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwordes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/19 13:37:38 by iwordes           #+#    #+#              #
#    Updated: 2017/03/19 13:38:39 by iwordes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = lem_in
AUTHOR = iwordes

CC     = gcc
CF     = -Wall -Wextra -Werror -I include
CL     = -L "lib/ft" -l "ft" -I lib/ft/include

SRC    = main.c init.c heatmap.c sort.c path.c ps/rooms.c ps/links.c
SRC   := $(addprefix src/,$(SRC))

# ------------------------------------------------------------------------------
# Phony Targets

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build
	make fclean -C "lib/ft"

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

# ------------------------------------------------------------------------------
# Real Targets

$(NAME): $(SRC) lib/ft/libft.a
	$(CC) $(CF) $(CL) -o $@ $^

lib/ft/libft.a:
	make re -C "lib/ft"

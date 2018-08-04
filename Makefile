# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 12:56:02 by ihodge            #+#    #+#              #
#    Updated: 2018/01/07 13:09:07 by ihodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCS = main.c merge_files.c merge_dir.c init.c save_args.c free.c ft_itoa_base.c file_mode.c make_tree.c print_stuff.c
OBJ = ${SRCS:.c=.o}
FLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) $(OBJ) $(LIB) -o $@

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ)
	make clean -C libft

fclean: clean
	rm $(NAME)
	make fclean -C libft

re: fclean all

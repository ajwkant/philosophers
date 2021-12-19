# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akant <akant@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/09 16:01:19 by akant         #+#    #+#                  #
#    Updated: 2021/12/16 17:08:14 by akant         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
SRCS =	main.c ft_atoi.c init.c time.c eat.c sleep.c lock.c die.c

OBJ = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror -I ./includes
VPATH = ./srcs
CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

$(NAME): $(OBJ)
	# $(CC) -fsanitize=address $(OBJ) $(FLAGS) -lpthread -o $(NAME)
	$(CC) $(OBJ) $(FLAGS) -lpthread -o $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
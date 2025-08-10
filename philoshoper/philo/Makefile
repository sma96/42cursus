# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sma <sma@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:02:11 by sma               #+#    #+#              #
#    Updated: 2021/07/19 16:52:39 by sma              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
BONUS_NAME = philo_bonus

SRCS		=./philo.c\
			./philo_utils.c\
			./philo_utils_2.c\
			./dinner_time.c\
			./init_info.c		

OBJS		= $(SRCS:.c=.o)

RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I . -o $(NAME) -lpthread

all : $(NAME)
		
fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all
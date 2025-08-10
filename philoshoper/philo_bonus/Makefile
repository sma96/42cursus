# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sma <sma@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 14:02:11 by sma               #+#    #+#              #
#    Updated: 2021/07/19 17:06:12 by sma              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
BONUS_NAME 	= philo_bonus

BONUS_SRCS	=./philo_bonus.c\
			./philo_utils_bonus.c\
			./philo_utils_2_bonus.c\
			./dinner_time_bonus.c\
			./init_info_bonus.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -I . -o $(BONUS_NAME) -lpthread

all : $(BONUS_NAME)

fclean : clean
	$(RM) $(BONUS_NAME)

clean :
	$(RM) $(BONUS_OBJS)

re : fclean all
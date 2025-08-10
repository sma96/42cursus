NAME		= megaphone

SRCS		=./megaphone.cpp	

OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f
CXX			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CXX) $(CCFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all
NAME		= ex01

SRCS		= main.cpp\
			Animal.cpp\
			Cat.cpp\
			Dog.cpp\
			Brain.cpp

OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I . $(OBJS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all
NAME		= ex03

SRCS		= main.cpp\
			AMteria.cpp\
			Cure.cpp\
			Ice.cpp\
			MteriaSource.cpp\
			Character.cpp

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
NAME		= ex03

SRCS		= main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\
			DiamondTrap.cpp

OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I . $(OBJS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all
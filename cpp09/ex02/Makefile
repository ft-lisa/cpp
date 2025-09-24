NAME    = PmergeMe
SRCS    = main.cpp \
		PmergeMe.cpp

OBJS    = $(SRCS:.cpp=.o)
CXX     = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 -O3

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
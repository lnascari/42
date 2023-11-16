FILES = BitcoinExchange.cpp

OBJ = $(FILES:.cpp=.o)

NAME = bitcoinexchange

$(NAME): main.cpp $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	c++ -c -Wall -Wextra -Werror -std=c++98 $(@:.o=.cpp)

all: $(NAME)

clean:
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
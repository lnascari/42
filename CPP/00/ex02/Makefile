FILES =  Account.cpp

OBJ = $(FILES:.cpp=.o)

NAME = account

$(NAME): tests.cpp $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 tests.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	c++ -c -Wall -Wextra -Werror -std=c++98 $(@:.o=.cpp)

clean:
	rm -f ./*.o
	rm -f $(NAME)
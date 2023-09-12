FILES = 

OBJ = $(FILES:.cpp=.o)

NAME = 

$(NAME): main.cpp $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	c++ -c -Wall -Wextra -Werror -std=c++98 $(@:.o=.cpp)

clean:
	rm -f ./*.o
	rm -f $(NAME)
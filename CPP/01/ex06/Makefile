FILES = Harl.cpp

OBJ = $(FILES:.cpp=.o)

NAME = harlFilter

$(NAME): main.cpp $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 -Wno-implicit-fallthrough main.cpp $(OBJ) -o $(NAME)

%.o: %.cpp %.hpp
	c++ -c -Wall -Wextra -Werror -std=c++98 $(@:.o=.cpp)

clean:
	rm -f ./*.o
	rm -f $(NAME)
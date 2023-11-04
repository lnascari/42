HEADERS = Base.hpp A.hpp B.hpp C.hpp

NAME = convert

$(NAME): main.cpp $(HEADERS)
	c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o $(NAME)

clean:
	rm -f $(NAME)
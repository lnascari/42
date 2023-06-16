FILES =  Contact.cpp PhoneBook.cpp

OBJ = $(FILES:.cpp=.o)

HEADERS = Contact.hpp PhoneBook.hpp

NAME = phonebook

$(NAME): main.cpp $(OBJ) $(HEADERS)
	c++ -Wall -Wextra -Werror -std=c++98 main.cpp $(OBJ) -o $(NAME)

%.o: %.c
	c++ -c -Wall -Wextra -Werror -std=c++98 $?

clean:
	rm -f ./*.o
	rm -f $(NAME)
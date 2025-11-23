NAME = fixed3
SRC = Fixed.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
MLINK = -lm
RM = rm -f

%.o: %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLINK) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
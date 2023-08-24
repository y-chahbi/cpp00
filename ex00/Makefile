NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRC_N = megaphone.cpp
OBJ_N = $(SRC_N:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ_N)
		$(CC)  $(CFLAGS) $< -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ_N) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
NAME	=		main
CC		= 		c++
CFLAGS	= 		-Wall -Wextra -Werror -std=c++98 

SRC		=		main.cpp Span.cpp

OBJ		= 		$(SRC:%.cpp=%.o)


all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $^ -o $@
%.o: %.cpp
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJ) 

fclean: 		clean
				rm -rf $(NAME)


re: fclean all

.PHONY: all re clean fclean

NAME 	=	PmergeMe

SRC     =	src/main.cpp 		\
			src/PmergeMe.cpp 	\
			src/VectorMerge.cpp \
			src/DequeMerge.cpp

CC		=	g++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADER	=	src/PmergeMe.hpp

OBJECTS	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		@echo "\033[0;33mCompiling..."
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@echo "\033[0m"

.cpp.o:
		@echo "\033[0;32mGenerating obj..."
		$(CC) $(CFLAGS) -c -o $@ $<
		@echo "\033[0m"

clean:
		@echo "\033[0;31mCleaning..."
		@$(RM) -f $(OBJECTS)
		@echo "maked clean"
		@echo "\033[0m"

fclean: clean
		@echo "\033[0;31mRemoving executable..."
		@$(RM) -f $(NAME)
		@echo "maked fclean"
		@echo "\033[0m"

re:			fclean all

.PHONY: all clean fclean re

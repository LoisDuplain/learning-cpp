NAME			=	unnecessary-violence

INCS			=	Weapon.hpp	\
					HumanA.hpp	\
					HumanB.hpp

SRCS			=	main.cpp	\
					Weapon.cpp	\
					HumanA.cpp	\
					HumanB.cpp

COMPILED_DIR	=	./compiled_sources
OBJS			=	$(addprefix $(COMPILED_DIR)/,$(SRCS:.cpp=.o))

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(COMPILED_DIR):
	mkdir -p $(COMPILED_DIR)

$(COMPILED_DIR)/%.o:%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(COMPILED_DIR) $(INCS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(COMPILED_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
NAME			=	clap-trap

INCS			=	ClapTrap.hpp	\
					ScavTrap.hpp	\
					FragTrap.hpp

SRCS			=	main.cpp		\
					ClapTrap.cpp	\
					ScavTrap.cpp	\
					FragTrap.cpp

COMPILED_DIR	=	./compiled_sources
OBJS			=	$(addprefix $(COMPILED_DIR)/,$(SRCS:.cpp=.o))

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(COMPILED_DIR):
	mkdir -p $(COMPILED_DIR)

$(COMPILED_DIR)/%.o:%.cpp	$(INCS)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(COMPILED_DIR) $(INCS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(COMPILED_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
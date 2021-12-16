NAME			=	bureaucrat

INCS			=	AForm.hpp					\
					Bureaucrat.hpp				\
					PresidentialPardonForm.hpp	\
					RobotomyRequestForm.hpp		\
					ShrubberyCreationForm.hpp	\
					Intern.hpp

SRCS			=	main.cpp					\
					AForm.cpp					\
					Bureaucrat.cpp				\
					PresidentialPardonForm.cpp	\
					RobotomyRequestForm.cpp		\
					ShrubberyCreationForm.cpp	\
					Intern.cpp

COMPILED_DIR	=	./compiled_sources
OBJS			=	$(addprefix $(COMPILED_DIR)/,$(SRCS:.cpp=.o))

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

all: $(NAME)

$(COMPILED_DIR):
	mkdir -p $(COMPILED_DIR)

$(COMPILED_DIR)/%.o:%.cpp	$(INCS)
	mkdir -p $(@D)	
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(COMPILED_DIR) $(INCS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(COMPILED_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
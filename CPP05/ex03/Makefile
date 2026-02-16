NAME 					= ex03

C++						= c++ -std=c++98

STD_FLAGS 				= -Wall -Wextra -Werror

SRCS					= main.cpp \
						  Bureaucrat.cpp \
						  AForm.cpp \
						  ShrubberyCreationForm.cpp \
						  RobotomyRequestForm.cpp \
						  PresidentialPardonForm.cpp \
						  Intern.cpp
						  						  
OBJS					= ${SRCS:.cpp=.o}

REMOVE					= rm -f ${OBJS}

all:					${NAME}

${NAME}:
						${C++} ${SRCS} ${STD_FLAGS} -o ${NAME}

clean:					
						${REMOVE}

fclean:					clean
						rm -f ex03
						
re:						fclean all

.PHONY:					all clean fclean re
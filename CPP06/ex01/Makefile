NAME 					= ex01

C++						= c++ -std=c++98

STD_FLAGS 				= -Wall -Wextra -Werror

SRCS					= main.cpp \
						  Serializer.cpp
						  						  
OBJS					= ${SRCS:.cpp=.o}

REMOVE					= rm -f ${OBJS}

all:					${NAME}

${NAME}:
						${C++} ${SRCS} ${STD_FLAGS} -o ${NAME}

clean:					
						${REMOVE}

fclean:					clean
						rm -f ex01
						
re:						fclean all

.PHONY:					all clean fclean re
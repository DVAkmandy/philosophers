NAME	= philo
HEADER	= philosophers.h

LIST		= philo.c checker.c life_philo.c mutex_threads.c utils_0.c utils_1.c

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			gcc $(OBJ) -o $(NAME)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)
debug:
		gcc -g ${LIST} -o philo
re :		fclean all

.PHONY :	all clean fclean re
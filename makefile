NAME = philosophers

SRC = philosophers.c \
		utils.c \
		lists.c \
		to_do.c \

OBJ = $(SRC:.c=.o)

RM = rm -rf

CC = cc

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c philosophers.h
	@$(CC) $(FLAGS) $< -c -o $@ -g

$(NAME) : $(OBJ) philosophers.h
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -g

clean : $(OBJ) $(OBJ_B)
	@$(RM) $(OBJ) $(OBJB)

fclean :
	@$(RM) $(NAME) $(OBJ_B) $(OBJ)

re : fclean all

.PHONY : re clean fclean all
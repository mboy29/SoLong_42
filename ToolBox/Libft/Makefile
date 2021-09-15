NAME 		= 	libft

TEST		= 	./Tester/main.c

MYLIBFT 	=	Sources/ft_isalpha.c\
				Sources/ft_str_isalpha.c\
				Sources/ft_isdigit.c\
				Sources/ft_str_isdigit.c\
				Sources/ft_isalnum.c\
				Sources/ft_str_isalnum.c\
				Sources/ft_itoa.c\
				Sources/ft_atoi.c\
				Sources/ft_split.c\
				Sources/ft_strlen.c\
				Sources/ft_nblen.c\
				Sources/ft_strdup.c\
				Sources/ft_strjoin.c\
				Sources/ft_tolower.c\
				Sources/ft_toupper.c\
				Sources/ft_putchar.c\
				Sources/ft_putstr.c\
				Sources/ft_putnbr.c

GNL			=	Sources/GNL/gnl.c

TESTOBJ		= $(TEST:.c=.o)
MYOBJ 		= $(MYLIBFT:.c=.o)
GNLOBJ		= $(GNL:.c=.o)


CC			=	gcc
RM 			=	rm -f
FLAGS		= 	-Wall -Werror -Wextra -g -fsanitize=address

all : $(NAME) 

$(NAME) : $(MYOBJ) $(GNLOBJ)
	ar rcs $(NAME) $(MYOBJ) $(GNLOBJ)

test : $(TESTOBJ) $(MYOBJ) $(GNLOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(TESTOBJ) $(MYOBJ) $(GNLOBJ)

clean :
	rm -rf $(MYOBJ) $(OBJB) $(GNLOBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re test

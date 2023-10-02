NAME=libftprintf.a

COMPILER=cc
FLAGS=-Wall -Wextra -Werror

FILES=main.c put_basic.c
BNS_FILES= 

OBJS=$(FILES:.c=.o)
BNS_OBJS=$(BNS_FILES:.c=.o)

all: $(NAME)

%.o : %.c
	$(COMPILER) $(FLAGS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS) $(BNS_OBJS)

fclean:
	rm -fr $(OBJS) $(BNS_OBJS) libft.a

re: fclean all

bonus: $(OBJS) $(BNS_OBJS)
	ar rc $(NAME) $(OBJS) $(BNS_OBJS)

.PHONY: clean re fclean all bonus
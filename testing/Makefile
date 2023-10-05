NAME=test

$(NAME): ../libftprintf.a
	cc -Wall -Wextra -Werror test.c -o $(NAME) -L.. -lftprintf

clean:
	rm -fr test

re: clean $(NAME)
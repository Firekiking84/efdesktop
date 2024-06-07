NAME =			efDesktop

SRC =			$(wildcard ./src/*.c)		\
			$(wildcard ./src/*/*.c)		\

OBJS =			$(SRC:.c=.o)

LIB_OBJS =		$(LIB_SRC:.c=.o)

INCLUDE =		-I./include

CC =			bcc

FLAGS =			-Wall -Wextra -g -ggdb

LDFLAGS =		-L./ -rdynamic

all:$(NAME)

$(NAME):$(OBJS)
			$(CC) $(OBJS) -O0 $(LDFLAGS) -o $(NAME)
.c.o:
			$(CC) $(FLAGS) -O0 $(INCLUDE) -c $< -o $@
ar:$(OBJS)
			ar rc $(NAME).a $(OBJS)
g:
			gdb --arg ./$(NAME)
clean:
			rm -f $(shell find ./ -name "*.o")
			rm -f $(shell find ./ -name "*~")
			rm -f $(shell find ./ -name "*.gcda")
			rm -f $(shell find ./ -name "*.gcno")
			rm -f $(shell find ./ -name "*#")
			rm -f $(shell find ./ -name "*#")
fclean: clean
			rm -f $(NAME)
re: fclean all

test: fclean

tree: fclean
			tree

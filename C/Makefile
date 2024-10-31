CC=gcc
CFLAGS=-Wall -Wextra -g -fsanitize=address
LIB= -fsanitize=address

SRC=todo.c \
	verif.c \
	color.c
OBJ=$(SRC:.c=.o)

todo: $(OBJ)
	$(CC) -o todo $+ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm todo *.o data

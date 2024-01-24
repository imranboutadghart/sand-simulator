CC := cc
LIB := -lX11 -lXext -lmlx
CFLAGS := -Wall -Wextra
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, bin/%.o, $(SRC))
NAME := automata

all : $(NAME)

bin/%.o : src/%.c src/automata.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)

debug : CFLAGS += -g
debug : fclean $(NAME)
	gdb ./$(NAME)

test : $(NAME)
	./$(NAME)
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

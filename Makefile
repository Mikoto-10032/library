#ifdef DEBUG
    #define debug(...) printf(__VA__ARGS)
#else
    #define debug(...)
#endif
CC=gcc
OBJ=main.o library.o reader.o manager.o editor.o admin.o menu.o tools.o list.o
BIN=Library
STD=-std=gnu99
INCLUDE=-I.
FLAG=-Wall -Werror -DDEBUG
LIB=-lm

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LIB)
%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@ $(INCLUDE)
clean:
	rm -rf $(BIN) $(OBJ)

CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -g
SRC=src/main.c src/inventory_array.c src/inventory_list.c src/sort_search.c
OUT=survival

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT) *.o

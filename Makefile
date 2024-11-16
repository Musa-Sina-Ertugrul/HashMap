INCLUDE_DIR = include

SRC_DIR = src

all: hashmap.so

hashmap.so : $(SRC_DIR)/hashmap.c $(INCLUDE_DIR)/hashmap.h
	gcc -g -Wall -Wextra -Wparentheses -I$(INCLUDE_DIR) -c -fPIC $(SRC_DIR)/*.c -o hashmap.o
	gcc hashmap.o -shared -o libhashmap.so
	gcc -o main main.c -L. -lhashmap -I$(INCLUDE_DIR) -Wl,-rpath=.

clean:
	rm -rf hashmap.o hashmap.so

INCLUDE_DIR = include

SRC_DIR = src

all: hashmap.so

hashmap.so : $(SRC_DIR)/hashmap.c $(INCLUDE_DIR)/hashmap.h
	gcc -g -Wall -Wextra -Wparentheses -I$(INCLUDE_DIR) -c -fPIC $(SRC_DIR)/*.c -o hashmap.o
	gcc hashmap.o -shared -o libhasmap.so

clean:
	rm -rf hashmap.o hashmap.so

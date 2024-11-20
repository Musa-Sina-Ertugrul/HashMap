INCLUDE_DIR = include

SRC_DIR = src

all: hashmap.so

hashmap.so : $(SRC_DIR)/hashmap.c $(INCLUDE_DIR)/hashmap.h
	gcc -DSUPER  -g -Wall -Wextra -Wparentheses -I$(INCLUDE_DIR) -c -fPIC $(SRC_DIR)/*.c -o hashmap.o
	gcc hashmap.o -shared -o libhashmap.so
	gcc -g -o main main.c -DSUPER -L. -lhashmap -I$(INCLUDE_DIR) -Wl,-rpath=.

clean:
	rm -rf hashmap.o libhashmap.so



#ifndef HASHMAP
#define HASHMAP

#include <stdlib.h>

typedef struct {
  void* structer;
  char* name;
} node_t;

typedef struct {
  node_t** map;
  size_t map_size;
  int item_count;
} hashmap_t;

size_t hashing(const char* name, size_t map_size);

int contains(const char* name,hashmap_t* map);

int put(node_t* node,hashmap_t* map);

node_t* get(const char* node_name,hashmap_t* map);


#endif

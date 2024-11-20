

#ifndef HASHMAP
#define HASHMAP

#include <stdlib.h>

typedef struct {
  void* structer;
  char* name;
} node_t;

typedef struct {
  node_t** map;
  size_t size;
} hashmap_t;

size_t hashing(const char* name, size_t map_size);

int contains(const char* name, hashmap_t* map);

int put(node_t* node, hashmap_t* map);

node_t* get(const char* name, hashmap_t* map);

#ifdef SUPER

typedef struct {
  char* name;
  char* state;
} node_name_state_t;

int put_name_w_states(node_t* node, hashmap_t* map);

int check_states(const char* name,const char* state);

node_name_state_t* seperate_name_state(const char* name);

#endif

#endif

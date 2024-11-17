
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

size_t hashing(const char* name, size_t map_size){
  unsigned long hash = 5381;
  int c;

  while ((c = *name++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return ((size_t)hash)%map_size;
}

int contains(const char* name,hashmap_t* map){
  size_t hash = hashing(name,map->map_size);
  if (map->map[hash]==NULL){
    return 0;
  } 
  node_t* node = map->map[hash];
  return strcmp(name,node->name)==0;
}

int put(node_t* node,hashmap_t* map){
  if (node == NULL){
    return 0;
  }
  size_t hash = hashing(node->name,map->map_size);
  map->map[hash] = node;
  return 1;
}

node_t* get(const char* node_name,hashmap_t* map){
  if (!contains(node_name,map)){
    return NULL;
  } 
  size_t hash = hashing(node_name,map->map_size);
  return map->map[hash];
}


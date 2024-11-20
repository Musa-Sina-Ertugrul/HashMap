#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_name_state_t* seperate_name_state(const char* name)
{
  if (name[0] != 's') {
    return NULL;
  }
  size_t name_len = strlen(name);
  char* super_states = (char*)calloc(name_len + 1, sizeof(char));
  super_states = strcpy(super_states, name);
  size_t index = 0;
  char c;

  while ((c = name[++index]) != '_') {}

  if (!c) {
    free(super_states);
    return NULL;
  }

  node_name_state_t* result = (node_name_state_t*)malloc(sizeof(node_name_state_t));
  result->state = super_states;
  super_states[index] = '\0';
  ++index;
  result->name = &super_states[index];

  return result;
}

size_t hashing(const char* name, size_t size)
{
  unsigned long hash = 5381;
  int c;

  while ((c = *name++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return ((size_t)hash) % size;
}

int contains(const char* name, hashmap_t* map)
{
  size_t hash = hashing(name, map->size);
  if (map->map[hash] == NULL) {
    return 0;
  }
  node_t* node = map->map[hash];
  node_name_state_t* node_name = seperate_name_state(node->name);
  if (node_name){
    int result = (strcmp(name, node_name->name) == 0);
    free(node_name->state);
    return result;
  }
  free(node_name->state);
  return strcmp(name,node->name) == 0;
}

int put(node_t* node, hashmap_t* map)
{
  if (node == NULL) {
    return 0;
  }
  size_t hash = hashing(node->name, map->size);
  map->map[hash] = node;
  return 1;
}

node_t* get(const char* name, hashmap_t* map)
{
  if (!contains(name, map)) {
    return NULL;
  }
  size_t hash = hashing(name, map->size);
  return map->map[hash];
}

int check_states(const char* name, const char* states)
{
  char* current_state = calloc(2, sizeof(char));
  current_state[0] = name[0];
  int is_there = 1;
  int current_is_there = 0;
  size_t i = 0;
  for (;(current_is_there = (strstr(states, current_state) != NULL)); current_state[0] = name[0]) {
    is_there &= current_is_there;
    ++states;
    ++name;
    ++i;
  }
  free(current_state);
  return (i == 0 ?  current_is_there : is_there);
}

int put_name_w_states(node_t* node, hashmap_t* map)
{

  if (!check_states(node->name, "s_")) {
    fprintf(stderr, "s | _ is not in the name, it is not super, use put\n");
    return 0;
  }
  node_name_state_t* name = seperate_name_state(node->name);
  size_t hash = hashing(name->name, map->size);
  map->map[hash] = node;
  free(name->state);
  free(name);
  return 1;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashmap.h"


int main(){
  size_t hash_1 = hashing("Test_1",11);
  printf("first hash index: %zu\n",hash_1);
  size_t hash_2 = hashing("Test_2",11);
  printf("second hash index: %zu\n",hash_2);
  assert(hash_1 != hash_2);
  printf("First test passed\n");
  hashmap_t map = {(node_t**)malloc(sizeof(node_t*)*11),11,0};
  node_t* node = malloc(sizeof(node_t));
  node->name = "Test_1";
  assert(put(node,&map));
  printf("Second test passed\n");
  assert(~put(NULL,&map));
  printf("Third test passed\n");
  node_t* new_node = get("Test_1",&map);
  assert(~strcmp(new_node->name,node->name));
  printf("4th Test passed\n");
  assert(contains("Test_1",&map));
  printf("5th Test passed\n");
  assert(~contains("Test_2",&map));
  printf("6th Test passed\n");
  free(node);
  free(map.map);
  return 0;
}

#include "linked_list.h"

// create a new node
struct song_node * create_node(char * name, char * artist){
  // make memory for the new node, set the values, and return the pointer
  struct song_node * new = malloc(sizeof(struct song_node));
  strcpy(new->artist, artist);
  strcpy(new->name, name);

  return new;
}

// print the contents of a node without newlines
void print_node(struct song_node * to_print){
  // print the content of a node (NO NEWLINES)
  if(to_print){
    printf("[%s - %s]", to_print->artist, to_print->name);
  }
}

// print the contents of a list
void print_list(struct song_node * list){
  printf("{");
  while(list){
    print_node(list);
    if(list->next)
      printf(" --> ");
    list = list->next;
  }
  printf("}\n");
}

// find a song and return a pointer to the song
struct song_node * find_song(struct song_node * list, char * name, char * artist){
  struct song_node * to_find = create_node(name, artist);

  //iterate through the list, until we find the first node equal to to_find
  while(list && song_node_cmp(list, to_find))
    list = list->next;

  //prevent memory leak
  free(to_find);

  return list;
}

// return a pointer to the first song by an artist
struct song_node * find_artist(struct song_node * list, char * artist){
  while(list && strcmp(list->artist, artist))
    list = list->next;

  return list;
}

// insert node to the front of the list
struct song_node * insert_front(struct song_node * list, struct song_node * to_insert){
  to_insert->next = list;
  return to_insert;
}

// compare two song nodes
int song_node_cmp(struct song_node * first, struct song_node * second){
  int dif = strcmp(first->artist, second->artist);
  if(dif)
    return dif;
  return strcmp(first->name, second->name);
}

// literally the hardest part of this whole assignment
struct song_node * insert_in_order(struct song_node * list, struct song_node * to_insert){

  // special case
  if(!list || song_node_cmp(list, to_insert) >= 0){
    return insert_front(list, to_insert);
  }

  // normal case
  struct song_node * cur = list;
  while(cur->next && song_node_cmp(cur->next, to_insert) < 0){
    cur = cur->next;
  }

  to_insert->next = cur->next;
  cur->next = to_insert;

  return list;
}

// return the length of the list
int get_length(struct song_node * list){
  int len = 0;

  while(list){
    list = list->next;
    len++;
  }

  return len;
}

// get the nth node of the list
struct song_node * get_nth_node(struct song_node * list, int n){
  if(n < 0)
    return 0;

  while(n--)
    list = list->next;

  return list;
}

// get a random node from the list
struct song_node * get_random_node(struct song_node * list){
  if(!list)
    return 0;

  int random_n = rand() % get_length(list);

  return get_nth_node(list, random_n);
}

// remove a node from the list
struct song_node * remove_node(struct song_node * list, struct song_node * to_remove){
  // if the first node of the list should be deleted
  if(!song_node_cmp(list, to_remove)){
    struct song_node * temp = list->next;
    free(list); // no leaks
    return temp;
  }

  struct song_node * cur = list->next;
  struct song_node * prev = list;
  while(cur && song_node_cmp(cur, to_remove)){
    prev = cur;
    cur = cur->next;
  }
  if(!cur)
    return list;

  // cur is the node we need to remove
  prev->next = cur->next;
  free(cur); // no leaks

  return list;
}

// free the entire list
struct song_node * free_list(struct song_node * to_free){
  if(to_free){
    free_list(to_free->next);
    printf(" Freeing ");
    print_node(to_free);
    printf("\n");
    free(to_free);
  }

  return 0;
}













// hello!

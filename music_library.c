#include "music_library.h"

// print out the contents of the entire library
void print_library(struct song_node * to_print[]){
  printf("{\n");
  int i = 0;
  for(i = 0; i < 27; i++){
    if(to_print[i]){
      if(i - 26){
        printf("%c list:\n ", i + 97);
      } else {
        printf("# list:\n ");
      }
      print_list(to_print[i]);
    }
  }
  printf("}\n");
}

// add a song to the library
void add_song(struct song_node * lib[], char * name, char * artist){
  struct song_node * to_add = create_node(name, artist);
  int add_index = artist[0] - 97;
  if (add_index < 0 || add_index > 26){ // in case artist[0] is not a-z
    add_index = 26;
  }
  lib[add_index] = insert_in_order(lib[add_index], to_add);
}

// print all songs under a certain letter
void print_letter(struct song_node * lib[], char letter){
  letter = letter - 97;
  if(letter < 0 || letter > 26){ // in case letter is not a-z
    letter = 26;
  }
  print_list(lib[letter]);
}

// get the size of the entire library
int get_size(struct song_node * lib[]){
  int i;
  int size = 0;
  for(i = 0; i < 27; i++){
    size += get_length(lib[i]);
  }
  return size;
}

// get a random song from the library
struct song_node * random_song(struct song_node * lib[]){
  if(!get_size(lib))
    return 0;
  int rand_index = rand() % 27;
  while(!lib[rand_index])
    rand_index = rand() % 27;
  return get_random_node(lib[rand_index]);
}

// print out a random number of random songs
void shuffle(struct song_node * lib[]){
  int num_times = (rand() % 10) + 1;
  int i;
  for(i = 0; i < num_times; i++){
    printf(" ");
    print_node(random_song(lib));
    printf("\n");
  }
}

// delete a song from the library
void delete_song (struct song_node * lib[], char * name, char * artist){
  struct song_node * to_delete = create_node(name, artist);
  int delete_index = artist[0] - 97;
  if(delete_index < 0 || delete_index > 26)
    delete_index = 26;

  lib[delete_index] = remove_node(lib[delete_index], to_delete);


  free(to_delete); // no leaks
}

// search and return a pointer to a song
struct song_node * search_song(struct song_node * lib[], char * name, char * artist){
  int find_index = artist[0] - 97;
  if(find_index < 0 || find_index > 26)
    find_index = 26;

  return find_song(lib[find_index], name, artist);
}

// search and return a pointer to an artist
struct song_node * search_artist(struct song_node * lib[], char * artist){
  int find_index = artist[0] - 97;
  if(find_index < 0 || find_index > 26)
    find_index = 26;

  return find_artist(lib[find_index], artist);
}

// print all songs by a certain artist
void print_artist(struct song_node * lib[], char * artist){
  struct song_node * first_node = search_artist(lib, artist);
  while(first_node && !strcmp(first_node->artist, artist)){
    printf("  ");
    print_node(first_node);
    printf("\n");
    first_node = first_node->next;
  }
}

// clear all entries in the library
void clear_library(struct song_node * lib[]){
  int i;
  for(i = 0; i < 27; i++)
    lib[i] = free_list(lib[i]);
}



















//yeah

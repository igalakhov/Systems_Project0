// needed libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// linked list structure
struct song_node {
  char               name[100]  ;
  char               artist[100];
  struct song_node * next       ;
};

// linked list functions
struct song_node * create_node     (char *             , char *                          ); // create a new node [tested]
void               print_node      (struct song_node *                                   ); // print the contents of a node without newlines [tested]
void               print_list      (struct song_node *                                   ); // print the contents of a list [tested]
struct song_node * find_song       (struct song_node * , char *             , char *     ); // find a song and return a pointer tot he song [tested]
struct song_node * find_artist     (struct song_node * , char *                          ); // find and return a pointer to the first song by an artist [tested]
struct song_node * insert_front    (struct song_node * , struct song_node *              ); // insert a new node in the front [tested]
struct song_node * insert_in_order (struct song_node * , struct song_node *              ); // insert a new node in order [tested]
int                song_node_cmp   (struct song_node * , struct song_node *              ); // compares two song nodes [tested]
int                get_length      (struct song_node *                                   ); // finds the length of the list [tested]
struct song_node * get_nth_node    (struct song_node * , int                             ); // finds and returns the nth node [tested]
struct song_node * get_random_node (struct song_node *                                   ); // finds and returns a random node in the list [tested]
struct song_node * remove_node     (struct song_node *, struct song_node *               ); // removes a node [tested]
struct song_node * free_list       (struct song_node *                                   ); // frees the entire list [tested]

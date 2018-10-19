// needed libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

// music library headers
void               print_library    (struct song_node * []                  ); // prints out the entire library [tested]
void               add_song         (struct song_node * [], char * , char * ); // add a song to the library [tested]
void               print_letter     (struct song_node * [], char            ); // print all entries under a letter [tested ]
struct song_node * random_song      (struct song_node * []                  ); // return a random node [tested]
int                get_size         (struct song_node * []                  ); // get the size of the library [tested]
void               shuffle          (struct song_node * []                  ); // print out a series of randomly selected songs [tested]
void               delete_song      (struct song_node * [], char * , char * ); // delete a song [tested]
struct song_node * search_song      (struct song_node * [], char * , char * ); // find a song [tested]
struct song_node * search_artist    (struct song_node * [], char *          ); // find an artist [tested]
void               print_artist     (struct song_node * [], char *          ); // print all songs by an artist [tested]
void               clear_library    (struct song_node * []                  ); // clear the entire library

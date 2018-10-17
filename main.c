#include <stdlib.h>
#include <stdio.h>
#include "music_library.h"
#include "linked_list.h"

int main(){
  srand(time(NULL));
  printf("Project 0: myTunes\nWritten by Ivan Galakhov, period 5\nCredits to Angel Li for the songs :)\n\n");

  // create a list of songs that we can use in each of our test

  // linked list tests
  printf("~~~~~~~~~~~~~~~~~~~\nTESTING LINKED LIST\n~~~~~~~~~~~~~~~~~~~\n\n");

  struct song_node * my_list = NULL; // we start out empty
  printf("Printing out empty list:\n");
  print_list(my_list);
  printf("\nTesting inserting at the front...\n");
  struct song_node * front_insert = create_node("starman", "david bowie");
  my_list = insert_front(my_list, front_insert);
  printf(" Added ");
  print_node(front_insert);
  printf("\n\n");

  printf("Printing out non-empty list:\n ");

  print_list(my_list);

  printf("\n\nTesting inserting in order...\n");

  char * songs[] = {"ac/dc", "thunderstruck",
                          "of monsters and men", "i of the storm",
                          "the beatles", "long and winding road",
                          "the beatles", "hey jude",
                          "bastille", "icarus",
                          //"bastille", "good grief",
                          //"bastille", "send them off!",
                          "bastille", "daniel in the den",
                          "saba", "life",
                          "saba", "heaven all around me",
                          "zach farache", "sweaterman",
                          "zach farache", "the loser"};
                          // "potsu", "im closing my eyes",
                          // "rex orange county", "loving is easy",
                          // "in love with a ghost", "we've never met but can we have a cup of coffee",
                          // "kino", "kukushka",
                          // "brand new", "the boy who blocked his own shot",
                          // "arctic monkeys", "arabella",
                          // "arctic monkeys", "r u mine?",
                          // "aurora", "runaway",
                          // "willow", "marceline",
                          // "willow", "warm honey",
                          // "my chemical romance", "the world is ugly",
                          // "frank sinatra", "my way",
                          // "joji", "can't get over you",
                          // "more amor", "beach bones",
                          // "khachaturian", "masquerade suite: waltz",
                          // "mussorgsky", "night on the bald mountain",
                          // "mussorgsky", "in the steppes of central asia"};

  int i;
  for(i = 0; i < sizeof(songs)/sizeof(songs[0]) - 1; i+= 2){
    my_list = insert_in_order(my_list, create_node(songs[i+1], songs[i]));
    printf(" Added [%s - %s]\n", songs[i+1], songs[i]);
  }

  printf("\nPrinting out non-empty list: \n ");
  print_list(my_list);


  // generate a song we know is in the list, as well as one that we know isn't
  int rand_artist = (rand() % (sizeof(songs)/sizeof(songs[0]))/2 *2);

  // should always be found
  printf("\nAttempting to find [%s - %s]:\n", songs[rand_artist], songs[rand_artist + 1]);
  struct song_node * found = find_song(my_list, songs[rand_artist + 1], songs[rand_artist]);
  if(found){
    printf(" Song found! ");
    print_node(found);
    printf("\n");
  } else {
    printf(" Song not found!");
  }

  // should (almost always) be not found
  printf("\nAttempting to find [%s - %s]:\n", songs[rand_artist], "oranges");
  found = find_song(my_list, "oranges", songs[rand_artist]);
  if(found){
    printf(" Song found! ");
    print_node(found);
    printf("\n");
  } else {
    printf(" Song not found!\n");
  }

  // generate another random artist
  rand_artist = (rand() % (sizeof(songs)/sizeof(songs[0]))/2 *2);
  printf("\nAttempting to find first song by [%s]\n ", songs[rand_artist]);
  struct song_node * first_node = find_artist(my_list, songs[rand_artist]);
  if(first_node){
    printf("Node found! ");
    print_node(first_node);
    printf("\n Rest of list from that node: ");
    print_list(first_node);
  }

  int num_nodes = (rand() % 5) + 3;
  printf("\nFinding %d random nodes:\n ", num_nodes);
  for(i = 0; i < num_nodes; i++){
    print_node(get_random_node(my_list));
    printf("\n ");
  }

  printf("\nTesting get_length (helper function):\n");
  printf(" Length of list: %d\n", get_length(my_list));

  printf("\nTesting get_nth_node (helper function):\n");
  int nth = rand() % get_length(my_list);
  printf(" Attempting to find node #%d\n", nth);
  printf(" Node found! ");
  print_node(get_nth_node(my_list, nth));

  int num_times = (rand() % 4) + 2;
  printf("\n\nTesting remove_node %d times: \n\n", num_times);
  for(i = 0; i < num_times; i++){
    struct song_node * rand_node = get_random_node(my_list);
    printf(" Removing ");
    print_node(rand_node);
    my_list = remove_node(my_list, rand_node);
    printf("\n");
    print_list(my_list);
    printf("\n ");
  }

  printf("\nTesting get_length (helper function):\n");
  printf(" Length of list: %d\n", get_length(my_list));

  num_times = (rand() % 5) + 3;
  printf("\nTesting song_node_cmp (helper function) %d times:\n", num_times + 1);
  struct song_node * first;
  struct song_node * second;
  for(i = 0; i < num_times; i++){
    first = get_random_node(my_list);
    second = get_random_node(my_list);
    printf(" Comparing");
    print_node(first);
    printf(" and ");
    print_node(second);
    printf("\n");
    printf("  Result: %d\n", song_node_cmp(first, second));
  }
  printf(" Comparing");
  print_node(first);
  printf(" and ");
  print_node(first);
  printf("\n");
  printf("  Result: %d\n", song_node_cmp(first, first));


  printf("\nFreeing the entire list (recursively):\n");

  my_list = free_list(my_list);


  printf("\nTesting get_length (helper function):\n");
  printf(" Length of list: %d\n", get_length(my_list));

  printf("\nGetting random node from empty list:\n");
  struct song_node * rand_node = get_random_node(my_list);
  if(!rand_node){
    printf(" No node found!\n");
  } else {
    printf(" Node found? ");
    print_node(rand_node);
    printf("\n");
  }

  // song library tests
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\nTESTING THE SONG LIBRARY\n~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


  return 0;
}















//hello

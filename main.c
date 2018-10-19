#include <stdlib.h>
#include <stdio.h>
#include "music_library.h"

void divider(){
  printf("\n---------------\n");
}

int main(){
  srand(time(NULL));
  printf("Project 0: myTunes\nWritten by Ivan Galakhov, period 5\nCredits to Angel Li for the songs :)\n\n");

  // create a list of songs that we can use in each of our test

  // linked list tests
  printf("~~~~~~~~~~~~~~~~~~~\nTESTING LINKED LIST\n~~~~~~~~~~~~~~~~~~~\n\n");

  // test print list
  struct song_node * my_list = NULL; // we start out empty
  printf("Printing out empty list:\n");
  print_list(my_list);

  divider();

  // test inserting in the front
  printf("\nTesting inserting at the front...\n");
  struct song_node * front_insert = create_node("starman", "david bowie");
  my_list = insert_front(my_list, front_insert);
  printf(" Added ");
  print_node(front_insert);
  printf("\n\n");

  printf("Printing out non-empty list:\n ");

  print_list(my_list);

  divider();

  // test inserting in order
  printf("\nTesting inserting in order...\n");
  printf("\n(notice that this inserting is in an order that puts songs in the beginning, end, and middle)");

  char * songs[] = {"ac/dc", "thunderstruck",
                          "of monsters and men", "i of the storm",
                          "the beatles", "long and winding road",
                          "the beatles", "hey jude",
                          "willow", "warm honey",
                          "bastille", "icarus",
                          "#numberband", "numbersong",
                          "&numberband", "numbersong1",
                          "0numberband", "numbersong2",
                          "bastille", "send them off!",
                          "bastille", "daniel in the den",
                          "saba", "life",
                          "saba", "heaven all around me",
                          "zach farache", "sweaterman",
                          "zach farache", "the loser",
                          "potsu", "im closing my eyes",
                          "rex orange county", "loving is easy",
                          "in love with a ghost", "we've never met but can we have a cup of coffee",
                          "kino", "kukushka",
                          "brand new", "the boy who blocked his own shot",
                          "arctic monkeys", "arabella",
                          "arctic monkeys", "r u mine?",
                          "aurora", "runaway",
                          "willow", "marceline",
                          "my chemical romance", "the world is ugly",
                          "frank sinatra", "my way",
                          "joji", "can't get over you",
                          "more amor", "beach bones",
                          "khachaturian", "masquerade suite: waltz",
                          "mussorgsky", "night on the bald mountain",
                          "mussorgsky", "in the steppes of central asia"};

  int i;
  for(i = 0; i < sizeof(songs)/sizeof(songs[0]) - 1; i+= 2){
    my_list = insert_in_order(my_list, create_node(songs[i+1], songs[i]));
    printf(" Added [%s - %s]\n", songs[i+1], songs[i]);
  }

  printf("\nPrinting out non-empty list: \n");
  print_list(my_list);

  divider();

  // testing looking for a song
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

  divider();

  // testing looking for an artist
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

  divider();

  // testing random node
  int num_nodes = (rand() % 5) + 3;
  printf("\nFinding %d random nodes:\n ", num_nodes);
  for(i = 0; i < num_nodes; i++){
    print_node(get_random_node(my_list));
    printf("\n ");
  }

  printf("\nTesting get_length (helper function):\n");
  printf(" Length of list: %d\n", get_length(my_list));

  divider();

  // getting the nth node
  printf("\nTesting get_nth_node (helper function):\n");
  int nth = rand() % get_length(my_list);
  printf(" Attempting to find node #%d\n", nth);
  printf(" Node found! ");
  print_node(get_nth_node(my_list, nth));

  divider();

  // testing remove node
  int num_times = (rand() % 4) + 2;
  printf("\nTesting remove_node %d times: \n\n", num_times);
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

  divider();

  // test comparing songs
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

  divider();

  printf("\nFreeing the entire list (recursively):\n");

  my_list = free_list(my_list);

  printf("\nTesting get_length (helper function):\n");
  printf(" Length of list: %d\n", get_length(my_list));

  divider();

  // test getting random node
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

  struct song_node * my_library[27];

  // empty library test
  printf("Printing out empty library:\n\n");
  print_library(my_library);

  divider();

  // testing adding songs
  printf("\nAdding songs to library:\n");

  for(i = 0; i < sizeof(songs)/sizeof(songs[0]) - 1; i+= 2){
    add_song(my_library, songs[i+1], songs[i]);
    printf(" Added [%s - %s]\n", songs[i+1], songs[i]);
  }


  printf("\nPrinting out non-empty library:\n\n");
  print_library(my_library);

  divider();

  num_times = (rand() % 4) + 3;
  printf("\nTesting printing out a certain letter %d times:\n", num_times + 1);
  char rand_letter = 97 + rand() % 27;
  for(i = 0; i < num_times; i++){
    printf("All entries under %c:\n ", rand_letter);
    print_letter(my_library, rand_letter);

    rand_letter = 97 + (rand() % 27);
  }
  printf("All entries under #:\n ");
  print_letter(my_library, '#');

  divider();
  // testing getting the size
  printf("\nTesting get_size (helper function):\n ");
  printf("Music Library Size: %d\n\n", get_size(my_library));

  divider();
  // printing out random nodes
  num_times = (rand() % 4) + 3;
  printf("\nTesting shuffle random_node (helper function) %d times: \n ", num_times);
  for(i = 0; i < num_times; i++){
    print_node(random_song(my_library));
    printf("\n ");
  }
  printf("\n");

  printf("Testing shuffle:\n");
  shuffle(my_library);

  printf("\nTesting shuffle again:\n");
  shuffle(my_library);

  divider();

  // testing deleting
  printf("\nTesting deleting:\n");
  num_times = (rand() % 4) + 2;
  for(i = 0; i < num_times; i++){
    printf(" Deleting ");
    struct song_node * to_delete = random_song(my_library);
    print_node(to_delete);
    delete_song(my_library, to_delete->name, to_delete->artist);
    printf("\n");

  }
  printf("\nNew library after deletions:\n");
  print_library(my_library);

  printf("\nTesting get_size (helper function):\n ");
  printf("Music Library Size: %d\n\n", get_size(my_library));

  divider();

  // finding songs
  num_times = (rand() % 4) + 2;
  printf("\nTesting finding songs:\n");
  for(i = 0; i < num_times; i++){
    struct song_node * to_find = random_song(my_library);
    printf(" Looking for ");
    print_node(to_find);
    printf("\n");
    struct song_node * found = search_song(my_library, to_find->name, to_find->artist);
    if(found){
      printf("  Song found! ");
      print_node(found);
    } else {
      printf("  Song not found!");
    }
    printf("\n");
  }

  // look for non existing node
  printf(" Looking for [ivan - nonexistentsong]\n");
  found = search_song(my_library, "ivan", "nonexistentsong");
  if(found){
    printf("  Song found! ");
    print_node(found);
  } else {
    printf("  Song not found!");
  }

  divider();

  // looking for an artist
  printf("\nTesting looking for an artist:\n");
  int artist_index = rand() % (sizeof(songs)/sizeof(songs[0]));
  artist_index -= artist_index % 2;
  printf(" Looking for first song by [%s]\n", songs[artist_index]);
  found = search_artist(my_library, songs[artist_index]);
  printf("  Printing list from that point: ");
  print_list(found);

  printf(" Looking for first song by [sam]\n");
  found = search_artist(my_library, "sam");
  printf("  Printing list from that point: ");
  print_list(found);


  divider();

  // testing printing an artist
  artist_index = rand() % (sizeof(songs)/sizeof(songs[0]));
  artist_index -= artist_index % 2;

  printf("\nTesting print_artist:\n");
  printf("\n Printing all songs by [%s]:\n", songs[artist_index]);
  print_artist(my_library, songs[artist_index]);

  artist_index = rand() % (sizeof(songs)/sizeof(songs[0]));
  artist_index -= artist_index % 2;

  printf("\n Printing all songs by [%s]:\n", songs[artist_index]);
  print_artist(my_library, songs[artist_index]);

  artist_index = rand() % (sizeof(songs)/sizeof(songs[0]));
  artist_index -= artist_index % 2;

  printf("\n Printing all songs by [ivan]:\n");
  print_artist(my_library, "ivan");

  divider();

  // testing clearing the program
  printf("\nTesting clearing the library:\n");
  clear_library(my_library);

  printf("\nPrinting the library one last time:\n");
  print_library(my_library);

  divider();

  printf("\nThat's it!! If any of the tests in this program \n");
  printf("didn't properly demostrate the edge cases, feel  \n");
  printf("free to rerun the program, as most of the tests  \n");
  printf("written here are random :)\n");
  printf("                               -Ivan Galakhov, 5\n\n");

  return 0;
}















//hello

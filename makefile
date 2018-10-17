all: main.o linked_list.o music_library.o
	gcc -o main.out main.o linked_list.o music_library.o
	rm *.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

music_library.o: music_library.c music_library.h
	gcc -c music_library.c

main.o: main.c music_library.h linked_list.h
	gcc -c main.c

run:
	clear
	./main.out

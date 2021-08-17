FLAGS = -Wall -Wextra -g

EXECUTABLE = main.exe

all:	main.exe

scrub: clean
	rm ~* *.swp *\#

run: $(EXECUTABLE)
	./$(EXECUTABLE)

main.exe:	Song.o main.o Library.o Playlist.o Timestamp.o
	g++ Song.o main.o Library.o Playlist.o Timestamp.o -o main.exe

Song.o:	HEADERS/Song.h HEADERS/Timestamp.h Song.cpp 
	g++ -c Song.cpp 

Timestamp.o: HEADERS/Timestamp.h Timestamp.cpp
	g++ -c Timestamp.cpp

Playlist.o: HEADERS/Song.h Playlist.cpp
	g++ -c Playlist.cpp

Library.o:	HEADERS/Song.h HEADERS/Library.h HEADERS/Playlist.h Library.cpp 
	g++ -c Library.cpp 

main.o: HEADERS/Song.h HEADERS/Library.h HEADERS/Playlist.h main.cpp 
	g++ -c main.cpp

clean:
	rm -f *.o $(EXECUTABLE)

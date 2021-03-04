# Use the first FLAGS definition for debugging, the 2nd for optimizing your code
FLAGS = -Wall -Wextra -g

CA = 2
LASTNAME = Burzynski
BU_USERID = nburzyn1
GITHUB_USERID = NikolasBurzynski
EXECUTABLE = main.exe

all:	main.exe

replaceme:
	echo "Did you remember to set the variables in the makefile?!"

tar: clean
	cd .. && tar -cvzf CA$(CA)_$(LASTNAME)_$(BU_USERID).tar.gz cs240-spring21-ca$(CA)-$(GITHUB_USERID) && cd -

scrub: clean
	rm ~* *.swp *\#

run: $(EXECUTABLE)
	./$(EXECUTABLE)

main.exe:	Song.o main.o Library.o
	g++ Song.o main.o Library.o -o main.exe

Song.o:	HEADERS/Song.h Song.cpp 
	g++ -c Song.cpp 

Library.o:	HEADERS/Song.h HEADERS/Library.h Library.cpp 
	g++ -c Library.cpp 

main.o: main.cpp 
	g++ -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(EXECUTABLE)

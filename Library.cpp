#include <iostream>
#include <stdlib.h>
#include <string>
#include "Song.h"
#include "Library.h"


Library::Library(const int size){
    songList = new Song[size]; 
    numSongs = 0;
}

void Library::addSong(Song inSong){
    songList[numSongs] = inSong;
    numSongs++; 
}

void Library::printLibrary(){
    for(int i = 0; i < numSongs; i++){
        songList[i].toString();
    }
}

Library::~Library(){
    delete[] songList;
}
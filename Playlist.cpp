#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Playlist.h"
#include "HEADERS/Song.h"

Playlist::Playlist(string inName){
    name = inName;
    numSongs = 0;
    songList = new Song[numSongs];
}

Playlist::~Playlist(){
    delete[] songList;
}

void Playlist::showSongs(){

};
void Playlist::printDetails(){};
void Playlist::addSong(Song inSong){};
void Playlist::removeSong(string outTitle){};

Playlist::Playlist(const Playlist & target){
    name = target.name;
    numSongs = target.numSongs;  
}


#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Song.h"
#include "HEADERS/Library.h"
#include "HEADERS/Playlist.h"


Library::Library(const int size){
    maxSongs = size;
    songList = new Song[maxSongs]; 
    playlists = new Playlist[0];
    numSongs = 0;
}

void Library::addPlaylist(string playlist_name){
    Playlist newPlaylist(playlist_name);
    
}

void Library::showPlaylists(){
    for(int i = 0; i < numPlaylists; i++){
        playlists[i].printDetails();
    }
}

void Library::addSong(Song inSong){
    if(numSongs == maxSongs) {
        cout << "Expanding Library" << endl;
        Song * newLibrary = new Song[numSongs + 1];
        maxSongs++;
        copy(songList, songList+numSongs, newLibrary);
        delete[] songList;
        songList = newLibrary;
    }
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
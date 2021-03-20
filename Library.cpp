#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Song.h"
#include "HEADERS/Library.h"
#include "HEADERS/Playlist.h"

Library::Library(){ //Blank Constructor
    // cout << "Library Empty Constructor" << endl;
    numSongs = 0;
    numPlaylists = 0;
    maxSongs = 1;
    maxPlaylists = 1;
    songList = new Song[maxSongs];
    playlists = new Playlist[maxPlaylists];
}

Library::Library(const int inMaxSongs, const int inMaxPlaylists){
    // cout << "Library Value Constructor" << endl;
    numSongs = 0;
    numPlaylists = 0;
    maxSongs = inMaxSongs;
    maxPlaylists = inMaxPlaylists;
    songList = new Song[maxSongs];
    playlists = new Playlist[maxPlaylists];
    // cout << numPlaylists << endl;
}

void Library::printLibrary(){
    for(int i = 0; i < numSongs; i++){
        songList[i].toString();
    }
}

Song Library::getSong(string title){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(title) == 0){
            return songList[i];
        }
    }
    // cout << "Never Called" << endl;
    return Song();
}

bool Library::containsPlaylist(string name){
    // cout << "Checking Playlists" << endl;
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(name) == 0){
            return true;
        }
    }
    return false;
}

bool Library::containsSong(string title){
    // cout << "Looking for Song" << endl;
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(title) == 0){
            return true;
        }
    }
    return false;
}

void Library::removeSong(string title){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(title) == 0){ //Remove this song
            //Take the last song and put it in this spot and then reduce Num songs
            songList[i] = songList[numSongs-1];
            numSongs--;
            break;
        }
    }
}

void Library::removePlaylist(string name){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(name) == 0){
            playlists[i] = playlists[numPlaylists - 1];
            numPlaylists--;
            cout << "playlist removed!" << endl;
            break;
        }
    }
}

bool Library::containsSong(Song song){
    for(int i = 0; i < numSongs; i++){
        if(songList[i] == song){
            return true;
        }
    }
    return false;
}

void Library::addSong(Song newSong){
    // cout << "Adding new Song" << endl;
    if(numSongs == maxSongs){
        // cout << "Need to Grow" << endl;
        growLibrary();
    }
    songList[numSongs] = newSong;
    numSongs++;
    cout << "Song Added" << endl;
}

void Library::growLibrary(){
    Song * newLibrary = new Song[maxSongs * 2];
    for(int i = 0; i < numSongs; i++){
        newLibrary[i] = songList[i];
    }
    delete[] songList;
    songList = newLibrary;
    maxSongs *= 2;
}

void Library::addPlaylist(string name){
    Playlist playlist(name);
    if(numPlaylists == maxPlaylists){
        // cout << "Need to expand playlists" << endl;
        growPlaylists();
    }
    playlists[numPlaylists] = playlist; //Assignment Operator
    numPlaylists++;
}

void Library::growPlaylists(){
    Playlist * tmpPlaylists = new Playlist[maxPlaylists * 2];
    for(int i = 0; i < numPlaylists; i++){
        tmpPlaylists[i] = playlists[i]; //Assignment Operator
    }
    delete[] playlists;
    playlists = tmpPlaylists;
    maxPlaylists *= 2;
}

void Library::addSongtoPlaylist(Song song, string playlistName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlistName) == 0){
            playlists[i].addSong(song);
            break;
        }
    }
}

void Library::removeSongfromPlaylist(string songTitle, string playlistName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlistName) == 0){
            playlists[i].removeSong(songTitle);
            break;
        }
    }
}

Library::~Library(){
    cout << "Destroying Library" << endl;
    delete[] songList;
    delete[] playlists;
}
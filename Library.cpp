#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Song.h"
#include "HEADERS/Library.h"
#include "HEADERS/Playlist.h"


Library::Library(const int songsSize, const int playlistsSize){
    maxSongs = songsSize;
    maxPlaylists = playlistsSize;
    songList = new Song[maxSongs]; 
    playlists = new Playlist[maxPlaylists];
    numSongs = 0;
    numPlaylists = 0;
}

void Library::clonePlaylist(string sourceName, string newName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(sourceName) == 0){
            Playlist newPlaylist = playlists[i];
            newPlaylist.setName(newName);
            if(numPlaylists == maxPlaylists) {
                cout << "Expanding Playlist Storage" << endl;
                Playlist * newPlaylists = new Playlist[numPlaylists * 2];
                maxPlaylists*=2;
                copy(playlists, playlists+numPlaylists, newPlaylists);
                if(playlists){
                    delete[] playlists;
                }
                playlists = newPlaylists;
            }
            playlists[numPlaylists] = newPlaylist;
            numPlaylists++;
            break;
        }
    }
    
}

void Library::addPlaylist(string playlist_name){
    Playlist newPlaylist(playlist_name);
    if(numPlaylists == maxPlaylists) {
        cout << "Expanding Playlist Storage" << endl;
        Playlist * newPlaylists = new Playlist[numPlaylists * 2];
        maxPlaylists*=2;
        copy(playlists, playlists+numPlaylists, newPlaylists);
        if(playlists){
            delete[] playlists;
        }
        playlists = newPlaylists;
    }
    playlists[numPlaylists] = newPlaylist;
    numPlaylists++;
}

int Library::getNumSongs(){
    return numSongs;
}

int Library::getNumPlaylists(){
    return numPlaylists;
}

bool Library::containsPlaylist(string name){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(name) == 0){
            return true;
        }
    }
    return false;
}


bool Library::containsSong(Song targetSong){
    for(int i = 0; i < numSongs; i++){
        if(songList[i] == targetSong) return true; //USE OF THE OVERLOADED EQUALS OPERATOR
    }
    return false;
}

bool Library::containsSong(string targetTitle){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(targetTitle) == 0) return true;
    }
    return false;
}

Song Library::getSong(string targetTitle){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(targetTitle) == 0){
            return songList[i];
        }
    }
    //No return here because it will never come here
}


void Library::addSongtoPlaylist(Song targetSong, string playlistName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlistName) == 0){
            // cout << playlists[i].getMaxSongs() << endl;
            if(!playlists[i].containsSong(targetSong)){
                playlists[i].addSong(targetSong);
            }
        }
    }
}

void Library::addSongsfromPlaylist(string playlistName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlistName) == 0){ //Playlist we are getting music from
            for(int j = 0; j < playlists[i].getNumSongs(); j++){
                if(!containsSong(playlists[i].getSong(j))){
                    addSong(playlists[i].getSong(j));
                }
            }
        }
    }
}

void Library::showPlaylists(){
    for(int i = 0; i < numPlaylists; i++){
        cout << playlists[i] << endl;
    }
}

void Library::addSong(Song inSong){
    if(numSongs == maxSongs) {
        cout << "Expanding Library" << endl;
        Song * newLibrary = new Song[numSongs * 2];
        maxSongs*=2;
        copy(songList, songList+numSongs, newLibrary);
        if(songList){
            delete[] songList;
        }
        songList = newLibrary;
    }
    songList[numSongs] = inSong;
    numSongs++; 
}

void Library::removeSong(string songName){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(songName) == 0){
            for(int j = i; j < numSongs; j++){
                if(j != numSongs - 1){
                    songList[j] = songList[j+1];
                }else{
                    if(numSongs != 0) numSongs--;
                    return;
                }
            }
        }
    }
}

void Library::removePlaylist(string name){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(name) == 0){
            for(int j = i; j < numPlaylists; j++){
                if(j != numPlaylists - 1){
                    playlists[j] = playlists[j+1];
                }else{
                    if(numPlaylists != 0) numPlaylists--;
                    return;
                }
            }
        }
    }
}

void Library::removeSongfromPlaylist(string songName, string playlistName){
    if(containsPlaylist(playlistName)){
        for(int i = 0; i < numPlaylists; i++){
            if(playlists[i].getName().compare(playlistName) == 0){
                playlists[i].removeSong(songName);
            }
        }
    }else{
        cout << "\"" << playlistName << " does not include " << "\"" << songName << "\"" << endl;
    }
}

void Library::printLibrary(){
    for(int i = 0; i < numSongs; i++){
        songList[i].toString();
    }
}
void Library::printPlaylist(string playlistName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlistName) == 0){
            playlists[i].printSongs();
        }
    }
}

void operator+=(Library const & library, string playlistName){
    library.addSongsfromPlaylist(playlistName);
}

Library::~Library(){
    delete[] songList;
    delete[] playlists;
}
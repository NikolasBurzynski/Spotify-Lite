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

void Library::clonePlaylist(string currentPlaylist, string newName){
    if(!containsPlaylist(newName)){
        for(int i = 0; i < numPlaylists; i++){
            if(playlists[i].getName().compare(currentPlaylist) == 0){
                Playlist newPlaylist(playlists[i]);
                newPlaylist.setName(newName);
                if(numPlaylists == maxPlaylists) growPlaylists();
                playlists[numPlaylists] = newPlaylist;
                numPlaylists++;
                cout << "Clone Created" << endl;
                break;
            }
        }
    }else{
        cout << "Library already has a playlist with name " << newName << endl;
    }
}

void Library::printSongfromPlaylist(string playlist, string songName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlist) == 0){
            playlists[i].printSong(songName);
        }
    }
}

void Library::addSongsfromPlaylist(string playlistName){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(playlistName) == 0){
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

void Library::importPlaylist(string playlistName, string currentPlaylist){
    if(currentPlaylist.compare("LIBRARY") == 0){
        addSongsfromPlaylist(playlistName);
    }else{
        for(int i = 0; i < numPlaylists; i++){
            if(playlists[i].getName().compare(currentPlaylist) == 0){
                for(int j = 0; j < numPlaylists; j++){
                    if(playlists[j].getName().compare(playlistName) == 0 && playlistName.compare(currentPlaylist) != 0){
                        for(int k = 0; k < playlists[j].getNumSongs(); k++){
                            Song addSong = playlists[j].getSong(k);
                            if(!playlists[i].containsSong(addSong)){
                                playlists[i] += addSong; 
                            }
                        }
                    }
                }
            }
        }
    }
}

void Library::printPlaylist(string name){
    for(int i = 0; i < numPlaylists; i++){
        if(playlists[i].getName().compare(name) == 0){
            playlists[i].printSongs();

        }
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
    if(numSongs == maxSongs){
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
        growPlaylists();
    }
    playlists[numPlaylists] = playlist; //Assignment Operator
    numPlaylists++;
}

void Library::growPlaylists(){
    cout << maxPlaylists << endl;
    Playlist * tmpPlaylists = new Playlist[maxPlaylists * 2];
    // cout << tmpPlaylists[1].getName() << endl;
    for(int i = 0; i < numPlaylists; i++){
        cout << "Index: " << i << endl;
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
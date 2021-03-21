#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Playlist.h"
#include "HEADERS/Song.h"
#include <math.h>

Playlist::Playlist(){
    // cout << "Playlist Empty Constructor" << endl;
    numSongs = 0;
    maxSongs = 1;
    numMins = 0;
    numSecs = 0;
    Timestamp addTime = Timestamp();
    createTime = addTime.toString();
    name = "";
    songList = new Song[maxSongs];
}

Playlist::Playlist(string inName){
    cout << "Playlist Value Constructor" << endl;
    numSongs = 0;
    maxSongs = 1;
    numMins = 0;
    numSecs = 0;
    Timestamp addTime = Timestamp();
    createTime = addTime.toString();
    name = inName;
    songList = new Song[maxSongs];
}

Playlist::Playlist(const Playlist & source){
    // cout << "Playlist Copy Constructor" << endl;
    numSongs = source.numSongs;
    maxSongs = source.maxSongs;
    numMins = source.numMins;
    numSecs = source.numSecs;
    createTime = source.createTime;
    name = source.name;
    songList = new Song[maxSongs];
    for(int i = 0; i < source.numSongs; i++){
        songList[i] = source.songList[i];
    }
}

string Playlist::getName(){
    return name;
}

Playlist& Playlist::operator=(const Playlist & source){
    // cout << "Playlist Assignment Called" << endl;
    if(this != &source){
        numSongs = source.numSongs;
        maxSongs = source.maxSongs;
        numMins = source.numMins;
        numSecs = source.numSecs;
        createTime = source.createTime;
        name = source.name;
        Song * tmpList = new Song[maxSongs];
        for(int i = 0; i < numSongs; i++){
            tmpList[i] = source.songList[i];
        }
        delete[] songList;
        songList = tmpList;
    }
    return *this;
}

void Playlist::growPlaylist(){
    Song * newSongList = new Song[maxSongs * 2];
    for(int i = 0; i < numSongs; i++){
        newSongList[i] = songList[i];
    }
    delete[] songList;
    songList = newSongList;
    maxSongs *= 2;
}

void Playlist::addSong(Song song){
    if(numSongs == maxSongs){
        cout << "Need to Expand Playlist" << endl;
        growPlaylist();
    }
    songList[numSongs] = song;
    numSongs++;
}

void Playlist::removeSong(string songTitle){
    if(containsSong(songTitle)){
        for(int i = 0; i < numSongs; i++){
            if(songList[i].getTitle().compare(songTitle) == 0){ //remove this song
                songList[i] = songList[numSongs - 1];
                cout << "Song Removed" << endl;
                numSongs--;
                break;
            }
        }
    }else{
        cout << songTitle << " is not in this playlist" << endl;
    }
}

bool Playlist::containsSong(string title){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(title) == 0){
            return true;
        }
    }
    return false;
}
bool Playlist::containsSong(Song song){
    for(int i = 0; i < numSongs; i++){
        if(songList[i] == song){
            return true;
        }
    }
    return false;
}

void Playlist::setName(string newName){
    name = newName;
}

void Playlist::printSongs(){
    numMins = 0;
    numSecs = 0;
    for(int i = 0; i < numSongs; i++){
        songList[i].toString();
        numMins += songList[i].getMins();
        numSecs += songList[i].getSecs();
        int multiples = floor(numSecs / 60.0);
        numMins += multiples;
        numSecs -= multiples * 60;
    }
    cout << "Total Playlist Duration: " << numMins << " minutes and " << numSecs << " seconds" << endl;
}

int Playlist::getNumSongs(){
    return numSongs;
}

Playlist& Playlist::operator+=(Song addedSong){
    addSong(addedSong);
    return *this;
}

Song Playlist::getSong(int i){
    Song song(songList[i]);
    return song;
}


void Playlist::printSong(string title){
    if(containsSong(title)){
        for(int i = 0; i < numSongs; i++){
            if(songList[i].getTitle().compare(title) == 0){
                songList[i].toString();
            }
        }
    }else{
        cout << "Playlist does not contain " << title << endl;
    }
}

ostream& operator<<(ostream& out, const Playlist& p){
    out << "Playlist Title: " << p.name << " Creation Timestamp: " << p.createTime;
    return out;
}


Playlist::~Playlist(){
    cout << "Destroying Playlist" << endl;
    if(songList) delete[] songList;
}


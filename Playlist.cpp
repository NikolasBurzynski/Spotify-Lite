#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Playlist.h"
#include "HEADERS/Song.h"
#include <math.h>

Playlist::Playlist(){
    cout << "Playlist Empty Constructor" << endl;
    int numSongs = 0;
    int maxSongs = 1;
    int numMins = 0;
    int numSecs = 0;
    Timestamp addTime = Timestamp();
    createTime = addTime.toString();
    string name = "";
    songList = new Song[maxSongs];
}

Playlist::Playlist(string inName){
    cout << "Playlist Value Constructor" << endl;
    int numSongs = 0;
    int maxSongs = 1;
    int numMins = 0;
    int numSecs = 0;
    Timestamp addTime = Timestamp();
    createTime = addTime.toString();
    string name = inName;
    songList = new Song[maxSongs];
}

Playlist::Playlist(const Playlist & source){
    cout << "Playlist Copy Constructor" << endl;
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
    cout << "Playlist Assignment Called" << endl;
    if(this != &source){
        numSongs = source.numSongs;
        maxSongs = source.maxSongs;
        numMins = source.numMins;
        numSecs = source.numSecs;
        createTime = source.createTime;
        name = source.name;
        Song * tmpList = new Song[maxSongs];
        cout << "Source NumSongs" << source.numSongs << endl;
        cout << "NumSongs " << numSongs << endl;
        for(int i = 0; i < numSongs; i++){
            songList[i] = source.songList[i];
        }
        delete[] songList;
        songList = tmpList;
    }
    return *this;
}



Playlist::~Playlist(){
    cout << "Destroying Playlist" << endl;
    if(songList) delete[] songList;
}


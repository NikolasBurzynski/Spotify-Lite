#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Playlist.h"
#include "HEADERS/Song.h"
#include <math.h>

Playlist::Playlist(){};

Playlist::Playlist(string inName){
    name = inName;
    maxSongs = 5;
    numSongs = 0;
    songList = new Song[maxSongs];
    Timestamp addTime = Timestamp();
    createTime = addTime.toString();
    numMins = 0;
    numSecs = 0;
}

int Playlist::getMaxSongs(){
    return maxSongs;
}

int Playlist::getNumSongs(){
    return numSongs;
}

Song Playlist::getSong(int index){
    return songList[index];
}

bool Playlist::containsSong(Song targetSong){
    for(int i = 0; i < numSongs; i++){
        if(songList[i] == targetSong) return true;
    }
    return false;
}



void Playlist::removeSong(string name){
    for(int i = 0; i < numSongs; i++){
        if(songList[i].getTitle().compare(name) == 0){
            for(int j = i; j < numSongs; j++){
                if(j != numSongs - 1){
                    songList[j] = songList[j+1];
                }else{
                    if(numSongs != 0)numSongs--;
                    return;
                }
            }
        }
    }
    cout << "\"" << name << "\"" << " is not in this playlist" << endl;
}

void Playlist::addSong(Song inSong){
    // cout << numSongs << " " << maxSongs << endl;
    if(numSongs == maxSongs){
        cout << "Expanding Playlist named: " << name << endl;
        Song * tempPlaylist = new Song[numSongs * 2];
        maxSongs*=2;
        copy(songList, songList+numSongs, tempPlaylist);
        if(songList){
            delete[] songList;
        }
        songList = tempPlaylist;
    }
    songList[numSongs] = inSong;
    numSongs++;
}

void Playlist::printSongs(){
    calculateTotalTime();
    for(int i = 0; i < numSongs; i++){
        songList[i].toString();
    }
    cout << "Total Time: " << numMins << " minutes and " << numSecs << " seconds." << endl;
}

void Playlist::calculateTotalTime(){
    numMins = 0;
    numSecs = 0;
    for(int i = 0; i < numSongs; i++){
        numMins += songList[i].getMins();
        numSecs += songList[i].getSecs();
    
        int multiples = floor(numSecs / 60.0);
        numMins += multiples;
        numSecs -= multiples * 60;
    }
}


ostream& operator<<(ostream& out, const Playlist& p){
    out << "Playlist Title: " << p.name << " Creation Timestamp: " << p.createTime;
    return out;
}


string Playlist::getName(){
    return name;
}

void Playlist::setName(string newName){
    name = newName;
}

Playlist::Playlist(const Playlist & source){
    name = source.name;
    numSongs = source.numSongs;
    numMins = source.numMins;
    numSecs = source.numSecs;
    maxSongs = source.maxSongs;
    songList = new Song[maxSongs];
    Timestamp addTime = Timestamp();
    createTime = addTime.toString();
    for(int i = 0; i < source.numSongs; i++){
        songList[i] = source.songList[i];
    }

}

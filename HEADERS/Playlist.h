#pragma once
#include <iostream>
#include <string>
#include "Song.h"

class Playlist{
    public:
        Playlist();
        Playlist(string);
        Playlist(const Playlist &);
        string getName();
        void setName(string);
        int getMaxSongs();
        int getNumSongs();
        Song getSong(int);
        bool containsSong(Song);
        void printSongs();
        void addSong(Song);
        void removeSong(string);
        void calculateTotalTime();
        friend ostream& operator<< (ostream&, const Playlist&);

    private:
        int numSongs;
        int maxSongs;
        int numMins;
        int numSecs;
        string name, createTime;
        Song * songList;
        

};
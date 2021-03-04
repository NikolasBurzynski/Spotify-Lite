#pragma once
#include <iostream>
#include "Song.h"


class Library{
    public:
        Library(const int size);
        void printLibrary();
        void addSong(Song);
        int numSongs;   
        ~Library();
    private:
        Song * songList;
};
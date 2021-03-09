#pragma once
#include <iostream>
#include <string>
#include "Song.h"

class Playlist{
    public:
        Playlist(string);
        ~Playlist();
        Playlist(const Playlist &);
        int numSongs;
        void showSongs();
        void printDetails();
        void addSong(Song);
        void removeSong(string title);

    private:
        string name, createDate, createTime;
        Song * songList;

};
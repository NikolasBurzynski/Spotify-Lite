#pragma once
#include <iostream>
#include <string>
#include "Song.h"

class Playlist{
    public:
        Playlist(string);
        ~Playlist();
        Playlist(Playlist);
        void show();
        void addSong(Song);
        void removeSong(Song);

    private:
        string name, createDate, createTime;

}
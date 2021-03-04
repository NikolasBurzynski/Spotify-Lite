#pragma once
#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include <string>


class Library{
    public:
        Library(const int size);
        void printLibrary();
        void addSong(Song);
        void addPlaylist(string);
        int numSongs; 
        int maxSongs;  
        ~Library();
    private:
        Song * songList;
        Playlist * list_of_playlists;
};
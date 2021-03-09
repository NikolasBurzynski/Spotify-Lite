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
        void showPlaylists();
        int numSongs; 
        int numPlaylists;
        int maxSongs;  
        ~Library();
    private:
        Song * songList;
        Playlist * playlists;
};
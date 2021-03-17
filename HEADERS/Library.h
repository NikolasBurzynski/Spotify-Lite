#pragma once
#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include <string>


class Library{
    public:
        Library(const int, const int);
        void printLibrary();
        void addSong(Song);
        void addPlaylist(string);
        void showPlaylists();
        void printPlaylist(string);
        int getNumSongs();
        int getNumPlaylists();
        void addSongtoPlaylist(Song, string);
        void addSongsfromPlaylist(string);
        bool containsPlaylist(string);
        Song getSong(string);
        bool containsSong(Song);
        bool containsSong(string);
        void removeSong(string);
        void removeSongfromPlaylist(string, string);
        void removePlaylist(string);
        void clonePlaylist(string, string);
        ~Library();
        friend void operator+=(const Library& , string);
    private:
        int numSongs; 
        int numPlaylists;
        int maxSongs;
        int maxPlaylists;
        Song * songList;
        Playlist * playlists;
};
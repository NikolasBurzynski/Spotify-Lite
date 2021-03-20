#pragma once
#include "Timestamp.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Song{
    private:
        string title, artist, duration, Explicit, month, day, year, time;  
    public:
        Song();
        Song(string, string, string, string, string, string, string, string);
        ~Song(){}
        Song(const Song&);
        void setSongInfo(string, string, string, string, string, string, string, string);
        void toString(); 
        string getTitle();
        int getSecs();
        int getMins();   

    friend bool operator==(const Song&, const Song&);
};


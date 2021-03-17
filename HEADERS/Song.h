#pragma once
#include "Timestamp.h"
#include <stdlib.h>
#include <string>

using namespace std;

class Song{
    private:
        string title, artist, duration, time, Explicit, timestamp;  
        Timestamp addTime;
    public:
        Song();
        Song(const Song&);
        void setSongInfo(string, string, string, string);
        void toString(); 
        string getTitle();
        int getSecs();
        int getMins();   

    friend bool operator==(const Song&, const Song&);
};


#pragma once
#include <stdlib.h>
#include <string>

using namespace std;

class Song{
    private:
        string title, artist, time, date, duration, Explicit;  
    public:
        void setSongInfo(string, string, string, string, string, string);
        void toString();    

    friend bool operator==(const Song&, const Song&);
};


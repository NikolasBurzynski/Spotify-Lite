#include <iostream>
#include <stdlib.h>
#include <string>
#include "Song.h"


void Song::setSongInfo(string inTitle, string inArtist, string inDuration, string inDate, string inTime, string inExplicit){
    title = inTitle;
    artist = inArtist;
    duration = inDuration;
    date = inDate;
    time = inTime;
    Explicit = inExplicit;
}

void Song::toString(){
    cout << title << " "<< artist << " E:" << Explicit << " " << duration << " " << time << " " << date << endl;
}

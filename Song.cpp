#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Song.h"


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

bool operator==(const Song & songA, const Song & songB){
    if(songA.title.compare(songB.title) == 0){
        return true;
    }else{
        return false;
    }

}

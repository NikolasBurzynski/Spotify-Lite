#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Song.h"

Song::Song(){}

void Song::setSongInfo(string inTitle, string inArtist, string inDuration, string inExplicit){
    title = inTitle;
    artist = inArtist;
    duration = inDuration;
    Explicit = inExplicit;
    Timestamp addTime = Timestamp();
    timestamp = addTime.toString();

}

Song::Song(const Song& source){
    title = source.title;
    artist = source.artist;
    duration = source.duration;
    Explicit = source.Explicit;
    timestamp = source.timestamp;
}

int Song::getMins(){
    string sMins = duration.substr(0,2);
    int mins = stoi(sMins, NULL, 10);
    return mins;
}

int Song::getSecs(){
    string sSecs = duration.substr(3,2);
    int secs = stoi(sSecs, NULL, 10); 
    return secs;
}

string Song::getTitle(){
    return title;
}

void Song::toString(){
    cout << title << " "<< artist << " E:" << Explicit << " " << timestamp << endl;
}

bool operator==(const Song & songA, const Song & songB){
    if(songA.title.compare(songB.title) == 0){
        return true;
    }else{
        return false;
    }

}

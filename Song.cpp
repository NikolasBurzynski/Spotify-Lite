#include <iostream>
#include <stdlib.h>
#include <string>
#include "HEADERS/Song.h"
using namespace std;

Song::Song(){
    // cout << "Song Empty Constructor" << endl;
    title = "";
    artist = "";
    duration = "";
    Explicit = "";
    month = "";
    day = "";
    year = "";
    time = "";
}

Song::Song(string inTitle, string inArtist, string inDuration, string inExplicit, string inMonth, string inDay, string inYear, string inTime){
    cout << "Song Value Constructor" << endl;
    title = inTitle;
    artist = inArtist;
    duration = inDuration;
    Explicit = inExplicit;
    month = inMonth;
    day = inDay;
    year = inYear;
    time = inTime;
}

Song::Song(const Song & source){
    cout << "Song Copy Constructor" << endl;
    title = source.title;
    artist = source.artist;
    duration = source.duration;
    Explicit = source.Explicit;
    month = source.month;
    day = source.day;
    year = source.year;
    time = source.time;
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
    cout << title << " "<< artist << " E:" << Explicit << " Duration " << duration << " Date Created: " << month << "/" << day << "/" << year << " Time Created: " << time << endl;
}

bool operator==(const Song & songA, const Song & songB){
    if(songA.title.compare(songB.title) == 0){
        return true;
    }else{
        return false;
    }
}
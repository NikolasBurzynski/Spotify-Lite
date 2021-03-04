#include <iostream>
#include <string>
#include "HEADERS/Library.h"
using namespace std;

const int MAX_SONGS = 10;
Library library(MAX_SONGS);


bool checkNum(string input){
    try{
        int num = stoi(input,NULL,10);
        return false;
    }catch(exception& e){
        cout << "Invalid Syntax"; 
        return true;
    }
}

void addSong(){
    cin.ignore();
    cout << "Sweet lets get some info about the song!\n";
    cout << "Enter the song title\n";
    string title; getline(cin, title);
    cout << "Enter the artist name\n";
    string artist; getline(cin, artist);
    cout << "Enter the song duration as \"MM:SS\"\n";
    string duration; getline(cin, duration);
    //Error check the duration
    if(duration.length() != 5){ cout << "Invalid Syntax"; return;}
    string inMin = duration.substr(0,2);
    if(checkNum(inMin)) return;
    string colon = duration.substr(2,1);
    if(colon.compare(":") != 0){ cout << "Invalid Syntax"; return;}
    string inSec = duration.substr(3,2);
    if(checkNum(inSec)) return;
    cout << "Enter today's date as \"MM/DD/YYYY\"\n";
    string date; getline(cin, date);
    //Error check the date
    if(date.length() != 10){ cout << "Invalid Syntax"; return;}
    string month = date.substr(0,2);
    if(checkNum(month)) return;
    string slash1 = date.substr(2,1);
    if(slash1.compare("/") != 0){ cout << "Invalid Syntax"; return;}
    string day = date.substr(3,2);
    if(checkNum(day)) return;
    string slash2 = date.substr(5,1);
    if(slash2.compare("/") != 0){ cout << "Invalid Syntax"; return;}
    string year = date.substr(6,4);
    if(checkNum(year)) return;
    cout << "Enter the time as \"HH:MM\" using military time\n";
    string time; getline(cin, time);
    //Error check the time
    if(time.length() != 5){ cout << "Invalid Syntax"; return;}
    string inHour = time.substr(0,2);
    if(checkNum(inHour)) return;
    colon = time.substr(2,1);
    if(colon.compare(":") != 0){ cout << "Invalid Syntax"; return;}
    string timeMin = time.substr(3,2);
    if(checkNum(timeMin)) return;
    cout << "And lastly does this song contain explicit lyrics? Type \"no\" or \"yes\".\n";
    string exp; cin >> exp;
    if(exp.compare("no") != 0 && exp.compare("yes") != 0){ cout << "Invalid Syntax"; return;}
    Song newSong;
    newSong.setSongInfo(title, artist, duration, date, time, exp);
    library.addSong(newSong);
    cout << "Song Added!" << endl;
}

void showSongs(){
    if(library.numSongs == 0) cout << "There are no songs in the library\n";
    else{
        cout << "Songs: " << library.numSongs << " Capacity: " << MAX_SONGS << endl;
        library.printLibrary();
    }
}

int UI(){
    cout<<"\n\nType: \"add\" to add a song\n";
    cout<<"Type: \"show\" to show all the songs in our library\n";
    cout<<"Type: \"exit\" to exit the program\n\n";
    string selection;
    cin >> selection;
    if(selection.compare("add") == 0){
        addSong();
        return 0;
    }else if(selection.compare("show") == 0){
        showSongs();
        return 0;
    }else if(selection.compare("exit") == 0){
        return 1;
    }else{
        cout << "Invalid input please try again.\n";
        return 0;
    }
}

int main(){
    cout<<"\nHello and welcome to Nikofy!\n";
    while(UI() == 0);
    cout << "Ending Program" << endl;
}
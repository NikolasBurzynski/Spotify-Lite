#include <iostream>
#include <string.h>
#include "HEADERS/Library.h"
#include "HEADERS/Parser.h"
using namespace std;


const int startMaxSong = 1;
const int startMaxPlaylist = 1;
Library library(startMaxSong, startMaxPlaylist);

string currentPlaylist = "LIBRARY";

void invalidInputError(string badIn){
    cout << "Input Error: \"" << badIn << "\" not understood." << endl;
}

bool checkNum(string input){
    try{
        int num = stoi(input,NULL,10);
        return false;
    }catch(exception& e){
        cout << "Invalid Syntax" << endl; 
        return true;
    }
}

void addNewPlaylist(string arg2){
    string playlistName;
    if(arg2.length() == 0){
        cout << "Please enter a playlist name:" << endl;
        cin >> playlistName;
    }else{
        playlistName = arg2;
    }
    if(!library.containsPlaylist(playlistName)){
        library.addPlaylist(playlistName);
        currentPlaylist = playlistName;
    }else{
        cout << playlistName << " is already a playlist name" << endl;
    }
}

void addNewSong(){
    currentPlaylist = "LIBRARY";
    cout << "Sweet lets get some info about the song!\n";
    cout << "Enter the song title\n";
    string title; getline(cin, title);
    int firstIndex = title.find_first_not_of(" \t");
    int lastIndex = title.find_last_not_of(" \t");
    int range = lastIndex - firstIndex + 1;
    title = title.substr(firstIndex, range);
    cout << "Enter the artist name\n";
    string artist; getline(cin, artist);
    firstIndex = artist.find_first_not_of(" \t");
    lastIndex = artist.find_last_not_of(" \t");
    range = lastIndex - firstIndex + 1;
    artist = artist.substr(firstIndex, range);
    cout << "Enter the song duration as \"MM:SS\"\n";
    string duration; getline(cin, duration);
    if(duration.length() != 5){ cout << "Invalid Syntax" << endl; return;}
    string inMin = duration.substr(0,2);
    if(checkNum(inMin)) return;
    string colon = duration.substr(2,1);
    if(colon.compare(":") != 0){ cout << "Invalid Syntax" << endl; return;}
    string inSec = duration.substr(3,2);
    if(checkNum(inSec)) return;
    cout << "Does this song contain explicit lyrics? Type \"n\" or \"y\".\n";
    string exp; getline(cin, exp);
    if(exp.compare("n") != 0 && exp.compare("y") != 0){ cout << "Invalid Syntax" << endl; return;}
    cout << "Enter the time as \"HH:MM:SS\" using military time\n";
    string time; getline(cin, time);
    if(time.length() != 8){ cout << "Invalid Syntax"; return;}
    string inHour = time.substr(0,2);
    if(checkNum(inHour)) return;
    colon = time.substr(2,1);
    if(colon.compare(":") != 0){ cout << "Invalid Syntax"; return;}
    string timeMin = time.substr(3,2);
    if(checkNum(timeMin)) return;
    cout << "Enter today's date as \"MM/DD/YYYY\"\n";
    string date; getline(cin, date);
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
    Song newSong(title, artist, duration, exp, month, day, year, time);
    if(!library.containsSong(newSong)){
        library.addSong(newSong);
    }else{
        cout << "\"" << newSong.getTitle() <<"\"" << " already exists in the library" << endl;
    }
}

// void import(string command){
//     std::stringstream is;
//     is.str(command);
//     string temp;
//     is >> temp; //throw import away
//     while(is >> temp){
//         if(library.containsPlaylist(temp)){
//             library.importPlaylist(temp, currentPlaylist);
//         }else{
//             cout << temp << " is not a playlist";
//         }
//     }

// }

int UI(){
    string line;
    cout << "Enter text: ";
    while(line.compare("") == 0){
        getline(cin, line);
    }
    // cout << line << endl;
    // if(line.substr(0,6).compare("import") == 0){
    //     import(line);
    //     cout << "Import Finished" << endl;
    //     return 0;
    // }
    Parser command(line);
    string op = command.getOperation();
    string arg1 = command.getArg1();
    string arg2 = command.getArg2();
    // cout << "  op:" << op << endl;
    // cout << "arg1:" << arg1 << endl;
    // cout << "arg2:" << arg2 << endl;
    if(op.compare("select") == 0){
        if(arg1.compare("library") == 0){
            currentPlaylist = "LIBRARY";
            cout << "Selected Library" << endl;
        }else if(arg1.compare("playlist") == 0){
            size_t found = arg2.find(" ");
            if(found != std::string::npos) arg2 = arg2.substr(0,found);
            bool exists = library.containsPlaylist(arg2);
            if(exists){currentPlaylist = arg2;}
            else{
                cout << "\"" << arg2 << "\" is not a playlist" << endl; 
            }
        }else{
            invalidInputError(arg1);
        }
        return 0;
    }else if(op.compare("add") == 0){
        if(arg1.compare("song") == 0 && arg2.length() == 0){
            addNewSong();
        }else if(arg1.compare("playlist") == 0){
            addNewPlaylist(arg2);
            cout << currentPlaylist << endl;
        }
    }//else if(arg1.compare("song") == 0 && arg2.length() != 0){
    //         if(library.containsSong(arg2)){
    //             cout << "Found Song" << endl;
    //             if(currentPlaylist.compare("LIBRARY") == 0){
    //                 cout << "Please select a playlist first" << endl;
    //                 return 0;
    //             }
    //             library.addSongtoPlaylist(library.getSong(arg2), currentPlaylist);
    //             cout << "Added song to playlist: " << currentPlaylist << endl;
    //         }else{
    //             cout << "\"" << arg2 << "\"" << " is not in your library." << endl;
    //         }
    //     }else{
    //         invalidInputError(arg1);
    //     }
    //     return 0;
    // else if(op.compare("remove") == 0){
    //     if(arg1.compare("song") == 0){
    //         if(currentPlaylist.compare("LIBRARY") == 0){
    //             if(library.containsSong(arg2)){
    //                 library.removeSong(arg2);
    //                 cout << "Song Removed" << endl;
    //             }else{
    //                 cout << "Song: " << "\"" << arg2 << "\"" << "is not in your library." << endl;
    //                 return 0;
    //             }
    //         }else{
    //             library.removeSongfromPlaylist(arg2, currentPlaylist);
    //             cout << "Song Removed" << endl;
    //         }
    //     }else if(arg1.compare("playlist")==0){
    //         if(arg2.compare("") == 0){
    //             if(currentPlaylist.compare("LIBRARY") == 0){
    //                 library.removePlaylist(currentPlaylist);
    //                 currentPlaylist = "LIBRARY";
    //             }else{
    //                 cout << "Cannot remove Library" << endl;
    //                 return 0;
    //             }
    //         }
    //         else{
    //             if(library.containsPlaylist(arg2)){
    //                 library.removePlaylist(arg2);
    //                 currentPlaylist = "LIBRARY";
    //             }else{
    //                 cout << "Playlist " << "\"" << arg2 << "\"" << " does not exist.";
    //                 return 0;
    //             }
    //         }
    //     }
    //     else{
    //         invalidInputError(arg1);
    //     }
    //     return 0;
    // }else if(op.compare("show") == 0){
    //     if(arg1.compare("playlists") == 0){
    //         library.showPlaylists();
    //     }else if(arg1.compare("song") == 0){
    //         if(currentPlaylist.compare("LIBRARY") == 0){
    //             if(!library.containsSong(arg2)){
    //                 cout << "Library does not contain: " << arg2 << endl;
    //                 return 0;
    //             }
    //             library.getSong(arg2).toString();
    //         }else{
    //             library.printSongfromPlaylist(currentPlaylist, arg2);
    //         }
    //     }else if (arg1.compare("songs") == 0){
    //         library.printLibrary();
    //     }else if (arg1.compare("playlist") == 0){
    //         if(arg2.compare("") == 0){
    //             if(currentPlaylist.compare("LIBRARY") != 0){
    //                 library.printPlaylist(currentPlaylist);
    //             }else{
    //                 cout << "Please select a playlist" << endl;
    //             }
    //         }else{
    //             if(library.containsPlaylist(arg2)){
    //                 library.printPlaylist(arg2);
    //             }else{
    //                 cout << "Playlist " << "\"" << arg2 << "\"" << " does not exist.";
    //                 return 0;
    //             }
    //         }
    //     }
    //     return 0;
    // }else if(op.compare("clone") == 0){
    //     if(currentPlaylist.compare("LIBRARY") == 0){
    //         cout << "No playlist selected" << endl;
    //         return 0;
    //     }
    //     if(arg1.compare("") == 0){
    //         cout << "Invalid Syntax" << endl;
    //     }else{
    //         library.clonePlaylist(currentPlaylist, arg1);
    //     }
    //     return 0;
    else if(op.compare("exit") == 0){
        return 1;
    }else{
        invalidInputError(op);
        return 0;
    }
    return 0;
}

int main(){
    cout<<"\nHello and welcome to Nikofy!\n";
    while(UI() == 0);
    cout << "Ending Program" << endl;
}
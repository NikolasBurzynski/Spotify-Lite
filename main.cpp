#include <iostream>
#include <string.h>
#include "HEADERS/Library.h"
#include "HEADERS/Parser.h"
using namespace std;


const int startSongSize = 2;
const int startPlaylistSize = 1;
Library library(startSongSize, startPlaylistSize);

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
        // cout << "WHAT THE FUCK" << endl;
        currentPlaylist = playlistName;
        // cout << "This some Bullshit" << endl;
    }else{
        cout << playlistName << " is already a playlist name" << endl;
    }

}

void addNewSong(){
    currentPlaylist = "LIBRARY";
    cout << "Sweet lets get some info about the song!\n";
    cout << "Enter the song title\n";
    string title; getline(cin, title);
    cout << "Enter the artist name\n";
    string artist; getline(cin, artist);
    cout << "Enter the song duration as \"MM:SS\"\n";
    string duration; getline(cin, duration);
    //Error check the duration
    if(duration.length() != 5){ cout << "Invalid Syntax" << endl; return;}
    string inMin = duration.substr(0,2);
    if(checkNum(inMin)) return;
    string colon = duration.substr(2,1);
    if(colon.compare(":") != 0){ cout << "Invalid Syntax" << endl; return;}
    string inSec = duration.substr(3,2);
    if(checkNum(inSec)) return;
    cout << "And lastly does this song contain explicit lyrics? Type \"no\" or \"yes\".\n";
    string exp; cin >> exp;
    if(exp.compare("no") != 0 && exp.compare("yes") != 0){ cout << "Invalid Syntax" << endl; return;}
    Song newSong;
    newSong.setSongInfo(title, artist, duration, exp);
    if(!library.containsSong(newSong)){
        library.addSong(newSong);
        cout << "Song Added!" << endl;
    }else{
        cout << "\"" << newSong.getTitle() <<"\"" << " already exists in the library" << endl;
    }
}

void import(string command){
    std::stringstream is;
    is.str(command);
    string temp;
    is >> temp; //throw import away
    while(is >> temp){
        if(library.containsPlaylist(temp)){
            library += temp;
        }else{
            cout << temp << " is not a playlist";
        }
    }

}

int UI(){
    string line;
    cout << "Enter text: ";
    while(line.compare("") == 0){
        getline(cin, line);
    }
    cout << line << endl;
    if(line.substr(0,6).compare("import") == 0){
        import(line);
    }
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
            // cout << currentPlaylist << endl;
        }else if(arg1.compare("song") == 0 && arg2.length() != 0){
            if(library.containsSong(arg2)){
                cout << "Found Song" << endl;
                if(currentPlaylist.compare("LIBRARY") == 0){
                    cout << "Please select a playlist first" << endl;
                    return 0;
                }
                library.addSongtoPlaylist(library.getSong(arg2), currentPlaylist);
                cout << "Added song to playlist: " << currentPlaylist << endl;
            }else{
                cout << "\"" << arg2 << "\"" << " is not in your library." << endl;
            }
        }else{
            invalidInputError(arg1);
        }
        return 0;
    }else if(op.compare("remove") == 0){
        if(arg1.compare("song") == 0){
            if(currentPlaylist.compare("LIBRARY") == 0){
                if(library.containsSong(arg2)){
                    library.removeSong(arg2);
                }else{
                    cout << "Song: " << "\"" << arg2 << "\"" << "is not in your library." << endl;
                    return 0;
                }
            }else{
                library.removeSongfromPlaylist(arg2, currentPlaylist);
            }
        }else if(arg1.compare("playlist")==0){
            if(arg2.compare("") == 0){
                if(currentPlaylist.compare("LIBRARY") == 0){
                    library.removePlaylist(currentPlaylist);
                    currentPlaylist = "LIBRARY";
                }else{
                    cout << "Cannot remove Library" << endl;
                    return 0;
                }
            }
            else{
                if(library.containsPlaylist(arg2)){
                    library.removePlaylist(arg2);
                    currentPlaylist = "LIBRARY";
                }else{
                    cout << "Playlist " << "\"" << arg2 << "\"" << " does not exist.";
                    return 0;
                }
            }
        }
        else{
            invalidInputError(arg1);
        }
        return 0;
    }else if(op.compare("show") == 0){
        if(arg1.compare("playlists") == 0){
            library.showPlaylists();
        }else if (arg1.compare("songs") == 0){
            library.printLibrary();
        }else if (arg1.compare("playlist") == 0){
            if(arg2.compare("") == 0){
                if(currentPlaylist.compare("LIBRARY") != 0){
                    library.printPlaylist(currentPlaylist);
                }else{
                    cout << "Please select a playlist" << endl;
                }
            }else{
                if(library.containsPlaylist(arg2)){
                    library.printPlaylist(arg2);
                }else{
                    cout << "Playlist " << "\"" << arg2 << "\"" << " does not exist.";
                    return 0;
                }
            }
        }
        return 0;
    }else if(op.compare("clone") == 0){
        if(currentPlaylist.compare("LIBRARY") == 0){
            cout << "No playlist selected" << endl;
            return 0;
        }
        if(arg1.compare("") == 0){
            cout << "Invalid Syntax" << endl;
        }else{
            library.clonePlaylist(currentPlaylist, arg1);
        }
        return 0;
    }else if(op.compare("exit") == 0){
        return 1;
    }else{
        invalidInputError(op);
        return 0;
    }
}

int main(){
    cout<<"\nHello and welcome to Nikofy!\n";
    while(UI() == 0);
    cout << "Ending Program" << endl;
}
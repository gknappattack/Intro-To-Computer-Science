//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;

string GetUserString(const string& prompt);

void AddSongsMenuOption(vector<Song*>& list);
void ListSongsMenuOption(vector<Song*>& list);
void AddPlaylistMenuOption(vector<Playlist>& playLists);
void AddSongToPlaylistMenuOption(vector<Playlist>& playLists, vector<Song*>& list);
void ListPlaylistsMenuOption(vector<Playlist>& playLists);
void PlayPlaylistMenuOption(vector<Playlist>& playLists, vector<Song*>& list);
void RemovePlaylistMenuOption(vector<Playlist>& playLists);
void RemoveSongFromPlaylistMenuOption(vector<Playlist>& playLists, vector<Song*>& list);
void RemoveSongFromLibraryMenuOption(vector<Playlist>& playLists, vector<Song*>& list);
void OptionsMenuOption();
void QuitMenuOption();

int main() {
    vector<Song*> songList;
    vector<Playlist> playlistList;

    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

    string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songList);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(songList);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlistList);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(playlistList, songList);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlistList);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlistList, songList);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlistList);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlistList, songList);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(playlistList, songList);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }


    //Deleting memory of all remaining songs!! FOR TAS
    for (unsigned int i = 0; i < songList.size(); ++i) {
        delete songList.at(i);
    }

    for (unsigned int i = 0; i < songList.size(); ++i) {
        songList.erase(songList.begin() + i);
    }

    return 0;
}

string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}

void AddSongsMenuOption(vector<Song*>& list) {
    string DONE_KEYWORD = "DONE";
    cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;

    string songName = "none";
    string firstLine = "none";
    Song* newSong = nullptr;

    songName = GetUserString("Song Name: ");

    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        newSong = new Song(songName, firstLine);
        list.push_back(newSong);

        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(vector<Song*>& list) {

    for (unsigned int i = 0; i < list.size(); ++i) {
        (*list.at(i)).PrintSong();
    }
    cout << endl;
}

void AddPlaylistMenuOption(vector<Playlist>& playLists) {
    string playlistTitle = "none";
    Playlist newPlaylist;

    cout << "Playlist name: " << endl;
    getline(cin, playlistTitle);

    newPlaylist = Playlist(playlistTitle);
    playLists.push_back(newPlaylist);
}

void AddSongToPlaylistMenuOption(vector<Playlist>& playLists, vector<Song*>& list) {
    int playlistIndex = -1;
    int songIndex = -1;
    Song* songAdd = nullptr;

    for (unsigned int i = 0; i < playLists.size(); ++i) {
        cout << i << ": ";
        playLists.at(i).PrintList();
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> playlistIndex;

    for (unsigned int i = 0; i < list.size(); ++i) {
        cout << i << ": ";
        (*list.at(i)).PrintTitle();
    }

    cout << "Pick a song index number: " << endl;
    cin >> songIndex;

    songAdd = list.at(songIndex);
    playLists.at(playlistIndex).getMyVec().push_back(songAdd);

    cin.clear();
    cin.ignore(1000, '\n');
}

void ListPlaylistsMenuOption(vector<Playlist>& playLists) {
    for (unsigned int i = 0; i < playLists.size(); ++i) {
        cout << i << ": ";
        playLists.at(i).PrintList();
    }
    cout << endl;
}

void PlayPlaylistMenuOption(vector<Playlist>& playLists, vector<Song*>& list) {
    int playlistIndex = -1;
    vector<Song> playPlaylist;

    for (unsigned int i = 0; i < playLists.size(); ++i) {
        cout << i << ": ";
        playLists.at(i).PrintList();
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> playlistIndex;

    cout << "Playing songs from playlist: ";
    playLists.at(playlistIndex).PrintList();

    playLists.at(playlistIndex).PrintSongs();
    cout << endl;

    playLists.at(playlistIndex).UpdatePlay();

    cin.clear();
    cin.ignore(1000, '\n');
}

void RemovePlaylistMenuOption(vector<Playlist>& playLists) {
    int playlistIndex = -1;

    for (unsigned int i = 0; i < playLists.size(); ++i) {
        cout << i << ": ";
        playLists.at(i).PrintList();
    }
    cout << "Pick a playlist index number to remove: " << endl;
    cin >> playlistIndex;

    playLists.erase(playLists.begin() + playlistIndex);

    cin.clear();
    cin.ignore(1000, '\n');
}

void RemoveSongFromPlaylistMenuOption(vector<Playlist>& playLists, vector<Song*>& list) {
    int playlistIndex = -1;
    int songIndex = -1;

    for (unsigned int i = 0; i < playLists.size(); ++i) {
        cout << i << ": ";
        playLists.at(i).PrintList();
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> playlistIndex;

    playLists.at(playlistIndex).PrintSongList();

    cout << "Pick a song index number to remove: " << endl;
    cin >> songIndex;

    string songName = playLists.at(playlistIndex).getMyVec().at(songIndex)->GetTitle();

    playLists.at(playlistIndex).getMyVec().erase(playLists.at(playlistIndex).getMyVec().begin() + songIndex);

    cin.clear();
    cin.ignore(1000, '\n');
}

void RemoveSongFromLibraryMenuOption(vector<Playlist>& playLists, vector<Song*>& list) {
    int songIndex = -1;
    string songName = "none";


    //Search and delete from Playlists
    for (unsigned int i = 0; i < list.size(); ++i) {
        cout << i << ": ";
        (*list.at(i)).PrintTitle();
    }
    cout << "Pick a song index number to remove: " << endl;
    cin >> songIndex;

    songName = list.at(songIndex)->GetTitle();


    for (unsigned int i = 0; i < playLists.size(); ++i) {
        playLists.at(i).DeleteSong(songName);
    }

    //Lines to free memory!! FOR TA's
    delete list.at(songIndex);
    list.erase(list.begin() + songIndex);

    cin.clear();
    cin.ignore(1000, '\n');
}

void OptionsMenuOption() {
    cout << "add      Adds a list of songs to the library" << endl
              << "list     Lists all the songs in the library" << endl
              << "addp     Adds a new playlist" << endl
              << "addsp    Adds a song to a playlist" << endl
              << "listp    Lists all the playlists" << endl
              << "play     Plays a playlist" << endl
              << "remp     Removes a playlist" << endl
              << "remsp    Removes a song from a playlist" << endl
              << "remsl    Removes a song from the library (and all playlists)" << endl
              << "options  Prints this options menu" << endl
              << "quit     Quits the program" << endl << endl;
}

void QuitMenuOption() {
    cout << "Goodbye!" << endl;
}


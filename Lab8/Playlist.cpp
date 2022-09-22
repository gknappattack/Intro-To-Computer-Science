//
// Created by Gregory Knapp on 3/22/20.
//

#include <iostream>
#include <vector>
using namespace std;

#include "Song.h"
#include "Playlist.h"

Playlist::Playlist() {
    playlistName = "none";
}

Playlist::Playlist(string name) {
    playlistName = name;
}

void Playlist::PrintList() {
    cout << this->playlistName << endl;
}

void Playlist::PrintSongs() {
    for (unsigned int i = 0; i < songPlay.size(); ++i) {
        (*songPlay.at(i)).PrintLine();
    }
}
void Playlist::UpdatePlay() {
    for (unsigned int i = 0; i < songPlay.size(); ++i) {
        (*songPlay.at(i)).UpdatePlayCount();
    }
}
vector<Song*> &Playlist::getMyVec() {
    return songPlay;
}

void Playlist::PrintSongList() {
    for (unsigned int i = 0; i < songPlay.size(); ++i) {
        cout << i << ": ";
        (*songPlay.at(i)).PrintTitle();
    }
}
void Playlist::DeleteSong(string deleteName) {
    int deleteIndex = -1;

    for (unsigned int i = 0; i < songPlay.size(); ++i) {
        if (songPlay.at(i)->GetTitle() == deleteName) {
            deleteIndex = i;
        }
    }
    songPlay.erase(songPlay.begin() + deleteIndex);


}
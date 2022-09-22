//
// Created by Gregory Knapp on 3/22/20.
//

#include <iostream>
#include <vector>
using namespace std;

#include "Song.h"

Song::Song() {
    songName = "none";
    firstLine = "none";
    playCount = 0;
}

Song::Song(string name, string first) {
    songName = name;
    firstLine = first;
    playCount = 0;
}
void Song::PrintSong() {
    cout << this->songName << ": \"" << this->firstLine << "\", " << this->playCount << " play(s)." << endl;
}
void Song::PrintTitle() {
    cout << this->songName << endl;
}
void Song::PrintLine() {
    cout << firstLine << endl;
}
void Song::UpdatePlayCount() {
    playCount = playCount + 1;
}
string Song::GetTitle() {
    return songName;
}

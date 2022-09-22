//
// Created by Gregory Knapp on 3/22/20.
//

#ifndef MAINLAB8_PLAYLIST_H
#define MAINLAB8_PLAYLIST_H

using namespace std;


class Playlist {
public:
    Playlist();
    Playlist(string name);
    void PrintList();
    void PrintSongs();
    vector<Song*>& getMyVec();
    void UpdatePlay();
    void PrintSongList();
    void DeleteSong(string deleteName);
private:
    string playlistName;
    vector<Song*> songPlay;
};

#endif //MAINLAB8_PLAYLIST_H

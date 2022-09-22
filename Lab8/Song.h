//
// Created by Gregory Knapp on 3/22/20.
//

#ifndef MAINLAB8_SONG_H
#define MAINLAB8_SONG_H

using namespace std;


class Song {
public:
    Song();
    Song(string name, string first);
    void UpdatePlayCount();
    void PrintSong();
    void PrintTitle();
    void PrintLine();
    string GetTitle();
private:
    string songName;
    string firstLine;
    int playCount;
};


#endif //MAINLAB8_SONG_H

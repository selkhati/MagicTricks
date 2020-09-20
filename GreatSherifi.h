//
// Created by Sherif Elkhatib on 8/2/20.
//
#include <string>
using namespace std;

#ifndef ASSIGNMENTA7_MAGIC_GREATSHERIFI_H
#define ASSIGNMENTA7_MAGIC_GREATSHERIFI_H


class GreatSherifi {
public:
    GreatSherifi();
    GreatSherifi(string songLines[], string missingLyrics[], string prize);
//    string getWordGuess();
//    void setWordGuess(string& word);
//    int getNumGuess();
//    void setNumGuess(int& number);
    string getPrize();

    void riddleMeThis();
    void guessTheNumber(int numGuess);
    void hipHopLyric(string wordGuess);
    void prizeWinner();

private:
    void introduction();
    string wordGuess;
    int numGuess;
    string lyricsKey[5];
    string lyrics[5];
    string prizeItem;




};

#endif //ASSIGNMENTA7_MAGIC_GREATSHERIFI_H

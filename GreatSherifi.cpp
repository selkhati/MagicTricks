//
// Created by Sherif Elkhatib on 8/2/20.
//
#include <iostream>
#include <ctime>
#include <string>
#include "GreatSherifi.h"
using namespace std;

// default constructor
GreatSherifi::GreatSherifi() {

    // Each song line is represented by an index of the lyrics array.
    lyrics[0] = "His palms are sweaty, knees weak, arms are heavy/There's vomit on his sweater already: mom's _.";
    lyrics[1] = "It was all a _. I used to read Word Up magazine.";
    lyrics[2] = "I'm not a businessman. I'm a _, man.";
    lyrics[3] = "Don't call it a _. I been here for years!";
    lyrics[4] = "I never sleep because sleep is the cousin of _.";

    // Each corresponding missing word to the lyrics above resides in this array
    lyricsKey[0] = "spaghetti";
    lyricsKey[1] = "dream";
    lyricsKey[2] = "business";
    lyricsKey[3] = "comeback";
    lyricsKey[4] = "death";

    prizeItem = "puppy";
}

// non-default constructor
GreatSherifi::GreatSherifi(string songLines[5], string missingLyrics[5], string prize) {
    for (int i = 0; i < 5; i++) lyrics[i] = songLines[i]; // set lyrics array equal to songLines array
    for (int i = 0; i < 5; i++) lyricsKey[i] = missingLyrics[i]; // set lyricsKey array equal to missingLyrics array
    prize = prizeItem;
}

//string GreatSherifi::getWordGuess() {
//    return wordGuess;
//}
//
//void GreatSherifi::setWordGuess(string& word) {
//    wordGuess = word;
//}
//
//int GreatSherifi::getNumGuess() {
//    return numGuess;
//}
//
//void GreatSherifi::setNumGuess(int& number) {
//    numGuess = number;
//}

string GreatSherifi::getPrize() {
    return prizeItem;
}

// Introduction function
void GreatSherifi::introduction() {

    cout << "Welcome to the Great Sherifi's magic show! Complete these three challenges to win." << endl;
    cout << "Fail any of these challenges and go home with NOTHING. *maniacal laughter*" << endl << endl;

    cout << "Challenge #1: Saw a lady in half.";
    cout << "\n \t Saw a lady in half correctly within (5) attempts and win a prize!" << endl << endl;

    cout << "Challenge #2: Guess a number between 1 and 50.";
    cout << "\n \t The merciful Sherifi will tell you if your answer is close (within 5) or too far off (10+)";
    cout << "\n \t You will also have (5) tries to get the number right." << endl << endl;

    cout << "Challenge #3: Complete the hip-hop line.";
    cout << "\n \t Fill in the blank of an iconic hip-hop lyric. You can choose your difficulty.";
    cout << "\n \t You get (2) attempts per entry." << endl << endl;
}

// Challenge 1:
void GreatSherifi::riddleMeThis() {
    introduction(); // Describes the games and how to play
    string wordGuess;
    int wrongCount = 0; // declared outside of for loop because it is used multiple times in the riddle function

    for (wrongCount = 0; wrongCount < 5; wrongCount++) { // Gives the user (5) tries before exiting the loop
        cout << "Saw a lady in half, separating the two halves with a dash \"-\": ";
        getline(cin, wordGuess); // Gathers the entire line to account for white spaces

        if (wordGuess == "a l-ady" || wordGuess == "la-dy") {
            cout << "You get it! You sawed \"a lady\" in half. HA. Get it? Get ready for Challenge #2" << endl;
            break; // Once the user guesses correctly, exit the loop and continue the game.
        }

        if (wordGuess != "a l-ady" && wordGuess != "la-dy") {
            cout << "Nope. Try again. " << endl;
        }
    }

    if (wrongCount == 5) { // Was the loop exited because of the wrongCount? If so, game over.
        cout << "Oooh... that was not pretty. Liability waivers only cover so much :(. You lose!" << endl;
        exit(0); // Closes the program. Prizes are for winners.
    }
    cout << endl;
}

// Challenge 2:
void GreatSherifi::guessTheNumber(int numGuess) {
    srand(time(0)); // seed random to time
    rand(); // throw-away first value associated with time
    int randomNumber = (rand() % 50) + 1; // Sets a random number between 1 and 50, inclusive.
    int wrongCount = 0;

    // cout << "TEST: NUMBER IS " << randomNumber << endl;

    cout << "Guess the magic number set between 1 and 50: " << endl;

    for (wrongCount = 0; wrongCount < 5; wrongCount++) {
        cout << "What is your guess?: "; // prompts a new user input
        cin >> numGuess;
        cout << endl;

        if (numGuess == randomNumber) {
            cout << "Great job! You guessed the magic number and passed the 2ND challenge. One more left!" << endl;
            break; // If user guess is correct, exit loop and continue game
        }

        if (numGuess > randomNumber) { // Tells the user if the guess is too high or low.
            cout << "Too high. ";
        } else {
            cout << "Too low. ";
        }

        if ((abs(numGuess - randomNumber) >= 10)) { // is the user guess 10+ from the magic number?
            cout << "Way off. ";
        } else if ((abs(numGuess - randomNumber) <= 5)) { // is the user guess within 5 of the magic number?
            cout << "You're close. ";
        }

        // tells the user the amount of guesses they have left
        cout << "Try again. You have (" << (4-wrongCount) << ") more tries" << endl;
    }

    if (wrongCount == 5) { // Was the loop exited because of the wrongCount? If so, game over.
        cout << "You lose!" << endl;
        exit(0); // Closes the program. Prizes are for winners.
    }

    cout << endl;
}



// Challenge 3:
void GreatSherifi::hipHopLyric(string wordGuess) {
    int difficulty; // a scale of 1-5 for the user to choose their desired difficulty. completely subjective
    int wrongCount = 0;

    cout << "For your last challenge, we'll take a magical journey through Hip-Hop. " << endl;
    cout << "Fill in the blank with the missing lyric of the hip-hop line below." << endl;
    cout << "Choose a difficulty between 1 and 5: ";
    cin >> difficulty;

    for (wrongCount = 0; wrongCount < 2; wrongCount++) { // gives the user (2) chances to get it right
        cout << lyrics[(difficulty - 1)] << endl; // lyrics correspond to the (difficulty-1)th index of the array
        cout << "What is the missing word? ";
        cin >> wordGuess;
        cout << endl;

        if (wordGuess == lyricsKey[difficulty - 1]) { // key corresponds to the (difficulty-1)th index of the array
            cout << "You did it! You are a hip hop magician!" << endl;
            break;
        }
    }

    if (wrongCount == 2) { // Was the loop exited because of the wrongCount? If so, game over.
        cout << "You are just another sucka MC. Sorry, you lose!" << endl;
        exit(0);
    }
}

void GreatSherifi::prizeWinner() {

    cout << "You've completed all the challenges! Now you will be presented with your prize: " << endl;

    cout << "     __      _" << endl;
    cout << "   o'')}____//" << endl;
    cout << "    `_/      )" << endl;
    cout << "    (_(_/-(_/" << endl;
    // ASCII Art via https://www.asciiart.eu/animals/dogs


    cout << "You win a " << prizeItem << "!" << endl;

}




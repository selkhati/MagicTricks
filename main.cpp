/* CSCI 261 Assignment A7: Magic Item
 * Author: Sherif Elkhatib
 * */

#include <iostream>
#include <string>
#include "GreatSherifi.h"
using namespace std;

int main() {

    string wordGuess;   // for user inputs that are of string data type
    int numGuess = 1;       // for user inputs that are of an int data type

    GreatSherifi magicMan; // declares a greatSherifi class type named maginMan.


    magicMan.riddleMeThis(); // Challenge #1, includes introduction function
    magicMan.guessTheNumber(numGuess); // Challenge #2
    magicMan.hipHopLyric(wordGuess); // Challenge #3
    magicMan.prizeWinner(); // Prize!


    return 0;
}

//Your "magic item" class should have at least two data members - DONE
// in addition to constructors and getter/setter functions, at least three other member functions. - DONE
// One of these other functions must be introduction()  that tells the user how to use the "magic item" to win a prize. - DONE

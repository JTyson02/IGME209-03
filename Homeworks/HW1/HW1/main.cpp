
#include <iostream>
using namespace std;
#include "hangman.h"


int main()
{

	char toBeGuessed[9];

	char correctGuesses[9];

	char allGuess[27];

	int failedGuesses = 0;

	cout << "Welcome to Hangman! Your word has 8 letters in it!" << endl;

	showGallows(failedGuesses);
	showSolved(toBeGuessed, allGuess);

	while (failedGuesses != 7)
	{

		char guess[1];

		cout << "Please enter your guess: ";
		cin >> guess;

		if (!strchr(toBeGuessed, guess[0])) {

			cout << "Sorry, that's not a correct guess!" << endl;
			failedGuesses++;

			strcat_s(allGuess, guess);
			
		}


	}




}
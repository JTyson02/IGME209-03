
#include <iostream>
using namespace std;
#include "hangman.h"


int main()
{

	bool win;

	char toBeGuessed[100] = "super";

	char correctGuess[100] = "_____";

	char allGuess[100] = "";

	int failedGuesses = 0;

	cout << "Welcome to Hangman! Your word has 8 letters in it!" << endl;

	while (failedGuesses != 8 && strcmp(toBeGuessed, correctGuess))
	{

		char guess[100];

		showGallows(failedGuesses);
		
		cout << "Word to guess: " << correctGuess << endl;
		
		cout << "Incorrect guesses : " << allGuess << endl;
		
		cout << "Please enter your guess: ";
		cin >> guess;

		if (strchr(allGuess, guess[0])) 
		{
			cout<< "\nSorry, you've already guessed that character!" << endl;
		}
		else {

			if (!strchr(toBeGuessed, guess[0])) {

			cout << "Sorry, that's not a correct guess!" << endl;
			failedGuesses++;

			strcat_s(allGuess, guess);

			}
			else
			{

				cout << "Correct!" << endl;

				for (int i = 0; i < 99; i++) {

					if (toBeGuessed[i] == guess[0])
					{

						correctGuess[i] = guess[0];

					}
					else {
						
					}

				}

			}
		}
		


	}

	if (failedGuesses < 8) {
		cout << "\n\nCongratulations! You figured out the word was " << toBeGuessed << endl;
	}
	else
	{
		cout << "\n\nThe word to guess was: " << toBeGuessed << endl;
	}

	




}
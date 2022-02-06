
#include <iostream>;
using namespace std;
#include "hangman.h";

void showGallows(int guessLimit) {
	
	switch (guessLimit) 
	{

	case 0:
		cout << "_______"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 1:
		cout << "_______"
			<< "\n|   |"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 2:
		cout << "_______"
			<< "\n|   |"
			<< "\n|   0"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 3:
		cout << "_______"
			<< "\n|   |"
			<< "\n|   0"
			<< "\n|   I"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 4:
		cout << "_______"
			<< "\n|   |"
			<< "\n|   0"
			<< "\n|  /I"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 5:
		cout << "_______"
			<< "\n|   |"
			<< "\n|   0"
			<< "\n|  /I\\"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 6:
		cout << "_______"
			<< "\n|   |"
			<< "\n|   0"
			<< "\n|  /I\\"
			<< "\n|   I"
			<< "\n|  /"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have " << 8 - guessLimit << " guesses left!"
			<< endl;
		break;

	case 7:
		cout << "_______"
			<< "\n|   |"
			<< "\n|   0"
			<< "\n|  /I\\"
			<< "\n|   I"
			<< "\n|  / \\"
			<< "\n|"
			<< "\n|"
			<< "\n\nYou have no guesses left!"
			<< endl;
		break;

	}

}

void showSolved(char word[], char guesses[]) 
{

	char correctGuesses[8] = "test";

	if (guesses) {

	}


}

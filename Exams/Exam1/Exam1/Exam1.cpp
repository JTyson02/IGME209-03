
//Created by Joshua Tyson, Section 3, Exam 1 practical

#include <iostream>
using namespace std;

// Calculates the average scores from the pointer of scores.
void AverageScore(float* scores, int numEntries) 
{
    //Sets the average score to 0
    float averageScore = 0;

    //For each entry:
    for (int i = 0; i < numEntries; i++)
    {
        //Adds the scores together
        averageScore += scores[i];

    }

    //Divides the scores by the number of entries
    averageScore /= numEntries;

    //Prints out the average score
    cout << "Average Score is " << averageScore << endl;

}

//Finds the highest score in a given data set
void HighScore(float* scores, int numEntries)
{
    //Sets highScore equal to the first score
    float highScore = scores[0];

    //For each entry:
    for (int i = 0; i < numEntries; i++)
    {
        //Checks if the score is greater than the currently saved highscore
        if (highScore <= scores[i])
        {
            //If it is, it becomes the new highscore
            highScore = scores[i];
        }
    }

    //Prints out the highscore
    cout << "High Score is " << highScore << endl;

}

//Finds the lowest score in a given data set
void LowScore(float* scores, int numEntries)
{

    //Sets the lowScore variable to the first score
    float lowScore = scores[0];

    //For each entry:
    for (int i = 0; i < numEntries; i++)
    {   
        //Checks to see if the entry is lower than the lowscore
        if (lowScore >= scores[i])
        {
            //If it is, it becomes the new lowscore
            lowScore = scores[i];
        }
    }

    //Prints out the new lowscore
    cout << "Low Score is " << lowScore << endl;

}


int main()
{
    //Variable for the number of scores the user wants to input
    int numEntries;

    //Prompts user for the number of scores to use
    
    do {
        cout << "Enter the number of scores to use: ";
        cin >> numEntries;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (numEntries <= 0 && numEntries / 1 == numEntries); //While the number of entries is less than or equal to 0
    //If the user inputs a letter, it reads in a 0 but that doesn't trip the while loop. why
    //I would love to know
        
    //Dynamically creates an array of pointers to hold the scores
    float* scores = new float[numEntries];

    //Fills the array with scores
    for (int i = 0; i < numEntries; i++)
    {
            //Prompts the user for a score
            do {
                cout << "Enter a score greater than 0: ";
                cin >> scores[i];
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (scores[i] <= 0 && scores[i] / 1 == scores[i]);
    }

    //Calculates and prints out the average score
    AverageScore(scores, numEntries);

    //Calculates and prints out the lowest score
    LowScore(scores, numEntries);

    //Calculates and prints out the highest score
    HighScore(scores, numEntries);

    //Cleans up the allocated memory
    delete[] scores;

}

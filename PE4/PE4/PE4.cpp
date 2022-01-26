// PE4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    char word[60] = "supercalifragilistic";

   std::cout << strlen(word);

   char otherWord[] = "expialidocious";

   strcat_s(word, otherWord);

   std::cout << "\n" << word;
   

   int numberOfI = 0;

   for (int i = 0; i < strlen(word); i++) {

       if (word[i] == 'i') {
           numberOfI++;
       }
   }

   std::cout << "\nThere are " << numberOfI << " I's in this word";

}

// Main file for Cheating Hangman
// Authors: Alex Kuang, Mason Cormany

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <list>
#include <string.h>
#include <string>
#include <ctime>

using namespace std;

class HangMan {

};

int main() {
    list <string> textList;
    string text;
    ifstream MyReadFile("words.txt");

    string word;
    int rand_index;
    int guesses = 7;

    // Reading in file
    while(getline (MyReadFile, text)) {
        textList.push_front(text);
    }
    MyReadFile.close();

    cout << "Welcome to Cheating Hangman!" << endl;
    
    // Choose a random work from the list
    srand(time(0));
    rand_index = rand() % textList.size();
    cout << rand_index << endl;
    list<string>::iterator it = textList.begin();
    advance(it, rand_index);
    word = *it;

    cout << "The word has " << word.size() << " letters in it." << endl;

    // Game loop
    while (guesses > 0) {
        string player_guess;

        cout << "Guess a letter!" << endl;
        cin >> player_guess;

        guesses -= 1;
    }

    return 0;
}
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
    public:
        // Function to split strings into seperate strings by space
        void split(string str, list <char>& l) {
            for (int i=0;i<str.size();i++){
                l.push_back(str[i]);
            }
        }

        // Creates an empty list
        void create_empty(){
            
        }

        
};

int main() {
    HangMan hangman;

    list <string> textList;
    list <char> letters;
    list <char> correct_letters;
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
    
    // Choose a random word from the list
    srand(time(0));
    rand_index = rand() % textList.size();
    list<string>::iterator it = textList.begin();
    advance(it, rand_index);
    word = *it;

    // Add each character of the word into a list
    hangman.split(word, letters);

    cout << "The word has " << word.size() << " letters in it." << endl;

    // Game loop
    while (guesses > 0) {

        char player_guess;
        
        cout << "Guess a letter!" << endl;
        cin >> player_guess;

        for (auto l:letters){
            if (player_guess!=l){
                guesses -= 1;
            }
            else {

            }
        }
    }

    cout << "You ran out of guesses :(, better luck next time!" << endl;

    return 0;
}
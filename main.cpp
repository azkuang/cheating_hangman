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

        void play(){
            
        }

        
};

int main() {
    HangMan hangman;

    list <string> textList;
    list <char> letters;
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
    int wordSize = word.size();
    string playingWord;
    list <char> letterGuesses;

    // Add each character of the word into a list
    hangman.split(word, letters);

    cout << "The word has " << word.size() << " letters in it." << endl;

    // Split the word into separate characters
    // hangman.split(word, letters);

    // for (auto w:letters){
    //     cout<<"hi"<<endl;
    // }

    // Game loop
    while (guesses > 0) {

        string player_guess;

        cout << "Guess a letter!" << endl;
        cin >> player_guess;

        guesses -= 1;
    }

    cout << "You ran out of guesses :(, better luck next time!" << endl;

    for(int j = 0; j < wordSize; j++) {
        playingWord += '_';
    }

    cout << 'Your Word: ' << playingWord << endl;

    // Game loop
    while (guesses > 0) {
        char player_guess;

        cout << "Guess a letter!" << endl;
        cin >> player_guess;

        guesses -= 1;

        list <string> cheatingList;

        bool guessRight = false;
        for(char p : word) {
            if(p == (player_guess)){
                guessRight = true;
            }
        }

        if(guessRight == true) {
            //Makes list of all possible words to cheat with
            for(int x = 0; x < textList.size(); x++) {

                //Goes thru the list for if statement
                list<string>::iterator it = textList.begin();
                advance(it, 1);
                string wordInList = *it;

                //checks if the word is the same size and has the same of already guessed letters
                if(wordInList.size() == word.size()) {
                    bool stopper = false;
                    for(int y = 0; y < word.size(); y++) {
                        if(wordInList[y] != word[y] && word[y] != '_') {
                            stopper = true;
                        }
                    }
                    if(stopper == false) {
                        cheatingList.push_front(word);
                    }
                }
            }
            if(cheatingList.empty() == false) {
                cout << 'Hmm it seems you were wrong. Try again' << endl;
            }
            else {
                for(int z = 0; z < playingWord.size();z++) {
                    if(player_guess == word[z]) {
                        playingWord = player_guess;
                    }
                }
            }
            if(playingWord == word) {
                cout << 'You win....' << endl;
                break;
            }
            letterGuesses.push_front(player_guess);
        }
        else {
            cout << 'Wrong, try again' << endl;
            letterGuesses.push_front(player_guess);
        }
    }
    return 0;
}
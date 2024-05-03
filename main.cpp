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

        // Method to turn a character into a string
        string ToStr( char c ) {
            return string( 1, c );
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
    int wordSize = word.size();
    string playingWord;
    list <char> letterGuesses;

    // Add each character of the word into a list
    hangman.split(word, letters);

    // Display the word for now (DELETE LATER)
    cout<<word<<endl;

    cout << "The word has " << word.size() << " letters in it." << endl;

    for(int j = 0; j < wordSize; j++) {
        playingWord += '_';
    }

    cout << "Your Word: " << playingWord << endl;

    // Game loop
    while (guesses > 0) {
        char player_guess;

        cout << "Guess a letter!" << endl;
        cin >> player_guess;

        list <string> cheatingList;

        bool guessRight = false;
        int index_correct_word = 0;
        for(char p : word) {
            if(p == (player_guess)){
                guessRight = true;
                break;
            }
            index_correct_word++;
        }

        if (guessRight==true){
            list<char>::iterator it = letters.begin();
            advance(it, index_correct_word);
            char correct_letter = *it;
            playingWord.replace(index_correct_word, 1, hangman.ToStr(correct_letter));
        } 
        else {
            guesses--;
        }

        cout << playingWord << endl;

        if (playingWord == word){
            cout << "You win!" << endl;
            break;
        }

        // if(guessRight == true) {
        //     //Makes list of all possible words to cheat with
        //     for(int x = 0; x < textList.size(); x++) {

        //         //Goes through the list for if statement
        //         list<string>::iterator it = textList.begin();
        //         advance(it, 1);
        //         string wordInList = *it;

        //         //checks if the word is the same size and has the same of already guessed letters
        //         if(wordInList.size() == word.size()) {
        //             bool stopper = false;
        //             for(int y = 0; y < word.size(); y++) {
        //                 if(wordInList[y] != word[y] && word[y] != '_') {
        //                     stopper = true;
        //                 }
        //             }
        //             if(stopper == false) {
        //                 cheatingList.push_front(word);
        //             }
        //         }
        //     }
        //     if(cheatingList.empty() == false) {
        //         cout << "Hmm it seems you were wrong. Try again" << endl;
        //     }

        //     else {
        //         for(int z = 0; z < playingWord.size();z++) {
        //             if(player_guess == word[z]) {
        //                 playingWord = player_guess;
        //             }
        //         }
        //     }

        //     if(playingWord == word) {
        //         cout << "You win...." << endl;
        //         break;
        //     }
        //     letterGuesses.push_front(player_guess);
        // }
        // else {
        //     cout << "Wrong, try again" << endl;
        //     letterGuesses.push_front(player_guess);
        // }
    }

    if (guesses <= 0) {
        cout << "You ran out of guesses :(, better luck next time!" << endl;
    }

    return 0;
}
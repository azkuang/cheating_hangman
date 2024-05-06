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
#include <set>

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

        // Method to update the display word
        bool updateWord(string& playingWord, string& word, char guess){
            bool correctGuess = false;
            for (int i=0;i<word.length();i++){
                if (word[i]==guess){
                    playingWord[i]=guess;
                    cout<<"Correct Guess!"<<endl;
                    correctGuess = true;
                }
            }
            return correctGuess;
        }

        // Method to create the cheating list
        list <string> cheatingWords(list<string>& words, string& playingWord, set<char>& lettersGuessed){
            list <string> cheatingWords;
            bool match = false;
            for (const string& w: words){
                if (w.length() != playingWord.length()){
                    continue;
                }
                bool match = true;
                for (int i=0;i<w.length();i++){
                    if (playingWord[i]!='_' && playingWord[i]!=w[i]){
                        match = false;
                        break;
                    }
                    // Ensures letters already guessed can't be in the cheating list
                    if (lettersGuessed.find(w[i])!=lettersGuessed.end()){
                        match = false;
                        break;
                    }
                }
                if (match){
                    cheatingWords.push_back(w);
                }
            }
            return cheatingWords;
        } 

        // Method to pick a random word from the cheating list
        string pickCheatWord(list<string>& cheatingWords){
            int index = rand() % cheatingWords.size();
            list<string>::iterator it = cheatingWords.begin();
            advance(it, index);
            string cheatWord = *it;
            return cheatWord;
        }
};

int main() {
    // Initialize hangman class
    HangMan hangman;

    // variables and data structures
    list <string> textList;
    list <char> letters;
    list <char> correct_letters;
    string text;
    ifstream MyReadFile("dictionary.txt");
    string word;
    int rand_index;

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

    // Create a set to hold player guesses
    set <char> guessedLetters;

    // Add each character of the word into a list
    hangman.split(word, letters);

    // Display the word
    cout<<"Word to guess: "<<word<<endl;

    cout << "The word has " << word.size() << " letters in it." << endl;

    // Creating the string that has _ for the letters in the word
    for(int j = 0; j < wordSize; j++) {
        playingWord += '_';
    }

    cout << "Your Word: " << playingWord << endl;

    // Game loop
    while (true) {
        char player_guess;

        // Ask user input for a letter
        cout << "Guess a letter!" << endl;
        cin >> player_guess;

        // List to hold all possible words to switch with the current word
        list <string> cheatingList;

        // Condition to check if a letter as already been guessed using a set
        if (guessedLetters.find(player_guess)!=guessedLetters.end()){
            cout<<"You have already guessed "<<player_guess<<" try again."<<endl;
        } else {
            // Fill in the playing word and cheat :)
            if (hangman.updateWord(playingWord, word, player_guess)){
                cheatingList = hangman.cheatingWords(textList, playingWord, guessedLetters);
                if (cheatingList.size() > 1){
                    word = hangman.pickCheatWord(cheatingList);
                    cout<<"I cheated >:)"<<endl;
                    cout<<"New word after cheating: "<<word<<endl;
                }
            }
        }

        guessedLetters.insert(player_guess);

        cout << playingWord << endl;

        // Win condition
        if (playingWord == word){
            cout << "You win!" << endl;
            break;
        }
    }

    return 0;
}